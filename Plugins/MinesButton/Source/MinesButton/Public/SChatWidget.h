// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Widgets/SCompoundWidget.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
 
class MINESBUTTON_API SChatWidget : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SChatWidget)
		{
		}
		SLATE_ARGUMENT(TWeakObjectPtr<class AWindowHUD>, OwningHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void OnChatSubmitted(const FText& Text, ETextCommit::Type CommitType);

	TWeakObjectPtr<class AWindowHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };

	void SendAIRequest(FString Query); // Sends a request to AI
	void OnAIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful); // Handles AI response

private:
	void ProcessAIGridResponse(FString AIResponse);
};
