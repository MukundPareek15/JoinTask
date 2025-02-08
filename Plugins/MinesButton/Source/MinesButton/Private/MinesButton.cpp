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
	if (!ChatWidget.IsValid())  // Prevent multiple windows
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating a new chat window..."));

		ChatWidget = SNew(SChatWidget).OwningHUD(nullptr);

		TSharedRef<SWindow> ChatWindow = SNew(SWindow)
			.Title(FText::FromString("Chat Window"))
			.ClientSize(FVector2D(500, 400))
			/*.SupportsMaximize(false)
			.SupportsMinimize(false)*/
			[
				ChatWidget.ToSharedRef()
			];

		ChatWidgetContainer = ChatWindow;  // Store the reference
		FSlateApplication::Get().AddWindow(ChatWindow);
	}
	else
	{
		// Correctly handle TWeakPtr by converting it to TSharedPtr
		if (TSharedPtr<SWindow> WindowPtr = ChatWidgetContainer.Pin())
		{
			UE_LOG(LogTemp, Warning, TEXT("Chat window already exists. Bringing to front."));
			WindowPtr->BringToFront();  // ✅ Now it's a valid TSharedPtr
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ChatWidgetContainer was unexpectedly invalid. Resetting..."));
			ChatWidget.Reset();
			PluginButtonClicked();  // Try again
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