#pragma once
#include "DatabaseInfo.h"
#include "FileInfo.h"

#include "JsonInfo.generated.h"

USTRUCT(BlueprintType)
struct JSONDBCONFIGLOADER_API FJsonInfo
{
	GENERATED_BODY()

public:
	FJsonInfo();
	FJsonInfo(FFileInfo _key, FDatabaseInfo _value);

	UPROPERTY()
	FFileInfo Key;
	
	UPROPERTY()
	FDatabaseInfo Value;
};
