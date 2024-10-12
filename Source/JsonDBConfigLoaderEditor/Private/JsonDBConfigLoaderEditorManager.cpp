// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonDBConfigLoaderEditorManager.h"

#include <vector>

#include "DesktopPlatformModule.h"
#include "IDesktopPlatform.h"
#include "Dom/JsonObject.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

UJsonDBConfigLoaderEditorManager* UJsonDBConfigLoaderEditorManager::Instance;

UJsonDBConfigLoaderEditorManager::UJsonDBConfigLoaderEditorManager()
{
	UE_LOG(LogTemp, Display, TEXT("On Initial"));
}

UJsonDBConfigLoaderEditorManager* UJsonDBConfigLoaderEditorManager::GetInstance()
{
	if(!Instance)
	{
		Instance = NewObject<UJsonDBConfigLoaderEditorManager>();
		Instance->AddToRoot();
	}
	
	return Instance;
}

int UJsonDBConfigLoaderEditorManager::AddDatabaseInfo(FFileInfo fileInfo, FDatabaseInfo databaseinfo, bool& isOverride)
{
	if(DatabaseInfos.Contains(fileInfo.FileName) && DatabaseInfos[fileInfo.FileName].Key.FilePath == fileInfo.FilePath)
	{
		FJsonInfo* JsonInfo = &DatabaseInfos[fileInfo.FileName];
		JsonInfo->Key = fileInfo;
		JsonInfo->Value = databaseinfo;
		
		int index = FileNames.Find(fileInfo.FileName);
		FileNames[index] = fileInfo.FileName;
		isOverride = true;
		return index;
	}
	else
	{
		isOverride = false;
		DatabaseInfos.Add(fileInfo.FileName, FJsonInfo(fileInfo, databaseinfo));
		return FileNames.Add(fileInfo.FileName);
	}
}

void UJsonDBConfigLoaderEditorManager::RemoveDatabaseInfo(FString FileName)
{
	DatabaseInfos.Remove(FileName);
	FileNames.Remove(FileName);
}

FDatabaseInfo* UJsonDBConfigLoaderEditorManager::GetDatabase(FString FileName)
{
	return &DatabaseInfos[FileName].Value;
}

FFileInfo* UJsonDBConfigLoaderEditorManager::GetFileInfo(FString FileName)
{
	return &DatabaseInfos[FileName].Key;
}

FJsonInfo* UJsonDBConfigLoaderEditorManager::GetJsoninfo(FString FileName)
{
	return &DatabaseInfos[FileName];
}

TArray<FString> UJsonDBConfigLoaderEditorManager::OpenLoadFileDialog()
{
	
	TArray<FString> JsonFiles;
	
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	
	if(DesktopPlatform)
	{
		DesktopPlatform->OpenFileDialog(
		nullptr,
		TEXT("Select a File"),
		TEXT(""),
		TEXT(""),
		TEXT("JSON Files (*.json)|*.json|All Files (*.*)|*.*"),
		EFileDialogFlags::Multiple,
		JsonFiles
		);
	}
	
	if(JsonFiles.Num() > 0)
	{
		for (const FString& jsonFile : JsonFiles)
		{
			UE_LOG(LogTemp, Log, TEXT("Selected JSON File: %s"), *jsonFile);
		}
	}
	
	return JsonFiles;
}

TArray<FString> UJsonDBConfigLoaderEditorManager::OpenSaveFileDialog()
{
	TArray<FString> JsonFiles;
	
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	
	if(DesktopPlatform)
	{
		DesktopPlatform->SaveFileDialog(
		nullptr,
		TEXT("Select a File"),
		TEXT(""),
		TEXT(""),
		TEXT("JSON Files (*.json)|*.json|All Files (*.*)|*.*"),
		EFileDialogFlags::None,
		JsonFiles
		);
	}
	
	if(JsonFiles.Num() > 0)
	{
		for (const FString& jsonFile : JsonFiles)
		{
			UE_LOG(LogTemp, Log, TEXT("Selected JSON File: %s"), *jsonFile);
		}
	}
	
	return JsonFiles;
}

void UJsonDBConfigLoaderEditorManager::SaveJsonDBConfig(FString FilePath, FDatabaseInfo DatabaseInfo)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	
	JsonObject->SetStringField(TEXT("Hostname"), DatabaseInfo.Hostname);
	JsonObject->SetStringField(TEXT("Username"), DatabaseInfo.Username);
	JsonObject->SetStringField(TEXT("Password"), DatabaseInfo.Password);
	JsonObject->SetStringField(TEXT("Port"), DatabaseInfo.Port);
	JsonObject->SetStringField(TEXT("DatabaseName"), DatabaseInfo.DatabaseName);
	
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
	
	FFileHelper::SaveStringToFile(JsonString, *FilePath);
}

bool UJsonDBConfigLoaderEditorManager::LoadJsonDBConfig(FString FilePath, FDatabaseInfo& DatabaseInfo)
{
	FString JsonString;
	
	if(!FFileHelper::LoadFileToString(JsonString, *FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load JSON file: %s"), *FilePath);
		return false;
	}
	
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
	TSharedPtr<FJsonObject> JsonObject;
	
	if(FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		DatabaseInfo = FDatabaseInfo(
		JsonObject->GetStringField(TEXT("Hostname")),
		JsonObject->GetStringField(TEXT("Username")),
		JsonObject->GetStringField(TEXT("Password")),
		JsonObject->GetStringField(TEXT("Port")),
		JsonObject->GetStringField(TEXT("DatabaseName")));
	    
	    return true;
	}
	
	DatabaseInfo = FDatabaseInfo("","","","","");
	
	return false;
}

void UJsonDBConfigLoaderEditorManager::RemoveJsonInList(FString FileName)
{
	DatabaseInfos.Remove(FileName);
	FileNames.Remove(FileName);
}