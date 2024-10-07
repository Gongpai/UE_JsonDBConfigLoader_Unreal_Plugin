#pragma once

#include "CoreMinimal.h"
#include "DatabaseConfig.h"
#include "Engine/DataTable.h"
#include "JsonDBRow.generated.h"

USTRUCT(BlueprintType)
struct JSONDBCONFIGLOADER_API FJsonDBRow : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JsonDBRow")
	FDatabaseConfig JsonDBs;
};
