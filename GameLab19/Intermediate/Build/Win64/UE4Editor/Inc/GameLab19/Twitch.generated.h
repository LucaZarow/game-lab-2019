// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMELAB19_Twitch_generated_h
#error "Twitch.generated.h already included, missing '#pragma once' in Twitch.h"
#endif
#define GAMELAB19_Twitch_generated_h

#define GameLab19_Source_GameLab19_Public_Twitch_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSendIRCMessage) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param__message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SendIRCMessage(Z_Param__message); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAuthentication) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Authentication(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Connect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInitialInfo) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Oauth); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Username); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Channel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetInitialInfo(Z_Param_Oauth,Z_Param_Username,Z_Param_Channel); \
		P_NATIVE_END; \
	}


#define GameLab19_Source_GameLab19_Public_Twitch_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSendIRCMessage) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param__message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SendIRCMessage(Z_Param__message); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAuthentication) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Authentication(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Connect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetInitialInfo) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Oauth); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Username); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Channel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetInitialInfo(Z_Param_Oauth,Z_Param_Username,Z_Param_Channel); \
		P_NATIVE_END; \
	}


#define GameLab19_Source_GameLab19_Public_Twitch_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATwitch(); \
	friend struct Z_Construct_UClass_ATwitch_Statics; \
public: \
	DECLARE_CLASS(ATwitch, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameLab19"), NO_API) \
	DECLARE_SERIALIZER(ATwitch)


#define GameLab19_Source_GameLab19_Public_Twitch_h_16_INCLASS \
private: \
	static void StaticRegisterNativesATwitch(); \
	friend struct Z_Construct_UClass_ATwitch_Statics; \
public: \
	DECLARE_CLASS(ATwitch, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameLab19"), NO_API) \
	DECLARE_SERIALIZER(ATwitch)


#define GameLab19_Source_GameLab19_Public_Twitch_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATwitch(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATwitch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATwitch); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATwitch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATwitch(ATwitch&&); \
	NO_API ATwitch(const ATwitch&); \
public:


#define GameLab19_Source_GameLab19_Public_Twitch_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATwitch(ATwitch&&); \
	NO_API ATwitch(const ATwitch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATwitch); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATwitch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATwitch)


#define GameLab19_Source_GameLab19_Public_Twitch_h_16_PRIVATE_PROPERTY_OFFSET
#define GameLab19_Source_GameLab19_Public_Twitch_h_13_PROLOG
#define GameLab19_Source_GameLab19_Public_Twitch_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_PRIVATE_PROPERTY_OFFSET \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_RPC_WRAPPERS \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_INCLASS \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameLab19_Source_GameLab19_Public_Twitch_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_PRIVATE_PROPERTY_OFFSET \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_INCLASS_NO_PURE_DECLS \
	GameLab19_Source_GameLab19_Public_Twitch_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameLab19_Source_GameLab19_Public_Twitch_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
