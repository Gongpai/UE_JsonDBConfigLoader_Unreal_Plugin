// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JsonDBConfigLoader/Public/FileInfo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFileInfo() {}
// Cross Module References
	JSONDBCONFIGLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FFileInfo();
	UPackage* Z_Construct_UPackage__Script_JsonDBConfigLoader();
// End Cross Module References
class UScriptStruct* FFileInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern JSONDBCONFIGLOADER_API uint32 Get_Z_Construct_UScriptStruct_FFileInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FFileInfo, Z_Construct_UPackage__Script_JsonDBConfigLoader(), TEXT("FileInfo"), sizeof(FFileInfo), Get_Z_Construct_UScriptStruct_FFileInfo_Hash());
	}
	return Singleton;
}
template<> JSONDBCONFIGLOADER_API UScriptStruct* StaticStruct<FFileInfo>()
{
	return FFileInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FFileInfo(FFileInfo::StaticStruct, TEXT("/Script/JsonDBConfigLoader"), TEXT("FileInfo"), false, nullptr, nullptr);
static struct FScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFFileInfo
{
	FScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFFileInfo()
	{
		UScriptStruct::DeferCppStructOps<FFileInfo>(FName(TEXT("FileInfo")));
	}
} ScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFFileInfo;
	struct Z_Construct_UScriptStruct_FFileInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FilePath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsLoad_MetaData[];
#endif
		static void NewProp_IsLoad_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsLoad;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsEdit_MetaData[];
#endif
		static void NewProp_IsEdit_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsEdit;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFileInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FileInfo.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFileInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFileInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FileName_MetaData[] = {
		{ "ModuleRelativePath", "Public/FileInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFileInfo, FileName), METADATA_PARAMS(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FileName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FileName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FilePath_MetaData[] = {
		{ "ModuleRelativePath", "Public/FileInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFileInfo, FilePath), METADATA_PARAMS(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FilePath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsLoad_MetaData[] = {
		{ "ModuleRelativePath", "Public/FileInfo.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsLoad_SetBit(void* Obj)
	{
		((FFileInfo*)Obj)->IsLoad = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsLoad = { "IsLoad", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FFileInfo), &Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsLoad_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsLoad_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsLoad_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsEdit_MetaData[] = {
		{ "ModuleRelativePath", "Public/FileInfo.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsEdit_SetBit(void* Obj)
	{
		((FFileInfo*)Obj)->IsEdit = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsEdit = { "IsEdit", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FFileInfo), &Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsEdit_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsEdit_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsEdit_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFileInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FileName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_FilePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsLoad,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFileInfo_Statics::NewProp_IsEdit,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFileInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_JsonDBConfigLoader,
		nullptr,
		&NewStructOps,
		"FileInfo",
		sizeof(FFileInfo),
		alignof(FFileInfo),
		Z_Construct_UScriptStruct_FFileInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FFileInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFileInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFileInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FFileInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_JsonDBConfigLoader();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("FileInfo"), sizeof(FFileInfo), Get_Z_Construct_UScriptStruct_FFileInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FFileInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FFileInfo_Hash() { return 2194993288U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
