// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DatabaseInfo.h"
#include "FileInfo.h"
#include "JsonInfo.h"
#include "Containers/Map.h"
#include "JsonDBConfigLoaderManager.generated.h"

UCLASS()
class JSONDBCONFIGLOADER_API UJsonDBConfigLoaderManager : public UObject
{
	GENERATED_BODY()

public:
	static UJsonDBConfigLoaderManager* GetInstance();
	
	int AddDatabaseInfo(FFileInfo fileInfo, FDatabaseInfo databaseinfo, bool& isOverride);
	void RemoveDatabaseInfo(FString FileName);
	FDatabaseInfo* GetDatabase(FString FileName);
	FFileInfo* GetFileInfo(FString FileName);
	FJsonInfo* GetJsoninfo(FString FileName);
	
protected:

public:
	UJsonDBConfigLoaderManager();
	static void SaveJsonDBConfig(FString FilePath, FDatabaseInfo DatabaseInfo);
	static bool LoadJsonDBConfig(FString FilePath, FDatabaseInfo& DatabaseInfo);
	void RemoveJsonInList(FString FileName);

	TArray<FString> OpenLoadFileDialog();
	TArray<FString> OpenSaveFileDialog();
	
	UPROPERTY()
	TMap<FString, FJsonInfo> DatabaseInfos;
	TArray<FString> FileNames;
	
private:
	static UJsonDBConfigLoaderManager* Instance;
};
