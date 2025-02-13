#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonUtilities.h"
#include "MinesweeperAIRequest.generated.h"

DECLARE_DELEGATE_OneParam(FOnMinesweeperResponseReceived, FString);

/**
 * Handles sending requests to the Mistral AI API and processing responses.
 */
UCLASS()
class MINESBUTTON_API UMinesweeperAIRequest : public UObject
{
	GENERATED_BODY()

public:
	/** Delegate triggered when an AI response is received. */
	FOnMinesweeperResponseReceived OnResponseReceived;

	/** Sends an AI request with the given user query. */
	void SendAIRequest(FString UserQuery);

private:
	/** Handles the AI response when received. */
	void OnAIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
