// Copyright Epic Games, Inc. All Rights Reserved.

#include "MinesButtonCommands.h"

#define LOCTEXT_NAMESPACE "FMinesButtonModule"

void FMinesButtonCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "MinesButton", "Execute MinesButton action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
