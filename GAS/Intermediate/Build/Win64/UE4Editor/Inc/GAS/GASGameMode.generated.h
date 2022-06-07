// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAS_GASGameMode_generated_h
#error "GASGameMode.generated.h already included, missing '#pragma once' in GASGameMode.h"
#endif
#define GAS_GASGameMode_generated_h

#define GAS_Source_GAS_GASGameMode_h_12_SPARSE_DATA
#define GAS_Source_GAS_GASGameMode_h_12_RPC_WRAPPERS
#define GAS_Source_GAS_GASGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define GAS_Source_GAS_GASGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGASGameMode(); \
	friend struct Z_Construct_UClass_AGASGameMode_Statics; \
public: \
	DECLARE_CLASS(AGASGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAS"), GAS_API) \
	DECLARE_SERIALIZER(AGASGameMode)


#define GAS_Source_GAS_GASGameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGASGameMode(); \
	friend struct Z_Construct_UClass_AGASGameMode_Statics; \
public: \
	DECLARE_CLASS(AGASGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAS"), GAS_API) \
	DECLARE_SERIALIZER(AGASGameMode)


#define GAS_Source_GAS_GASGameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GAS_API AGASGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGASGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GAS_API, AGASGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGASGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	GAS_API AGASGameMode(AGASGameMode&&); \
	GAS_API AGASGameMode(const AGASGameMode&); \
public:


#define GAS_Source_GAS_GASGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	GAS_API AGASGameMode(AGASGameMode&&); \
	GAS_API AGASGameMode(const AGASGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GAS_API, AGASGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGASGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGASGameMode)


#define GAS_Source_GAS_GASGameMode_h_12_PRIVATE_PROPERTY_OFFSET
#define GAS_Source_GAS_GASGameMode_h_9_PROLOG
#define GAS_Source_GAS_GASGameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASGameMode_h_12_SPARSE_DATA \
	GAS_Source_GAS_GASGameMode_h_12_RPC_WRAPPERS \
	GAS_Source_GAS_GASGameMode_h_12_INCLASS \
	GAS_Source_GAS_GASGameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAS_Source_GAS_GASGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASGameMode_h_12_SPARSE_DATA \
	GAS_Source_GAS_GASGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	GAS_Source_GAS_GASGameMode_h_12_INCLASS_NO_PURE_DECLS \
	GAS_Source_GAS_GASGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAS_API UClass* StaticClass<class AGASGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAS_Source_GAS_GASGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
