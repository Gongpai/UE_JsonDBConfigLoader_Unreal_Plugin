// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "JsonDBConfigLoaderEditorStyle.h"

class FJsonDBConfigLoaderEditorCommands : public TCommands<FJsonDBConfigLoaderEditorCommands>
{
public:

	FJsonDBConfigLoaderEditorCommands()
		: TCommands<FJsonDBConfigLoaderEditorCommands>(TEXT("JsonDBConfigLoader"), NSLOCTEXT("Contexts", "JsonDBConfigLoader", "JsonDBConfigLoader Plugin"), NAME_None, FJsonDBConfigLoaderEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};