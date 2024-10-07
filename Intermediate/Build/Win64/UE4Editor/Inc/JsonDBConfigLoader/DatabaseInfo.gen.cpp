// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JsonDBConfigLoader/Public/DatabaseInfo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDatabaseInfo() {}
// Cross Module References
	JSONDBCONFIGLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FDatabaseInfo();
	UPackage* Z_Construct_UPackage__Script_JsonDBConfigLoader();
// End Cross Module References
class UScriptStruct* FDatabaseInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern JSONDBCONFIGLOADER_API uint32 Get_Z_Construct_UScriptStruct_FDatabaseInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FDatabaseInfo, Z_Construct_UPackage__Script_JsonDBConfigLoader(), TEXT("DatabaseInfo"), sizeof(FDatabaseInfo), Get_Z_Construct_UScriptStruct_FDatabaseInfo_Hash());
	}
	return Singleton;
}
template<> JSONDBCONFIGLOADER_API UScriptStruct* StaticStruct<FDatabaseInfo>()
{
	return FDatabaseInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FDatabaseInfo(FDatabaseInfo::StaticStruct, TEXT("/Script/JsonDBConfigLoader"), TEXT("DatabaseInfo"), false, nullptr, nullptr);
static struct FScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFDatabaseInfo
{
	FScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFDatabaseInfo()
	{
		UScriptStruct::DeferCppStructOps<FDatabaseInfo>(FName(TEXT("DatabaseInfo")));
	}
} ScriptStruct_JsonDBConfigLoader_StaticRegisterNativesFDatabaseInfo;
	struct Z_Construct_UScriptStruct_FDatabaseInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hostname_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Hostname;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Username;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Password;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Port_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Port;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DatabaseName_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_DatabaseName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDatabaseInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DatabaseInfo.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDatabaseInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Hostname_MetaData[] = {
		{ "ModuleRelativePath", "Public/DatabaseInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Hostname = { "Hostname", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDatabaseInfo, Hostname), METADATA_PARAMS(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Hostname_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Hostname_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Username_MetaData[] = {
		{ "ModuleRelativePath", "Public/DatabaseInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDatabaseInfo, Username), METADATA_PARAMS(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Username_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Username_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Password_MetaData[] = {
		{ "ModuleRelativePath", "Public/DatabaseInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDatabaseInfo, Password), METADATA_PARAMS(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Password_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Password_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Port_MetaData[] = {
		{ "ModuleRelativePath", "Public/DatabaseInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDatabaseInfo, Port), METADATA_PARAMS(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Port_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Port_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_DatabaseName_MetaData[] = {
		{ "ModuleRelativePath", "Public/DatabaseInfo.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_DatabaseName = { "DatabaseName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDatabaseInfo, DatabaseName), METADATA_PARAMS(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_DatabaseName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_DatabaseName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDatabaseInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Hostname,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Username,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Password,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_Port,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDatabaseInfo_Statics::NewProp_DatabaseName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDatabaseInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_JsonDBConfigLoader,
		nullptr,
		&NewStructOps,
		"DatabaseInfo",
		sizeof(FDatabaseInfo),
		alignof(FDatabaseInfo),
		Z_Construct_UScriptStruct_FDatabaseInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDatabaseInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FDatabaseInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FDatabaseInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_JsonDBConfigLoader();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("DatabaseInfo"), sizeof(FDatabaseInfo), Get_Z_Construct_UScriptStruct_FDatabaseInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FDatabaseInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FDatabaseInfo_Hash() { return 3707604669U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
