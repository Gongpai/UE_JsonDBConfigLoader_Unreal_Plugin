// Copyright Epic Games, Inc. All Rights Reserved.

#include "JsonDBConfigLoaderEditorCommands.h"

#define LOCTEXT_NAMESPACE "FJsonDBConfigLoaderModule"

void FJsonDBConfigLoaderEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "JsonDBConfigLoader", "Bring up JsonDBConfigLoader window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
