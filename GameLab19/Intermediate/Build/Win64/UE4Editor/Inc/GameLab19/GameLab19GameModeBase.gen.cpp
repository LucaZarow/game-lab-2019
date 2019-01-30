// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameLab19/GameLab19GameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameLab19GameModeBase() {}
// Cross Module References
	GAMELAB19_API UClass* Z_Construct_UClass_AGameLab19GameModeBase_NoRegister();
	GAMELAB19_API UClass* Z_Construct_UClass_AGameLab19GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_GameLab19();
// End Cross Module References
	void AGameLab19GameModeBase::StaticRegisterNativesAGameLab19GameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AGameLab19GameModeBase_NoRegister()
	{
		return AGameLab19GameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AGameLab19GameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameLab19GameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameLab19,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameLab19GameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GameLab19GameModeBase.h" },
		{ "ModuleRelativePath", "GameLab19GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameLab19GameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameLab19GameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameLab19GameModeBase_Statics::ClassParams = {
		&AGameLab19GameModeBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A8u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGameLab19GameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGameLab19GameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameLab19GameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameLab19GameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameLab19GameModeBase, 2459867713);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameLab19GameModeBase(Z_Construct_UClass_AGameLab19GameModeBase, &AGameLab19GameModeBase::StaticClass, TEXT("/Script/GameLab19"), TEXT("AGameLab19GameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameLab19GameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
