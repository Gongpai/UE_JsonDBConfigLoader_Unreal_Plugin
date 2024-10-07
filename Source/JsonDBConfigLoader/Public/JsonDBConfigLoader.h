// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ButtonInfo.h"
#include "JsonDBConfigLoaderManager.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Templates/SharedPointer.h"
#include "IPropertyTypeCustomization.h"
#include "PropertyCustomizationHelpers.h"
#include "PropertyEditing.h"

class FToolBarBuilder;
class FMenuBuilder;

DECLARE_DELEGATE_OneParam(FClickAction, FString*)

class FJsonDBConfigLoaderModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();
	
private:
	void RegisterMenus();
	void OnButtonDelete(FString* FileName);

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);
	void AutoShowEmptyJsonText();
	FReply OnButtonClick();
	FReply OnButtonSave();
	FReply OnButtonLoad();
	FReply OnButtonAddNewJson();
	void OnAddJson();
	void OnDataTableChanged(const FAssetData& NewAssetData);
	FReply OnButtonCreateNewJson();
	FReply OnButtonClearList();
	FReply OnButtonClearConfig();
	void ClearConfig();
	void OnCreateJson(FDatabaseInfo DatabaseInfo);
	UJsonDBConfigLoaderManager* JsonDBCLManager;
	TMap<FString, TSharedRef<FButtonInfo>> JsonButtonLists;
	TSharedPtr<SObjectPropertyEntryBox> CreateDataTableEntryBox();
	void ShowNotification(FText Message, FName MessageLog);
	void AddJsonFileToDatabaseList(TArray<FString> JsonFiles, FDatabaseInfo DatabaseInfo, bool isSave);
	void AddJsonFileInList(FString FileName);
	void OnSetCurrentJson(FString* FileName);
	void OnLoadJson();
	void OnSaveJson();
	
	FFileInfo* CurrentFileInfo = nullptr;
	FDatabaseInfo* CurrentDatabaseInfo = nullptr;
	FLinearColor SelectColor = FLinearColor(0.00304, 0.31896, 0.14444, 1);
	FLinearColor HideColor = FLinearColor(0, 0, 0, 0);
	UDataTable* CurrentDataTable;
	FString CurrentDataTablePath;
	
	TSharedPtr<SDockTab> DockTab;
	TSharedRef<FButtonInfo> JsonFileButton(FString FileName, FClickAction SelectAction, FClickAction DeleteAction);
	bool ShowMessageDialog(FText Message);
	void ShowMessageDialogWithAction(FText Message, FOnClicked ConfirmAction, FOnClicked CancelAction);
	TSharedPtr<SBox> TextJsonEmpty;
	TSharedPtr<SScrollBox> JsonScrollListBox;
	TSharedPtr<STextBlock> CurrentPathText;
	TSharedPtr<SEditableTextBox> HostnameInputText;
	TSharedPtr<SEditableTextBox> UsernameInputText;
	TSharedPtr<SEditableTextBox> PasswordInputText;
	TSharedPtr<SEditableTextBox> PortInputText;
	TSharedPtr<SEditableTextBox> DatabaseInputText;
	TSharedPtr<SBox> DataTableBox;
	TSharedPtr<SObjectPropertyEntryBox> DataTableEntryBox;

private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
