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
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMinesButtonStyle::Initialize();
	FMinesButtonStyle::ReloadTextures();

	FMinesButtonCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMinesButtonCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FMinesButtonModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMinesButtonModule::RegisterMenus));
}

void FMinesButtonModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMinesButtonStyle::Shutdown();

	FMinesButtonCommands::Unregister();
}

void FMinesButtonModule::PluginButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Plugin Button Clicked!"));

	// ✅ Check if the chat widget is valid
	if (!ChatWidget.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating a new Minesweeper AI Chat window..."));

		// ✅ Create a new Minesweeper chat widget
		ChatWidget = SNew(SChatWidget);// .OwningHUD(nullptr);

		// ✅ Create a new window for the chat interface
		TSharedRef<SWindow> ChatWindow = SNew(SWindow)
			.Title(FText::FromString("Minesweeper AI Assistant"))
			.ClientSize(FVector2D(600, 450))  // Slightly larger for AI-generated grids
			[
				ChatWidget.ToSharedRef()
			];

		ChatWidgetContainer = ChatWindow;// Store a reference to the window
				
		FSlateApplication::Get().AddWindow(ChatWindow);// Add the window to Unreal's UI

		UE_LOG(LogTemp, Warning, TEXT("Chat window successfully created."));
	}
	else
	{
		// ✅ Check if the chat window reference is still valid
		if (TSharedPtr<SWindow> WindowPtr = ChatWidgetContainer.Pin())
		{
			UE_LOG(LogTemp, Warning, TEXT("Chat window already exists. Bringing it to front."));
			WindowPtr->BringToFront();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ChatWidgetContainer was unexpectedly invalid. Resetting..."));

			// ✅ Reset widget and try again
			ChatWidget.Reset();
			ChatWidgetContainer.Reset();
			PluginButtonClicked(); // 🔁 Retry opening the chat window
		}
	}
}



void FMinesButtonModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMinesButtonCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMinesButtonCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}

	HUDClass = AWindowHUD::StaticClass();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMinesButtonModule, MinesButton)