#pragma once

#include "DatabaseConfig.generated.h"

USTRUCT(BlueprintType)
struct JSONDBCONFIGLOADER_API FDatabaseConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString Hostname;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString Username;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString Password;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString Port;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString DatabaseName;
};