// Fill out your copyright notice in the Description page of Project Settings.


#include "SChatWidget.h"

#define LOCTEXT_NAMESPACE "SChatWidget"

void SChatWidget::Construct(const FArguments& InArgs)
{
	const FMargin ContentPadding = FMargin(500.0f, 300.0f);

	ChildSlot
		/*[
			SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SImage)
						.ColorAndOpacity(FColor::Black)
				]
				+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(ContentPadding)
				[
					SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
								.Text(FText::FromString("Chat Box"))
						]
				]
		];*/
		[
			SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(STextBlock).Text(FText::FromString("Chat Box"))
				]
				+ SVerticalBox::Slot()
				[
					SNew(SEditableTextBox)
						.OnTextCommitted(this, &SChatWidget::OnChatSubmitted)
				]
		];
}

void SChatWidget::OnChatSubmitted(const FText& Text, ETextCommit::Type CommitType)
{
	if (CommitType == ETextCommit::OnEnter)
	{
		FString UserInput = Text.ToString();
		UE_LOG(LogTemp, Log, TEXT("User Input: %s"), *UserInput);

		// Send input to AI
		SendAIRequest(UserInput);
	}
}

void SChatWidget::SendAIRequest(FString Query)
{
	// Get HTTP module
	FHttpModule* Http = &FHttpModule::Get();
	if (!Http) return;

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	Request->SetURL("https://api.openai.com/v1/chat/completions"); // Change to your API endpoint
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetHeader("Authorization", "Bearer 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"); // API key

	// Create JSON request body
	FString RequestBody = FString::Printf(TEXT(R"({"model": "gpt-4o-mini", "prompt": "%s", "max_tokens": 100})"), *Query);
	Request->SetContentAsString(RequestBody);

	// Bind response function
	Request->OnProcessRequestComplete().BindRaw(this, &SChatWidget::OnAIResponse);
	Request->ProcessRequest();
}

void SChatWidget::OnAIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response.IsValid())
	{
		FString AIResponse = Response->GetContentAsString();
		UE_LOG(LogTemp, Log, TEXT("AI Response: %s"), *AIResponse);

		// Process the AI response into a Minesweeper grid
		ProcessAIGridResponse(AIResponse);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get AI response!"));
	}
}

void SChatWidget::ProcessAIGridResponse(FString AIResponse)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(AIResponse);

	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString GridString;
		if (JsonObject->TryGetStringField("choices", GridString))
		{
			UE_LOG(LogTemp, Log, TEXT("AI Grid Response: %s"), *GridString);

			// Convert AI text to actual grid
			// Example AI Response: "0 1 0\n1 X 1\n0 1 0"
			TArray<TArray<int32>> Grid;
			TArray<FString> Rows;
			GridString.ParseIntoArray(Rows, TEXT("\n"));

			for (FString& Row : Rows)
			{
				TArray<FString> Cells;
				Row.ParseIntoArray(Cells, TEXT(" "));

				TArray<int32> GridRow;
				for (FString& Cell : Cells)
				{
					GridRow.Add(Cell == "X" ? -1 : FCString::Atoi(*Cell)); // -1 means mine
				}
				Grid.Add(GridRow);
			}

			// TODO: Use this `Grid` in your Minesweeper logic!
		}
	}
}

#undef LOCTEXT_NAMESPACE