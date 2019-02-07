// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameLab19/Public/Twitch.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTwitch() {}
// Cross Module References
	GAMELAB19_API UClass* Z_Construct_UClass_ATwitch_NoRegister();
	GAMELAB19_API UClass* Z_Construct_UClass_ATwitch();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GameLab19();
	GAMELAB19_API UFunction* Z_Construct_UFunction_ATwitch_Authentication();
	GAMELAB19_API UFunction* Z_Construct_UFunction_ATwitch_Connect();
	GAMELAB19_API UFunction* Z_Construct_UFunction_ATwitch_SendIRCMessage();
	GAMELAB19_API UFunction* Z_Construct_UFunction_ATwitch_SetInitialInfo();
// End Cross Module References
	void ATwitch::StaticRegisterNativesATwitch()
	{
		UClass* Class = ATwitch::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Authentication", &ATwitch::execAuthentication },
			{ "Connect", &ATwitch::execConnect },
			{ "SendIRCMessage", &ATwitch::execSendIRCMessage },
			{ "SetInitialInfo", &ATwitch::execSetInitialInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATwitch_Authentication_Statics
	{
		struct Twitch_eventAuthentication_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATwitch_Authentication_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Twitch_eventAuthentication_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATwitch_Authentication_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Twitch_eventAuthentication_Parms), &Z_Construct_UFunction_ATwitch_Authentication_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwitch_Authentication_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwitch_Authentication_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwitch_Authentication_Statics::Function_MetaDataParams[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "Public/Twitch.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwitch_Authentication_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATwitch, "Authentication", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Twitch_eventAuthentication_Parms), Z_Construct_UFunction_ATwitch_Authentication_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_Authentication_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATwitch_Authentication_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_Authentication_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATwitch_Authentication()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATwitch_Authentication_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATwitch_Connect_Statics
	{
		struct Twitch_eventConnect_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATwitch_Connect_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Twitch_eventConnect_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATwitch_Connect_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Twitch_eventConnect_Parms), &Z_Construct_UFunction_ATwitch_Connect_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwitch_Connect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwitch_Connect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwitch_Connect_Statics::Function_MetaDataParams[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "Public/Twitch.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwitch_Connect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATwitch, "Connect", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Twitch_eventConnect_Parms), Z_Construct_UFunction_ATwitch_Connect_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_Connect_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATwitch_Connect_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_Connect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATwitch_Connect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATwitch_Connect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics
	{
		struct Twitch_eventSendIRCMessage_Parms
		{
			FString _message;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp__message;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Twitch_eventSendIRCMessage_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Twitch_eventSendIRCMessage_Parms), &Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::NewProp__message = { UE4CodeGen_Private::EPropertyClass::Str, "_message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Twitch_eventSendIRCMessage_Parms, _message), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::NewProp__message,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "Public/Twitch.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATwitch, "SendIRCMessage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Twitch_eventSendIRCMessage_Parms), Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATwitch_SendIRCMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATwitch_SendIRCMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics
	{
		struct Twitch_eventSetInitialInfo_Parms
		{
			FString Oauth;
			FString Username;
			FString Channel;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Channel_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Channel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Username;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Oauth_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Oauth;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Channel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Channel = { UE4CodeGen_Private::EPropertyClass::Str, "Channel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(Twitch_eventSetInitialInfo_Parms, Channel), METADATA_PARAMS(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Channel_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Channel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Username_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Username = { UE4CodeGen_Private::EPropertyClass::Str, "Username", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(Twitch_eventSetInitialInfo_Parms, Username), METADATA_PARAMS(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Username_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Username_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Oauth_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Oauth = { UE4CodeGen_Private::EPropertyClass::Str, "Oauth", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(Twitch_eventSetInitialInfo_Parms, Oauth), METADATA_PARAMS(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Oauth_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Oauth_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Channel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Username,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::NewProp_Oauth,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "Public/Twitch.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATwitch, "SetInitialInfo", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Twitch_eventSetInitialInfo_Parms), Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATwitch_SetInitialInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATwitch_SetInitialInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATwitch_NoRegister()
	{
		return ATwitch::StaticClass();
	}
	struct Z_Construct_UClass_ATwitch_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATwitch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameLab19,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATwitch_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATwitch_Authentication, "Authentication" }, // 990535116
		{ &Z_Construct_UFunction_ATwitch_Connect, "Connect" }, // 2667645120
		{ &Z_Construct_UFunction_ATwitch_SendIRCMessage, "SendIRCMessage" }, // 882581737
		{ &Z_Construct_UFunction_ATwitch_SetInitialInfo, "SetInitialInfo" }, // 2819202320
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATwitch_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Twitch.h" },
		{ "ModuleRelativePath", "Public/Twitch.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATwitch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwitch>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATwitch_Statics::ClassParams = {
		&ATwitch::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ATwitch_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATwitch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATwitch()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATwitch_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATwitch, 1773387208);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATwitch(Z_Construct_UClass_ATwitch, &ATwitch::StaticClass, TEXT("/Script/GameLab19"), TEXT("ATwitch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATwitch);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
