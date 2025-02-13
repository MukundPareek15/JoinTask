#include "SChatWidget.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "HttpModule.h"

void SChatWidget::Construct(const FArguments& InArgs)
{
	AIRequest = NewObject<UMinesweeperAIRequest>();
	AIRequest->OnResponseReceived.BindRaw(this, &SChatWidget::HandleAIResponse);

	SAssignNew(GridBox, SVerticalBox);

	ChildSlot
		[
			SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(STextBlock).Text(FText::FromString("Ask AI for a Minesweeper Grid"))
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SAssignNew(InputTextBox, SEditableTextBox)
						.HintText(FText::FromString("Enter your request..."))
						.OnTextCommitted(this, &SChatWidget::OnChatSubmitted)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SAssignNew(ResponseText, STextBlock).Text(FText::FromString("AI Response will appear here"))
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SAssignNew(PlayButton, SButton)
						.Text(FText::FromString("Play"))
						.OnClicked(this, &SChatWidget::GenerateMinesweeperBoard)
						.IsEnabled(false)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					GridBox.ToSharedRef()
				]
		];
}

void SChatWidget::OnChatSubmitted(const FText& Text, ETextCommit::Type CommitType)
{
	if (CommitType == ETextCommit::OnEnter)
	{
		FString UserInput = Text.ToString();
		AIRequest->SendAIRequest(UserInput);
	}
}

void SChatWidget::HandleAIResponse(FString AIResponse)
{
	
	UE_LOG(LogTemp, Log, TEXT("Raw AI Response:\n%s"), *AIResponse);

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(AIResponse);

	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		// Extract message content from AI response
		TArray<TSharedPtr<FJsonValue>> Choices = JsonObject->GetArrayField("choices");
		if (Choices.Num() > 0 && Choices[0]->AsObject()->HasField("message"))
		{
			TSharedPtr<FJsonObject> MessageObject = Choices[0]->AsObject()->GetObjectField("message");

			if (MessageObject->HasField("content"))
			{
				FString ResponseTextStr = MessageObject->GetStringField("content");

				int32 GridStartIndex = ResponseTextStr.Find(TEXT("\n"));
				if (GridStartIndex != INDEX_NONE)
				{
					LastGeneratedGrid = ResponseTextStr.Mid(GridStartIndex).TrimStartAndEnd();
				}
				else
				{
					LastGeneratedGrid = ResponseTextStr; // Fallback if no newline
				}

				// Remove extra AI explanations
				LastGeneratedGrid = LastGeneratedGrid.Replace(TEXT("In this grid, \"X\" represents the bomb."), TEXT(""), ESearchCase::IgnoreCase);
				LastGeneratedGrid = LastGeneratedGrid.Replace(TEXT("The other cells are empty."), TEXT(""), ESearchCase::IgnoreCase);

				// Set the cleaned text in the UI
				ResponseText->SetText(FText::FromString(LastGeneratedGrid));
				PlayButton->SetEnabled(true);

			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Invalid AI response format: Missing 'message' or 'content'"));
			ResponseText->SetText(FText::FromString("Error: Invalid AI response format"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to parse AI response: %s"), *AIResponse);
		ResponseText->SetText(FText::FromString("Error: Invalid AI response"));
	}
}

FReply SChatWidget::GenerateMinesweeperBoard()
{
	UE_LOG(LogTemp, Log, TEXT("Generating Minesweeper Board: \n%s"), *LastGeneratedGrid);
	

	// Convert AI text into a 2D Minesweeper grid, Split AI response into Rows
	TArray<FString> Rows;
	LastGeneratedGrid.ParseIntoArray(Rows, TEXT("\n"), true);

	// Clear old grid (if any)
	GridBox->ClearChildren();

	for (const FString& Row : Rows)
	{
		if (Row.IsEmpty()) continue;

		TSharedPtr<SHorizontalBox> RowBox;// = SNew(SHorizontalBox);
		SAssignNew(RowBox, SHorizontalBox);

		TArray<FString> Cells;
		Row.ParseIntoArray(Cells, TEXT(" "), true);// Split by space (ignores multiple spaces)

		for (const FString& Cell : Cells)
		{

			FString DisplayText = (Cell == "X") ? "X" : Cell; // Bomb 

			RowBox->AddSlot()
				.AutoWidth()
				[
					SNew(SButton)
						.Text(FText::FromString(DisplayText))
				];
		}

		GridBox->AddSlot()
			.AutoHeight()
			[
				RowBox.ToSharedRef()
			];
	}

	return FReply::Handled();
}
