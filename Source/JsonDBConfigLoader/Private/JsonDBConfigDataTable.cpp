#include "JsonDBConfigDataTable.h"

#include "GameplayTagsManager.h"
#include "JsonDBRow.h"

void FJsonDBConfigDataTable::AddRowToDataTable(UDataTable* DataTable, FString& RowName,
	const FDatabaseConfig& DatabaseConfig)
{
	if (!DataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable is null!"));
		return;
	}
	
	FJsonDBRow* ExistingRow = DataTable->FindRow<FJsonDBRow>(*RowName, TEXT("Lookup"));
	
	if(ExistingRow)
	{
		ExistingRow->JsonDBs = DatabaseConfig;
	}
	else
	{
		FJsonDBRow NewRow;
		NewRow.JsonDBs = DatabaseConfig;
		DataTable->AddRow(*RowName, NewRow);
	}
	
	DataTable->MarkPackageDirty();
}

void FJsonDBConfigDataTable::RemoveRowFromDataTable(UDataTable* DataTable, FString& RowName)
{
	if(DataTable->FindRow<FJsonDBRow>(*RowName, TEXT("Lookup")))
	{
		DataTable->RemoveRow(*RowName);
    	
		DataTable->MarkPackageDirty();
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Row with name %s not found in DataTable."), *RowName);
	}
}
