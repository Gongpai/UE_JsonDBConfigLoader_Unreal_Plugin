// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JsonDBConfigLoader/Public/JsonDBConfigLoaderManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJsonDBConfigLoaderManager() {}
// Cross Module References
	JSONDBCONFIGLOADER_API UClass* Z_Construct_UClass_UJsonDBConfigLoaderManager_NoRegister();
	JSONDBCONFIGLOADER_API UClass* Z_Construct_UClass_UJsonDBConfigLoaderManager();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_JsonDBConfigLoader();
	JSONDBCONFIGLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FJsonInfo();
// End Cross Module References
	void UJsonDBConfigLoaderManager::StaticRegisterNativesUJsonDBConfigLoaderManager()
	{
	}
	UClass* Z_Construct_UClass_UJsonDBConfigLoaderManager_NoRegister()
	{
		return UJsonDBConfigLoaderManager::StaticClass();
	}
	struct Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DatabaseInfos_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DatabaseInfos_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DatabaseInfos_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_DatabaseInfos;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_JsonDBConfigLoader,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "JsonDBConfigLoaderManager.h" },
		{ "ModuleRelativePath", "Public/JsonDBConfigLoaderManager.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos_ValueProp = { "DatabaseInfos", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FJsonInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos_Key_KeyProp = { "DatabaseInfos_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos_MetaData[] = {
		{ "ModuleRelativePath", "Public/JsonDBConfigLoaderManager.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos = { "DatabaseInfos", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UJsonDBConfigLoaderManager, DatabaseInfos), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::NewProp_DatabaseInfos,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJsonDBConfigLoaderManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::ClassParams = {
		&UJsonDBConfigLoaderManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UJsonDBConfigLoaderManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UJsonDBConfigLoaderManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UJsonDBConfigLoaderManager, 2915240249);
	template<> JSONDBCONFIGLOADER_API UClass* StaticClass<UJsonDBConfigLoaderManager>()
	{
		return UJsonDBConfigLoaderManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UJsonDBConfigLoaderManager(Z_Construct_UClass_UJsonDBConfigLoaderManager, &UJsonDBConfigLoaderManager::StaticClass, TEXT("/Script/JsonDBConfigLoader"), TEXT("UJsonDBConfigLoaderManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UJsonDBConfigLoaderManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
