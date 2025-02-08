// Fill out your copyright notice in the Description page of Project Settings.


#include "WindowHUD.h"
#include "SChatWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AWindowHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport)
	{
		ChatWidget = SNew(SChatWidget)
			.OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(
			SAssignNew(ChatWidgetContainer, SWeakWidget)
			.PossiblyNullContent(ChatWidget.ToSharedRef())
		);
		
	}

}
