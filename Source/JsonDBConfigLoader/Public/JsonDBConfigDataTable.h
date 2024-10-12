#pragma once
#include "DatabaseConfig.h"
#include "Engine/DataTable.h"

class JSONDBCONFIGLOADER_API FJsonDBConfigDataTable
{
public:
	static void AddRowToDataTable(UDataTable* DataTable, FString& RowName, const FDatabaseConfig& DatabaseConfig);
	void RemoveRowFromDataTable(UDataTable* DataTable, FString& RowName);
};
