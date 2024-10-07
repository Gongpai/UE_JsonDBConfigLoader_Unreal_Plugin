// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "JsonDBConfigLoaderStyle.h"

class FJsonDBConfigLoaderCommands : public TCommands<FJsonDBConfigLoaderCommands>
{
public:

	FJsonDBConfigLoaderCommands()
		: TCommands<FJsonDBConfigLoaderCommands>(TEXT("JsonDBConfigLoader"), NSLOCTEXT("Contexts", "JsonDBConfigLoader", "JsonDBConfigLoader Plugin"), NAME_None, FJsonDBConfigLoaderStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};