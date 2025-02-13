// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/**
 * MinesButtonModule handles the Minesweeper AI Assistant plugin functionality,
 * including UI initialization, command execution, and menu registration.
 */

class FToolBarBuilder;
class FMenuBuilder;

class FMinesButtonModule : public IModuleInterface
{
public:

	/** Initializes the plugin module */
	virtual void StartupModule() override;

	/** Cleans up the plugin module before unloading */
	virtual void ShutdownModule() override;

	/** Handles the event when the plugin button is clicked */
	void PluginButtonClicked();
	

protected:

	/** Chat widget for the AI assistant */
	TSharedPtr<class SChatWidget> ChatWidget;

	/** Weak pointer to the chat window */
	TWeakPtr<class SWindow> ChatWidgetContainer;

	/** HUD class reference */
	TSubclassOf<class AHUD> HUDClass;


private:
	/** Registers plugin-related menus */
	void RegisterMenus();

	/** Command list for plugin actions */
	TSharedPtr<class FUICommandList> PluginCommands;
};
