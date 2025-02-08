// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MinesButtonStyle.h"

class FMinesButtonCommands : public TCommands<FMinesButtonCommands>
{
public:

	FMinesButtonCommands()
		: TCommands<FMinesButtonCommands>(TEXT("MinesButton"), NSLOCTEXT("Contexts", "MinesButton", "MinesButton Plugin"), NAME_None, FMinesButtonStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
