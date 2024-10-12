// Copyright Epic Games, Inc. All Rights Reserved.

#include "JsonDBConfigLoaderEditor.h"
#include "JsonDBConfigLoader/Public/JsonDBConfigDataTable.h"
#include "JsonDBConfigLoaderEditorStyle.h"
#include "JsonDBConfigLoaderEditorCommands.h"
#include "JsonDBConfigLoaderEditorManager.h"
#include "JsonDBConfigLoader.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "Chaos/AABB.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"
#include "EditorStyleSet.h"
#include "PropertyCustomizationHelpers.h"

static const FName JsonDBConfigLoaderTabName("JsonDBConfigLoader");

#define LOCTEXT_NAMESPACE "FJsonDBConfigLoaderModule"

void FJsonDBConfigLoaderEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FJsonDBConfigLoaderEditorStyle::Initialize();
	FJsonDBConfigLoaderEditorStyle::ReloadTextures();
	
	//Setup Other
	JsonDBCLManager = UJsonDBConfigLoaderEditorManager::GetInstance();

	FJsonDBConfigLoaderEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FJsonDBConfigLoaderEditorCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FJsonDBConfigLoaderEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FJsonDBConfigLoaderEditorModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(JsonDBConfigLoaderTabName, FOnSpawnTab::CreateRaw(this, &FJsonDBConfigLoaderEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FJsonDBConfigLoaderTabTitle", "JsonDBConfigLoader"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FJsonDBConfigLoaderEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FJsonDBConfigLoaderEditorStyle::Shutdown();

	FJsonDBConfigLoaderEditorCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(JsonDBConfigLoaderTabName);
}

TSharedRef<SDockTab> FJsonDBConfigLoaderEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FJsonDBConfigLoaderModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("JsonDBConfigLoader.cpp"))
		);

	if(JsonDBCLManager->FileNames.Num() <= 0 || !JsonScrollListBox.IsValid())
	{
		 TSharedPtr<STextBlock> TextEmpty = SNew(STextBlock)
			.Text(FText::FromString("Empty Json List."))
			.Justification(ETextJustify::Center);
	
		TextJsonEmpty = SNew(SBox)
		.HeightOverride(35)
		[
			TextEmpty.ToSharedRef()
		];
	
		JsonScrollListBox = SNew(SScrollBox)
		+ SScrollBox::Slot()
		.VAlign(VAlign_Top)
		[
			TextJsonEmpty.ToSharedRef()
		];
	}
	
	if(CurrentDatabaseInfo == nullptr)
	{
		CurrentDatabaseInfo = new FDatabaseInfo("", "", "", "", "");
	}
	
	CurrentPathText = SNew(STextBlock)
		.Text(FText::FromString("Path : "))
		.Justification(ETextJustify::Left)
		.ColorAndOpacity(FLinearColor::Black)
		.Font(FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Regular", 9.0f)));
		
	CurrentDataTablePath = TEXT("/Game/JsonDBDataTable.JsonDBDataTable");
	/*DataTableEntryBox = SNew(SObjectPropertyEntryBox)
		.AllowedClass(UDataTable::StaticClass())
		.AllowClear(true)
		.ObjectPath(CurrentDataTablePath)
		.OnObjectChanged(FOnSetObject::CreateRaw(this, &FJsonDBConfigLoaderModule::OnDataTableChanged));*/
	
	DataTableEntryBox = CreateDataTableEntryBox();
	DataTableBox = SNew(SBox)
	.HeightOverride(30)
	[
		DataTableEntryBox.ToSharedRef()
	];

	DockTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			
			SNew(SVerticalBox)
			
			//Input Json Database Config
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Fill)
			.FillHeight(1.0f)
			[
			    SNew(SBox)
			    .Padding(2.0f)
			    [
				SNew(SSplitter)
    			+ SSplitter::Slot()
    			.Value(0.25f) 
    			[
    				SNew(SVerticalBox)
			
    				+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(30)
						[
							SNew(SBorder)
							.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
							.BorderBackgroundColor(FLinearColor(0, 0, 0, 0.25))
							[
								SNew(STextBlock)
								.Text(FText::FromString("List"))
								.Justification(ETextJustify::Center)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Bold", 16.0f)))
							]
						]
					]
					
    				+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(30)
						[
							SNew(SHorizontalBox)
							
							+ SHorizontalBox::Slot()
							.HAlign(HAlign_Fill)
							.FillWidth(0.5f)
							[
								SNew(SBox)
								[
									SNew(SButton)
									.HAlign(HAlign_Center)
									.VAlign(VAlign_Center)
									.Text(FText::FromString("Add"))
									.OnClicked_Raw(this, &FJsonDBConfigLoaderEditorModule::OnButtonAddNewJson)
								]
							]
							
							+ SHorizontalBox::Slot()
							.HAlign(HAlign_Fill)
							.FillWidth(0.5f)
							[
								SNew(SBox)
								[
									SNew(SButton)
									.HAlign(HAlign_Center)
									.VAlign(VAlign_Center)
									.Text(FText::FromString("Create"))
									.OnClicked_Raw(this, &FJsonDBConfigLoaderEditorModule::OnButtonCreateNewJson)
								]
							]
						]
					]
			
					+ SVerticalBox::Slot()
					.VAlign(VAlign_Fill)
					.FillHeight(1.0f)
					[
						StaticCastSharedRef<SWidget>(JsonScrollListBox.ToSharedRef())
					]
    			]
    
				+ SSplitter::Slot()
    			.Value(0.75f)  
    			[
    				SNew(SVerticalBox)
			
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(30)
						[
							SNew(SBorder)
							.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
							.BorderBackgroundColor(FLinearColor(0, 0, 0, 0.25))
							[
								SNew(STextBlock)
								.Text(FText::FromString("Config"))
								.Justification(ETextJustify::Center)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Bold", 16.0f)))
							]
						]
					]
					
					+ SVerticalBox::Slot()
    				.VAlign(VAlign_Fill)
					.FillHeight(1.0f)
					[
						SNew(SHorizontalBox)
						
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.FillWidth(0.4f)
						[
							SNew(SVerticalBox)
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SNew(STextBlock)
									.Text(FText::FromString("Hostname / IP : "))
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SNew(STextBlock)
									.Text(FText::FromString("Username : "))
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SNew(STextBlock)
									.Text(FText::FromString("Password : "))
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SNew(STextBlock)
									.Text(FText::FromString("Port : "))
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SNew(STextBlock)
									.Text(FText::FromString("Database Name : "))
								]
							]
							
							+ SVerticalBox::Slot()
							.VAlign(VAlign_Fill)
							.FillHeight(1.0f)
							[
								SNew(SBox)
							]
						]
						
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.FillWidth(0.6f)
						[
							SNew(SVerticalBox)
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SAssignNew(HostnameInputText, SEditableTextBox)
									.Text(FText::FromString(CurrentDatabaseInfo != nullptr ? CurrentDatabaseInfo->Hostname : ""))
									.HintText(FText::FromString("127.0.0.1 Or yourdomain.com"))
									.OnTextChanged_Lambda([&](const FText& NewText)
									{
										if(CurrentDatabaseInfo != nullptr && JsonButtonLists.Contains(CurrentFileInfo->FileName))
										{
											TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
										
											if(!CurrentDatabaseInfo->CheckDataInfo(
											FDatabaseInfo(NewText.ToString(),
											CurrentDatabaseInfo->Username,
											CurrentDatabaseInfo->Password,
											CurrentDatabaseInfo->Port,
											CurrentDatabaseInfo->DatabaseName)))
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(FLinearColor::Black);
												CurrentFileInfo->IsEdit = true;
											}
											else
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(HideColor);
												CurrentFileInfo->IsEdit = false;
											}
										}
										
										CurrentDatabaseInfo->Hostname = NewText.ToString();
									})
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SAssignNew(UsernameInputText, SEditableTextBox)
									.Text(FText::FromString(CurrentDatabaseInfo != nullptr ? CurrentDatabaseInfo->Username : ""))
									.HintText(FText::FromString("username"))
									.OnTextChanged_Lambda([&](const FText& NewText)
									{
										if(CurrentDatabaseInfo != nullptr && JsonButtonLists.Contains(CurrentFileInfo->FileName))
										{
											TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
										
											if(!CurrentDatabaseInfo->CheckDataInfo(
											FDatabaseInfo(CurrentDatabaseInfo->Hostname,
											NewText.ToString(),
											CurrentDatabaseInfo->Password,
											CurrentDatabaseInfo->Port,
											CurrentDatabaseInfo->DatabaseName)))
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(FLinearColor::Black);
												CurrentFileInfo->IsEdit = true;
											}
											else
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(HideColor);
												CurrentFileInfo->IsEdit = false;
											}
										}
											
										CurrentDatabaseInfo->Username = NewText.ToString();
									})
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SAssignNew(PasswordInputText, SEditableTextBox)
									.Text(FText::FromString(CurrentDatabaseInfo != nullptr ? CurrentDatabaseInfo->Password : ""))
									.HintText(FText::FromString("password"))
									.IsPassword(true)
									.OnTextChanged_Lambda([&](const FText& NewText)
									{
										if(CurrentDatabaseInfo != nullptr && JsonButtonLists.Contains(CurrentFileInfo->FileName))
										{
											TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
										
											if(!CurrentDatabaseInfo->CheckDataInfo(
											FDatabaseInfo(CurrentDatabaseInfo->Hostname,
											CurrentDatabaseInfo->Username,
											NewText.ToString(),
											CurrentDatabaseInfo->Port,
											CurrentDatabaseInfo->DatabaseName)))
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(FLinearColor::Black);
												CurrentFileInfo->IsEdit = true;
											}
											else
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(HideColor);
												CurrentFileInfo->IsEdit = false;
											}
										}
										
										CurrentDatabaseInfo->Password = NewText.ToString();
									})
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SAssignNew(PortInputText, SEditableTextBox)
									.Text(FText::FromString(CurrentDatabaseInfo != nullptr ? CurrentDatabaseInfo->Port : ""))
									.HintText(FText::FromString("8080"))
									.OnTextChanged_Lambda([&](const FText& NewText)
									{
										if(CurrentDatabaseInfo != nullptr && JsonButtonLists.Contains(CurrentFileInfo->FileName))
										{
											TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
										
											if(!CurrentDatabaseInfo->CheckDataInfo(
											FDatabaseInfo(CurrentDatabaseInfo->Hostname,
											CurrentDatabaseInfo->Username,
											CurrentDatabaseInfo->Password,
											NewText.ToString(),
											CurrentDatabaseInfo->DatabaseName)))
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(FLinearColor::Black);
												CurrentFileInfo->IsEdit = true;
											}
											else
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(HideColor);
												CurrentFileInfo->IsEdit = false;
											}
										}
											
										CurrentDatabaseInfo->Port = NewText.ToString();
									})
								]
							]
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SAssignNew(DatabaseInputText, SEditableTextBox)
									.Text(FText::FromString(CurrentDatabaseInfo != nullptr ? CurrentDatabaseInfo->DatabaseName : ""))
									.HintText(FText::FromString("database name"))
									.OnTextChanged_Lambda([&](const FText& NewText)
									{
										if(CurrentDatabaseInfo != nullptr && JsonButtonLists.Contains(CurrentFileInfo->FileName))
										{
											TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
											
											if(!CurrentDatabaseInfo->CheckDataInfo(
											FDatabaseInfo(CurrentDatabaseInfo->Hostname,
											CurrentDatabaseInfo->Username,
											CurrentDatabaseInfo->Password,
											CurrentDatabaseInfo->Port,
											NewText.ToString())))
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(FLinearColor::Black);
												CurrentFileInfo->IsEdit = true;
											}
											else
											{
												ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(HideColor);
												CurrentFileInfo->IsEdit = false;
											}
										}
											
										CurrentDatabaseInfo->DatabaseName = NewText.ToString();
									})
								]
							]
							
							+ SVerticalBox::Slot()
							.VAlign(VAlign_Fill)
							.FillHeight(1.0f)
							[
								SNew(SBox)
							]
						]
					]
					
    				+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(30)
						[
							SNew(SBorder)
							.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
							.BorderBackgroundColor(FLinearColor(0, 0, 0, 0.25))
							[
								SNew(STextBlock)
								.Text(FText::FromString("Data Table"))
								.Justification(ETextJustify::Center)
								.ColorAndOpacity(FLinearColor::White)
								.Font(FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Bold", 16.0f)))
							]
						]
					]
					
					+ SVerticalBox::Slot()
    				.VAlign(VAlign_Fill)
					.FillHeight(1.0f)
					[
						SNew(SHorizontalBox)
						
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.FillWidth(0.4f)
						[
							SNew(SVerticalBox)
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(30)
								[
									SNew(STextBlock)
									.Text(FText::FromString("Your data table : "))
								]
							]
							
							+ SVerticalBox::Slot()
							.VAlign(VAlign_Fill)
							.FillHeight(1.0f)
							[
								SNew(SBox)
							]
						]
						
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.FillWidth(0.6f)
						[
							SNew(SVerticalBox)
							
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								DataTableBox.ToSharedRef()
							]
							
							+ SVerticalBox::Slot()
							.VAlign(VAlign_Fill)
							.FillHeight(1.0f)
							[
								SNew(SBox)
							]
						]
					]
					
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(20)
						[
							SNew(SBorder)
							.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
							.BorderBackgroundColor(FLinearColor(1, 1, 1, 0.5))
							.VAlign(VAlign_Center)
							[
								CurrentPathText.ToSharedRef()
							]
						]
					]
    			]
			]
			]
			
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBox)
				.Padding(2.0f)
				.HeightOverride(29)
				[
					SNew(SHorizontalBox)
					
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(150)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Text(FText::FromString("Clear List"))
							.OnClicked_Raw(this, &FJsonDBConfigLoaderEditorModule::OnButtonClearList)
						]
					]
					
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(150)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Text(FText::FromString("Clear Config"))
							.OnClicked_Raw(this, &FJsonDBConfigLoaderEditorModule::OnButtonClearConfig)
						]
					]
					
					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Fill)
					.FillWidth(1.0f)
					[
						SNew(SBox)
					]
				
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(150)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Text(FText::FromString("Save"))
							.OnClicked_Raw(this, &FJsonDBConfigLoaderEditorModule::OnButtonSave)
						]
					]
				
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(150)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Text(FText::FromString("Load"))
							.OnClicked_Raw(this, &FJsonDBConfigLoaderEditorModule::OnButtonLoad)
						]
					]
				]
			]
		];
		
	return DockTab.ToSharedRef();
}

void FJsonDBConfigLoaderEditorModule::AutoShowEmptyJsonText()
{
	if(!JsonScrollListBox.IsValid())
	{
		JsonScrollListBox = SNew(SScrollBox)
		+ SScrollBox::Slot()
		.VAlign(VAlign_Top);
	}
	
	if(JsonDBCLManager->DatabaseInfos.Num() <= 0)
	{
		TSharedPtr<STextBlock> TextEmpty = SNew(STextBlock)
		   .Text(FText::FromString("Empty Json List."))
		   .Justification(ETextJustify::Center);
	
		TextJsonEmpty = SNew(SBox)
		.HeightOverride(35)
		[
			TextEmpty.ToSharedRef()
		];	
		
		JsonScrollListBox->AddSlot()
		[
		    TextJsonEmpty.ToSharedRef()
		];
	}
	else
	{
		JsonScrollListBox->RemoveSlot(TextJsonEmpty.ToSharedRef());
	}
}

FReply FJsonDBConfigLoaderEditorModule::OnButtonClick()
{
	UE_LOG(LogTemp, Display, TEXT("ButtonClicked"));
	return FReply::Handled();
}

FReply FJsonDBConfigLoaderEditorModule::OnButtonSave()
{
	UE_LOG(LogTemp, Display, TEXT("ButtonSave"));
	OnSaveJson();
	return FReply::Handled();
}

FReply FJsonDBConfigLoaderEditorModule::OnButtonLoad()
{
	UE_LOG(LogTemp, Display, TEXT("ButtonLoad"));
	OnLoadJson();
	return FReply::Handled();
}

FReply FJsonDBConfigLoaderEditorModule::OnButtonAddNewJson()
{
	OnAddJson();
	return FReply::Handled();
}

void FJsonDBConfigLoaderEditorModule::OnAddJson()
{
	TArray<FString> JsonFiles = JsonDBCLManager->OpenLoadFileDialog();
	FDatabaseInfo DatabaseInfo;
	AddJsonFileToDatabaseList(JsonFiles, DatabaseInfo, false);
}

void FJsonDBConfigLoaderEditorModule::OnDataTableChanged(const FAssetData& NewAssetData)
{
	FString DatatablePath = NewAssetData.GetFullName();
	UE_LOG(LogTemp, Warning, TEXT("Current Datatable : %s"), *NewAssetData.ObjectPath.ToString());
	
	if (NewAssetData.IsValid())
	{
		UDataTable* DataTable = Cast<UDataTable>(NewAssetData.GetAsset());
		if (DataTable)
		{
			CurrentDataTable = DataTable;
			CurrentDataTablePath = NewAssetData.ObjectPath.ToString();
			DataTableEntryBox = CreateDataTableEntryBox();
		}
	}
}

FReply FJsonDBConfigLoaderEditorModule::OnButtonCreateNewJson()
{
	FDatabaseInfo* NewDatabaseInfo = new FDatabaseInfo("", "", "", "", "");
	OnCreateJson(*NewDatabaseInfo);
	return FReply::Handled();
}

FReply FJsonDBConfigLoaderEditorModule::OnButtonClearList()
{
    FOnClicked ConfirmAction;
    ConfirmAction.BindLambda([this]()->FReply
    {
    	for (TTuple<FString, FJsonInfo> DatabaseInfo : JsonDBCLManager->DatabaseInfos)
    	{
			OnButtonDelete(&DatabaseInfo.Value.Key.FileName);
		}
		
		return FReply::Handled();
    });
    
	FOnClicked CancelAction;
    ShowMessageDialogWithAction(FText::FromString("Are you sure you want to clear all Json files?"), ConfirmAction, CancelAction);
    
    return FReply::Handled();
}

FReply FJsonDBConfigLoaderEditorModule::OnButtonClearConfig()
{
	FOnClicked ConfirmAction;
	ConfirmAction.BindLambda([this]()->FReply
	{
		ClearConfig();
		
		return FReply::Handled();
	});
	
	FOnClicked CancelAction;
	ShowMessageDialogWithAction(FText::FromString("Are you sure you want to clear all configurations?"), ConfirmAction, CancelAction);
	
	return FReply::Handled();
}

void FJsonDBConfigLoaderEditorModule::ClearConfig()
{
	if(CurrentFileInfo != nullptr && JsonButtonLists.Contains(CurrentFileInfo->FileName))
	{
		CurrentFileInfo->IsLoad = false;
		TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
		ButtonInfo->SelectBar.ToSharedRef()->SetBorderBackgroundColor(HideColor);
		CurrentPathText->SetText(FText::FromString("Path : "));
	}
    
	CurrentDatabaseInfo = new FDatabaseInfo("", "", "", "", "");
	CurrentFileInfo = new FFileInfo("", "", false, false);
	
	if(HostnameInputText.IsValid() && UsernameInputText.IsValid() && PasswordInputText.IsValid() && PortInputText.IsValid() && DatabaseInputText.IsValid())
	{
		HostnameInputText.ToSharedRef()->SetText(FText::FromString(""));
		UsernameInputText.ToSharedRef()->SetText(FText::FromString(""));
		PasswordInputText.ToSharedRef()->SetText(FText::FromString(""));
		PortInputText.ToSharedRef()->SetText(FText::FromString(""));
		DatabaseInputText.ToSharedRef()->SetText(FText::FromString(""));
	}
}

void FJsonDBConfigLoaderEditorModule::OnCreateJson(FDatabaseInfo DatabaseInfo)
{
	TArray<FString> JsonFiles = JsonDBCLManager->OpenSaveFileDialog();
	AddJsonFileToDatabaseList(JsonFiles, DatabaseInfo, true);
}

void FJsonDBConfigLoaderEditorModule::AddJsonFileToDatabaseList(TArray<FString> JsonFiles, FDatabaseInfo DatabaseInfo, bool isSave = true)
{
	if(JsonFiles.Num() <= 0)
	{
		return;
	}
	
	FString JsonName;
	
	for (FString JsonFile : JsonFiles)
	{
		ShowNotification(FText::FromString("Add file to list : " + JsonFile), FName("Plus"));
		
		TArray<FString> Paths;
		
		JsonFile.ParseIntoArray(Paths, TEXT("/"), true);
		JsonName = Paths[Paths.Num() - 1];
		JsonName += ":" + JsonFile;
		
		FFileInfo FileInfo = FFileInfo(JsonName, JsonFile, false, false);
		
		if(isSave)
		{
			UJsonDBConfigLoaderEditorManager::SaveJsonDBConfig(JsonFile, DatabaseInfo);
		}
		else
		{
			UJsonDBConfigLoaderEditorManager::LoadJsonDBConfig(JsonFile, DatabaseInfo);
		}
		bool isOverride;
		JsonDBCLManager->AddDatabaseInfo(FileInfo, DatabaseInfo, isOverride);
		
		if(isOverride)
		{
			JsonScrollListBox->RemoveSlot(JsonButtonLists[JsonName]->Box.ToSharedRef());
			JsonButtonLists.Remove(JsonName);
		}
		AddJsonFileInList(JsonName);
	}
	
	OnSetCurrentJson(&JsonName);
}

void FJsonDBConfigLoaderEditorModule::AddJsonFileInList(FString FileName)
{
	TSharedRef<FButtonInfo> ButtonInfo = JsonFileButton(FileName, 
	FClickAction::CreateRaw(this, &FJsonDBConfigLoaderEditorModule::OnSetCurrentJson), 
	FClickAction::CreateRaw(this, &FJsonDBConfigLoaderEditorModule::OnButtonDelete));
	
	AutoShowEmptyJsonText();
	
	TSharedPtr<SBorder> MainBorder = SNew(SBorder)
	.Padding(0)
	.BorderBackgroundColor(FLinearColor(0,0,0,0))
	[
		ButtonInfo->Parent.ToSharedRef()
	];
	
	TSharedPtr<SBox> Box = SNew(SBox)
	.Padding(0)
	.HeightOverride(35)
	[
		MainBorder.ToSharedRef()
	];
	
	JsonScrollListBox->AddSlot()
	.Padding(0)
	[
		Box.ToSharedRef()
	];
	
	ButtonInfo->Box = Box;
	JsonButtonLists.Add(FileName, ButtonInfo);
}

void FJsonDBConfigLoaderEditorModule::OnSetCurrentJson(FString* FileName)
{
	if(CurrentFileInfo != nullptr && !CurrentFileInfo->IsEmpty() && JsonButtonLists.Contains(CurrentFileInfo->FileName))
	{
		CurrentFileInfo->IsLoad = false;
		TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
		ButtonInfo->SelectBar.ToSharedRef()->SetBorderBackgroundColor(HideColor);
		CurrentPathText->SetText(FText::FromString("Path : "));
	}

	if(FileName == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("FileName is nulllllll!!!!!!!!!!!!!!!"));
		return;
	}
		
	if(JsonDBCLManager == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("JsonDBCLManager is nulllllll!!!!!!!!!!!!!!!"));
		return;
	}
	
	FJsonInfo* JsonInfo = &JsonDBCLManager->DatabaseInfos[*FileName];
	CurrentFileInfo = &JsonInfo->Key;
	CurrentFileInfo->IsLoad = true;
	CurrentDatabaseInfo = &JsonInfo->Value;
	
	if(HostnameInputText.IsValid() && UsernameInputText.IsValid() && PasswordInputText.IsValid() && PortInputText.IsValid() && DatabaseInputText.IsValid())
	{
		HostnameInputText.ToSharedRef()->SetText(FText::FromString(CurrentDatabaseInfo->Hostname));
		UsernameInputText.ToSharedRef()->SetText(FText::FromString(CurrentDatabaseInfo->Username));
		PasswordInputText.ToSharedRef()->SetText(FText::FromString(CurrentDatabaseInfo->Password));
		PortInputText.ToSharedRef()->SetText(FText::FromString(CurrentDatabaseInfo->Port));
		DatabaseInputText.ToSharedRef()->SetText(FText::FromString(CurrentDatabaseInfo->DatabaseName));
	}
	
	TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
	ButtonInfo->SelectBar.ToSharedRef()->SetBorderBackgroundColor(SelectColor);
	CurrentPathText->SetText(FText::FromString(FString::Printf(TEXT("Path : %s"), *CurrentFileInfo->FilePath)));

	UE_LOG(LogTemp, Warning, TEXT("Current FileNameInfo : %s : %s"), *CurrentFileInfo->FileName, *CurrentFileInfo->FilePath);
	UE_LOG(LogTemp, Warning, TEXT("In Class Current DatabaseInfo : %s : %s"), *CurrentDatabaseInfo->Hostname, *CurrentDatabaseInfo->DatabaseName)
}

void FJsonDBConfigLoaderEditorModule::OnLoadJson()
{
	TArray<FString> FileNames;
	CurrentFileInfo->FileName.ParseIntoArray(FileNames, TEXT(":"));
	FString FileName = FileNames[0];
	FJsonDBConfigDataTable::AddRowToDataTable(CurrentDataTable, FileName, *CurrentDatabaseInfo);
}

void FJsonDBConfigLoaderEditorModule::OnSaveJson()
{
	if(CurrentFileInfo == nullptr || CurrentFileInfo->FileName.IsEmpty())
	{
		OnCreateJson(*CurrentDatabaseInfo);
	}else
	{
		TSharedPtr<FButtonInfo> ButtonInfo = JsonButtonLists[CurrentFileInfo->FileName];
		ButtonInfo->UnsavedIndicator.ToSharedRef()->SetColorAndOpacity(HideColor);
		JsonDBCLManager->DatabaseInfos[CurrentFileInfo->FileName].Value.ApplyBaseDataInfo();
		UJsonDBConfigLoaderEditorManager::SaveJsonDBConfig(CurrentFileInfo->FilePath, *CurrentDatabaseInfo);
	}
}

TSharedRef<FButtonInfo> FJsonDBConfigLoaderEditorModule::JsonFileButton(FString FileName, FClickAction SelectAction, FClickAction DeleteAction)
{
	UE_LOG(LogTemp, Warning, TEXT("Current FileName : %s"), *FileName);
	FString CurrentFileName = FileName;
	
	TArray<FString> Names;	
	JsonDBCLManager->DatabaseInfos[CurrentFileName].Key.FileName.ParseIntoArray(Names, TEXT(":"));
	FFileInfo FileInfo = JsonDBCLManager->DatabaseInfos[CurrentFileName].Key;
	
	TSharedPtr<STextBlock> TextBlock = SNew(STextBlock)
	.Text(FText::FromString(Names[0]));
	
	TSharedPtr<SBorder> SelectBar = SNew(SBorder)
	.Padding(0)
	.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
	.BorderBackgroundColor(HideColor);
	
	TSharedPtr<STextBlock> UnsavedIndicator = SNew(STextBlock)
	.Text(FText::FromString("*"))
	.Justification(ETextJustify::Center)
	.ColorAndOpacity(FileInfo.IsEdit ? FLinearColor::Black : HideColor)
	.Font(FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Bold", 12.0f)));
	
	TSharedPtr<SHorizontalBox> HorizontalBox = SNew(SHorizontalBox)
	+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SBox)
			.Padding(0)
			.WidthOverride(2)
			[
				SelectBar.ToSharedRef()
			]
		]
	
	+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		[
			SNew(SBox)
			.Padding(5.0f)
			[
				TextBlock.ToSharedRef()
			]
		]
	
	+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SBox)
			.Padding(0)
			.WidthOverride(5)
			[
				UnsavedIndicator.ToSharedRef()
			]
		];
	
	TSharedPtr<SButton> Button = SNew(SButton)
	.VAlign(VAlign_Center)
	.OnClicked_Lambda([&, SelectAction, CurrentFileName]() -> FReply {	
		if(SelectAction.IsBound())
		{
			FString* FileNameCopy = &JsonDBCLManager->DatabaseInfos[CurrentFileName].Key.FileName;
	    	
			if(&JsonDBCLManager->DatabaseInfos[*FileNameCopy].Key != nullptr)
			{
				SelectAction.Execute(FileNameCopy);
			}
		}
	    
		return FReply::Handled();
	})
	[
		HorizontalBox.ToSharedRef()
	];
	
	TSharedPtr<SButton> DeleteButton = SNew(SButton)
	.VAlign(VAlign_Center)
	.OnClicked_Lambda([&, DeleteAction, CurrentFileName]() -> FReply {	
	    
		FOnClicked ConfirmAction;
		ConfirmAction.BindLambda([&DeleteAction, &CurrentFileName, this]()->FReply
		{
			if(DeleteAction.IsBound())
			{
				FString* FileNameCopy = &JsonDBCLManager->DatabaseInfos[CurrentFileName].Key.FileName;
	    	
				if(&JsonDBCLManager->DatabaseInfos[*FileNameCopy].Key != nullptr)
				{
					DeleteAction.Execute(FileNameCopy);
				}
			}
		
			return FReply::Handled();
		});
	
		FOnClicked CancelAction;
		ShowMessageDialogWithAction(FText::FromString("Are you sure you want to remove the Json file from the list?"), ConfirmAction, CancelAction);
		
		return FReply::Handled();
	})
	[
	    SNew(SBox)
	    .Padding(4)
	    [
	    	SNew(SImage)
		    .Image(FEditorStyle::Get().GetBrush("Symbols.X"))
		    .ColorAndOpacity(FLinearColor::Red)
	    ]
	];
	
	TSharedPtr<SHorizontalBox> ButtonHorizontalBox = SNew(SHorizontalBox)
	
	+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		[
			SNew(SBox)
			.Padding(0)
			[
				Button.ToSharedRef()
			]
		]
	
	+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SBox)
			.Padding(0)
			.WidthOverride(35)
			[
				DeleteButton.ToSharedRef()
			]
		];
	
	return MakeShareable(new FButtonInfo(ButtonHorizontalBox, Button, DeleteButton, nullptr, SelectBar, UnsavedIndicator));
}

bool FJsonDBConfigLoaderEditorModule::ShowMessageDialog(FText Message)
{
	return FMessageDialog::Open(EAppMsgType::YesNo, Message) == EAppReturnType::Yes;
    
}

void FJsonDBConfigLoaderEditorModule::ShowMessageDialogWithAction(FText Message, FOnClicked ConfirmAction, FOnClicked CancelAction)
{
    bool bConfirm = FMessageDialog::Open(EAppMsgType::YesNo, Message) == EAppReturnType::Yes;
    
    if(bConfirm)
    {
        if(ConfirmAction.IsBound())
        {
            ConfirmAction.Execute();
        }
    }
    else
    {
	    if(CancelAction.IsBound())
	    {
	        CancelAction.Execute();
	    }
    }
}

TSharedPtr<SObjectPropertyEntryBox> FJsonDBConfigLoaderEditorModule::CreateDataTableEntryBox()
{
	UE_LOG(LogTemp, Warning, TEXT("CreateDataTableEntryBox : %s"), *CurrentDataTablePath);
	
	TSharedPtr<SObjectPropertyEntryBox> EntryBox = SNew(SObjectPropertyEntryBox)
		.AllowedClass(UDataTable::StaticClass())
		.AllowClear(true)
		.ObjectPath(CurrentDataTablePath)
		.OnObjectChanged(FOnSetObject::CreateRaw(this, &FJsonDBConfigLoaderEditorModule::OnDataTableChanged));
	
	if(DataTableBox.IsValid())
	{
		DataTableBox->SetContent(EntryBox.ToSharedRef());
	}
	
	return EntryBox;
}

void FJsonDBConfigLoaderEditorModule::ShowNotification(FText Message, FName MessageLog)
{
	FNotificationInfo Info(Message);
	Info.ExpireDuration = 15.0f;
	Info.bFireAndForget = true;
	Info.Image = FEditorStyle::Get().GetBrush(MessageLog);
	
	FSlateNotificationManager::Get().AddNotification(Info);
}

void FJsonDBConfigLoaderEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(JsonDBConfigLoaderTabName);
}

void FJsonDBConfigLoaderEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FJsonDBConfigLoaderEditorCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FJsonDBConfigLoaderEditorCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

/*FReply FJsonDBConfigLoaderModule::OnShowContextMenu(const FGeometry& Geometry, const FPointerEvent& MouseEvent)
{
	FButtonAction OnShowMenuAction;
	OnShowMenuAction.BindLambda([this](){
		OnButtonDelete();
	});
	return MenuWidget->OnButtonShowContextMenu(Geometry, MouseEvent, OnShowMenuAction);
}*/

void FJsonDBConfigLoaderEditorModule::OnButtonDelete(FString* FileName)
{
	UE_LOG(LogTemp, Warning, TEXT("Delete Now!!!!!!!!!!!!!!"));
	ShowNotification(FText::FromString("Remove files from list : " + FString(*FileName)), "PropertyWindow.Button_RemoveFromArray");
	JsonScrollListBox->RemoveSlot(JsonButtonLists[*FileName]->Box.ToSharedRef());
	UE_LOG(LogTemp, Warning, TEXT("Current Slot Num : %d"), JsonScrollListBox->GetChildren()->Num());
	JsonButtonLists.Remove(*FileName);
	JsonDBCLManager->RemoveDatabaseInfo(*FileName);
	CurrentPathText->SetText(FText::FromString("Path : "));
	
	if(JsonDBCLManager->DatabaseInfos.Num() <= 0)
	{
		ClearConfig();
	}
	else
	{
		TArray<FString> Keys;
		JsonDBCLManager->DatabaseInfos.GetKeys(Keys);
		FString LastKay = Keys.Last();
		OnSetCurrentJson(&LastKay);
	}
	
	AutoShowEmptyJsonText();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FJsonDBConfigLoaderEditorModule, JsonDBConfigLoader)