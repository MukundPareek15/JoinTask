// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WindowHUD.generated.h"

/**
 * 
 */
UCLASS()
class MINESBUTTON_API AWindowHUD : public AHUD
{
	GENERATED_BODY()

protected:

	TSharedPtr<class SChatWidget> ChatWidget;
	TWeakPtr<class SWidget> ChatWidgetContainer;

	virtual void BeginPlay() override;
	
};
