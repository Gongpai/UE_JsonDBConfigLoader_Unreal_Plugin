// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JsonDBConfigLoader/Public/JsonInfo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJsonInfo() {}
// Cross Module References
	JSONDBCONFIGLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FJsonInfo();
	UPackage* Z_Construct_UPackage__Script_JsonDBConfigLoader();
	JSONDBCONFIGLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FFileInfo();
	JSONDBCONFIGLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FDatabaseInfo();
// End Cross Module References
class UScriptStruct* FJsonInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern JSONDBCONFIGLOADER_API uint32 Get_Z_Construct_UScriptStruct_FJsonInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FJsonInfo, Z_Construct_UPackage__Script_JsonDBConfigLoader(), TEXT("JsonInfo"), sizeof(FJsonInfo), Get_Z_Construct_UScriptStruct_FJsonInfo_Hash());
	}
	return Singleton;
}
template<> JSONDBCONFIGLOADER_API UScriptStruct* StaticStruct<FJsonInfo>()
{
	return FJsonInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FJsonInfo(FJsonInfo::StaticStruct, TEXT("/Script/JsonDBConfigLoader"), TEXT("JsonInfo"), false, nullptr, nullptr);
static struct FScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFJsonInfo
{
	FScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFJsonInfo()
	{
		UScriptStruct::DeferCppStructOps<FJsonInfo>(FName(TEXT("JsonInfo")));
	}
} ScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFJsonInfo;
	struct Z_Construct_UScriptStruct_FJsonInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Key;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FJsonInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JsonInfo.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FJsonInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJsonInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Key_MetaData[] = {
		{ "ModuleRelativePath", "Public/JsonInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FJsonInfo, Key), Z_Construct_UScriptStruct_FFileInfo, METADATA_PARAMS(Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Key_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Key_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Value_MetaData[] = {
		{ "ModuleRelativePath", "Public/JsonInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FJsonInfo, Value), Z_Construct_UScriptStruct_FDatabaseInfo, METADATA_PARAMS(Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJsonInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Key,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJsonInfo_Statics::NewProp_Value,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJsonInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_JsonDBConfigLoader,
		nullptr,
		&NewStructOps,
		"JsonInfo",
		sizeof(FJsonInfo),
		alignof(FJsonInfo),
		Z_Construct_UScriptStruct_FJsonInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJsonInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FJsonInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJsonInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FJsonInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FJsonInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_JsonDBConfigLoader();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("JsonInfo"), sizeof(FJsonInfo), Get_Z_Construct_UScriptStruct_FJsonInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FJsonInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FJsonInfo_Hash() { return 1009614468U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
