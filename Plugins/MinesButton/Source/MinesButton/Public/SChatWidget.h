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
 
class MINESBUTTON_API SChatWidget : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SChatWidget)
		{
		}
		SLATE_ARGUMENT(TWeakObjectPtr<class AWindowHUD>, OwningHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply GenerateMinesweeperBoard();
private:
	TSharedPtr<class SEditableTextBox> InputTextBox;
	TSharedPtr<class STextBlock> ResponseText;
	TSharedPtr<class SButton> PlayButton;
	TSharedPtr<SVerticalBox> GridBox;


	TObjectPtr<UMinesweeperAIRequest> AIRequest;
	FString LastGeneratedGrid;

	void OnChatSubmitted(const FText& Text, ETextCommit::Type CommitType);
	void HandleAIResponse(FString AIResponse);
	;
	
};
