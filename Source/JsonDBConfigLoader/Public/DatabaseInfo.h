#pragma once
#include "DatabaseConfig.h"
#include "DatabaseInfo.generated.h"

USTRUCT(BlueprintType)
struct JSONDBCONFIGLOADER_API FDatabaseInfo : public FDatabaseConfig
{
	GENERATED_BODY()

public:
	FDatabaseInfo();
	FDatabaseInfo(FString hostname, FString username, FString password, FString port, FString databaseName);

	void SetHostname( FString hostname);
	FString GetHostname() ;
	
	void SetUsername( FString username) ;
	FString GetUsername() ;
	
	void SetPassword( FString password) ;
	FString GetPassword() ;
	
	void SetPort( FString port) ;
	FString GetPort() ;
	
	void SetDatabaseName( FString databaseName) ;
	FString GetDatabaseName() ;
	
	bool CheckDataInfo(FDatabaseInfo DatabaseInfo);
	
	void ApplyBaseDataInfo();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString BaseHostname;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString BaseUsername;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString BasePassword;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString BasePort;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DatabaseConfig")
	FString BaseDatabaseName;

	friend FArchive& operator<<(FArchive& Ar, FDatabaseInfo& DatabaseInfoStruct)
	{
		Ar << DatabaseInfoStruct.Hostname;
		Ar << DatabaseInfoStruct.Username;
		Ar << DatabaseInfoStruct.Password;
		Ar << DatabaseInfoStruct.Port;
		Ar << DatabaseInfoStruct.DatabaseName;
		return Ar;
	}
};
