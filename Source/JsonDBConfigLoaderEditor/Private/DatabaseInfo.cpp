#include "DatabaseInfo.h"

FDatabaseInfo::FDatabaseInfo()
{
}

FDatabaseInfo::FDatabaseInfo(FString hostname, FString username, FString password, FString port, FString databaseName)
{
	Hostname = hostname;
	Username = username;
	Password = password;
	Port = port;
	DatabaseName = databaseName;
	BaseHostname = hostname;
	BaseUsername = username;
	BasePassword = password;
	BasePort = port;
	BaseDatabaseName = databaseName;
}

void FDatabaseInfo::SetHostname(FString hostname)
{
	Hostname = hostname;
	BaseHostname = hostname;
}

FString FDatabaseInfo::GetHostname() 
{
	return Hostname;
}

void FDatabaseInfo::SetUsername( FString username) 
{
	Username = username;
	BaseUsername = username;
}

FString FDatabaseInfo::GetUsername() 
{
	return Username;
}

void FDatabaseInfo::SetPassword( FString password) 
{

	Password = password;
	BasePassword = password;
}

FString FDatabaseInfo::GetPassword() 
{
	return Password;
}

void FDatabaseInfo::SetPort( FString port) 
{
	Port = port;
	BasePort = port;
}

FString FDatabaseInfo::GetPort() 
{
	return Port;
}

void FDatabaseInfo::SetDatabaseName( FString databaseName) 
{
	DatabaseName = databaseName;
	BaseDatabaseName = databaseName;
}

FString FDatabaseInfo::GetDatabaseName() 
{
	return DatabaseName;
}

bool FDatabaseInfo::CheckDataInfo(FDatabaseInfo DatabaseInfo)
{
	return DatabaseInfo.Hostname == BaseHostname 
	&& DatabaseInfo.Username == BaseUsername 
	&& DatabaseInfo.Password == BasePassword
	&& DatabaseInfo.Port == BasePort
	&& DatabaseInfo.DatabaseName == BaseDatabaseName;
}

void FDatabaseInfo::ApplyBaseDataInfo()
{
	BaseHostname = Hostname;
	BaseUsername = Username;
	BasePassword = Password;
	BasePort = Port;
	BaseDatabaseName = DatabaseName;
}
