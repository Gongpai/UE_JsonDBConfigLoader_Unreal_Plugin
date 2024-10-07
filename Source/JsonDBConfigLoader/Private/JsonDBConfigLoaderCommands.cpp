// Copyright Epic Games, Inc. All Rights Reserved.

#include "JsonDBConfigLoaderCommands.h"

#define LOCTEXT_NAMESPACE "FJsonDBConfigLoaderModule"

void FJsonDBConfigLoaderCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "JsonDBConfigLoader", "Bring up JsonDBConfigLoader window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
