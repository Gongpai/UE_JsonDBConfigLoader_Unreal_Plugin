#include "JsonInfo.h"

FJsonInfo::FJsonInfo()
{
}

FJsonInfo::FJsonInfo(FFileInfo _key, FDatabaseInfo _value)
{
	Key = _key;
	Value = _value;
}
