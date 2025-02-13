// Copyright Epic Games, Inc. All Rights Reserved.

#include "MinesButton.h"
#include "MinesButtonStyle.h"
#include "MinesButtonCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "WindowHUD.h"
#include "SChatWidget.h"

static const FName MinesButtonTabName("MinesButton");

#define LOCTEXT_NAMESPACE "FMinesButtonModule"

void FMinesButtonModule::StartupModule()
{
	// Initialize UI styles and commands	
	FMinesButtonStyle::Initialize();
	FMinesButtonStyle::ReloadTextures();
	FMinesButtonCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	if (PluginCommands.IsValid())
	{
		PluginCommands->MapAction(
			FMinesButtonCommands::Get().PluginAction,
			FExecuteAction::CreateRaw(this, &FMinesButtonModule::PluginButtonClicked),
			FCanExecuteAction());
	}

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMinesButtonModule::RegisterMenus));
}

void FMinesButtonModule::ShutdownModule()
{
	// Cleanup before shutdown
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
	FMinesButtonStyle::Shutdown();
	FMinesButtonCommands::Unregister();
}

void FMinesButtonModule::PluginButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Plugin Button Clicked!"));

	// Check if the chat widget is valid, Create New one if not
	if (!ChatWidget.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating a new Minesweeper AI Chat window..."));
		SAssignNew(ChatWidget, SChatWidget);

		if (!ChatWidget.IsValid())
		{
			UE_LOG(LogTemp, Error, TEXT("ChatWidget creation failed!"));
			return;
		}

		// Create a new window for the chat interface
		TSharedRef<SWindow> ChatWindow = SNew(SWindow)
			.Title(FText::FromString("Minesweeper AI Assistant"))
			.ClientSize(FVector2D(600, 450))  // Slightly larger for AI-generated grids
			[
				ChatWidget.ToSharedRef()
			];

		// Store a reference to the window
		ChatWidgetContainer = ChatWindow;

		// Add the window to Unreal's UI
		FSlateApplication::Get().AddWindow(ChatWindow);
		UE_LOG(LogTemp, Warning, TEXT("Chat window successfully created."));
	}
	else
	{
		// If the chat widget already exists, bring the window to the front
		TSharedPtr<SWindow> WindowPtr = ChatWidgetContainer.Pin();
		if (WindowPtr.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Chat window already exists. Bringing it to front."));
			WindowPtr->BringToFront();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ChatWidgetContainer was unexpectedly invalid. Resetting..."));

			// Reset widget and try again
			ChatWidget.Reset();
			ChatWidgetContainer.Reset();
			PluginButtonClicked();
		}
	}
}


void FMinesButtonModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	{// Register a menu extension for the window menu, Add a menu entry under "Window" -> "Window Layout"
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMinesButtonCommands::Get().PluginAction, PluginCommands);
		}
	}

	{// Add a button to the "PlayToolBar"
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMinesButtonCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
	// Store a reference to the HUD class
	HUDClass = AWindowHUD::StaticClass();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMinesButtonModule, MinesButton)