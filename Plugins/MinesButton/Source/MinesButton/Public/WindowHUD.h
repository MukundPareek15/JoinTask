// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WindowHUD.generated.h"

/**
 * A custom HUD class that integrates a Slate-based chat window into the game viewport.
 */
UCLASS()
class MINESBUTTON_API AWindowHUD : public AHUD
{
	GENERATED_BODY()

protected:

	/** Reference to the Slate Chat Widget */
	TSharedPtr<class SChatWidget> ChatWidget;

	/** Holds a reference to the widget added to the viewport */
	TWeakPtr<class SWidget> ChatWidgetContainer;

	/** Called when the game starts */
	virtual void BeginPlay() override;
	
};
