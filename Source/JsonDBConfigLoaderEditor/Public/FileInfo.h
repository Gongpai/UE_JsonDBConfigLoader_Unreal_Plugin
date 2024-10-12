#pragma once

#include "FileInfo.generated.h"

USTRUCT(BlueprintType)
struct JSONDBCONFIGLOADEREDITOR_API FFileInfo
{
	GENERATED_BODY()

public:
	FFileInfo();
	FFileInfo(const FString& fileName, const FString& filePath, bool isLoad, bool isEdit);

	void SetFileName(FString fileName);
	FString GetFileName();
	
	void SetFilePath(FString filePath);
	FString GetFilePath();
	
	void SetIsLoad(bool isLoad);
	bool GetIsLoad();
	
	void SetIsEdit(bool isEdit);
	bool GetIsEdit();
	
	bool IsEmpty();

	UPROPERTY()
	FString FileName;
	
	UPROPERTY()
	FString FilePath;
	
	UPROPERTY()
	bool IsLoad;
	
	UPROPERTY()
	bool IsEdit;
};
