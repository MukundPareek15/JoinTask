// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FMinesButtonModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	

protected:

	TSharedPtr<class SChatWidget> ChatWidget;
	TWeakPtr<class SWindow> ChatWidgetContainer;
	TSubclassOf<class AHUD> HUDClass;


private:
	void RegisterMenus();
	TSharedPtr<class FUICommandList> PluginCommands;
};
