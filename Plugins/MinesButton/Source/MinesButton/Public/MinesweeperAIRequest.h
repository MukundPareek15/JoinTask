#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "MinesweeperAIRequest.generated.h"

DECLARE_DELEGATE_OneParam(FOnMinesweeperResponseReceived, FString);

UCLASS()
class MINESBUTTON_API UMinesweeperAIRequest : public UObject
{
	GENERATED_BODY()

public:
	FOnMinesweeperResponseReceived OnResponseReceived;

	void SendAIRequest(FString UserQuery);

private:
	void OnAIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
