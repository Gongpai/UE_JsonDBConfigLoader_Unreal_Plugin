#include "FileInfo.h"

FFileInfo::FFileInfo()
{

}

FFileInfo::FFileInfo(const FString& fileName, const FString& filePath, bool isLoad, bool isEdit)
	: FileName(fileName), FilePath(filePath), IsLoad(isLoad), IsEdit(isEdit)
{
	
}

void FFileInfo::SetFileName(FString fileName)
{
	FileName = fileName;
}

FString FFileInfo::GetFileName()
{
	return FileName;
}

void FFileInfo::SetFilePath(FString filePath)
{
	FilePath = filePath;
}

FString FFileInfo::GetFilePath()
{
	return FilePath;
}

void FFileInfo::SetIsLoad(bool isLoad)
{
	IsLoad = isLoad;
}

bool FFileInfo::GetIsLoad()
{
	return IsLoad;
}

void FFileInfo::SetIsEdit(bool isEdit)
{
	IsEdit = isEdit;
}

bool FFileInfo::GetIsEdit()
{
	return IsEdit;
}

bool FFileInfo::IsEmpty()
{
	return FileName.IsEmpty() && FilePath.IsEmpty();
}
