// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Widgets/SCompoundWidget.h"
#include "HttpModule.h"
#include "MinesweeperAIRequest.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Async/AsyncWork.h"

/**
 * Chat UI Widget that interacts with AI to generate Minesweeper grids.
 */ 
class MINESBUTTON_API SChatWidget : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SChatWidget)
		{
		}
		SLATE_ARGUMENT(TWeakObjectPtr<class AWindowHUD>, OwningHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Generates a Minesweeper board from the AI response */
	FReply GenerateMinesweeperBoard();
private:
	/** Input text box for user queries */
	TSharedPtr<class SEditableTextBox> InputTextBox;

	/** Displays AI-generated text */
	TSharedPtr<class STextBlock> ResponseText;

	/** Button to play Minesweeper */
	TSharedPtr<class SButton> PlayButton;

	/** Container for the Minesweeper grid */
	TSharedPtr<SVerticalBox> GridBox;

	/** Handles sending requests to AI */
	TObjectPtr<UMinesweeperAIRequest> AIRequest;

	/** Stores the last generated Minesweeper grid */
	FString LastGeneratedGrid;

	/** Called when the user submits a chat query */
	void OnChatSubmitted(const FText& Text, ETextCommit::Type CommitType);

	/** Handles the response from AI */
	void HandleAIResponse(FString AIResponse);
	;
	
};
