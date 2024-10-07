#pragma once
#include "DatabaseConfig.h"

class FJsonDBConfigDataTable
{
public:
	static void AddRowToDataTable(UDataTable* DataTable, FString& RowName, const FDatabaseConfig& DatabaseConfig);
	void RemoveRowFromDataTable(UDataTable* DataTable, FString& RowName);
};
