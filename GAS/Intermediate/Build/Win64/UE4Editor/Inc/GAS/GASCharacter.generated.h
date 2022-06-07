// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAS_GASCharacter_generated_h
#error "GASCharacter.generated.h already included, missing '#pragma once' in GASCharacter.h"
#endif
#define GAS_GASCharacter_generated_h

#define GAS_Source_GAS_GASCharacter_h_14_SPARSE_DATA
#define GAS_Source_GAS_GASCharacter_h_14_RPC_WRAPPERS
#define GAS_Source_GAS_GASCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define GAS_Source_GAS_GASCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGASCharacter(); \
	friend struct Z_Construct_UClass_AGASCharacter_Statics; \
public: \
	DECLARE_CLASS(AGASCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAS"), NO_API) \
	DECLARE_SERIALIZER(AGASCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AGASCharacter*>(this); }


#define GAS_Source_GAS_GASCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAGASCharacter(); \
	friend struct Z_Construct_UClass_AGASCharacter_Statics; \
public: \
	DECLARE_CLASS(AGASCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAS"), NO_API) \
	DECLARE_SERIALIZER(AGASCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AGASCharacter*>(this); }


#define GAS_Source_GAS_GASCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGASCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGASCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGASCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGASCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGASCharacter(AGASCharacter&&); \
	NO_API AGASCharacter(const AGASCharacter&); \
public:


#define GAS_Source_GAS_GASCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGASCharacter(AGASCharacter&&); \
	NO_API AGASCharacter(const AGASCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGASCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGASCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGASCharacter)


#define GAS_Source_GAS_GASCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AGASCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AGASCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__AbilitySystemComponenet() { return STRUCT_OFFSET(AGASCharacter, AbilitySystemComponenet); } \
	FORCEINLINE static uint32 __PPO__Attributes() { return STRUCT_OFFSET(AGASCharacter, Attributes); }


#define GAS_Source_GAS_GASCharacter_h_11_PROLOG
#define GAS_Source_GAS_GASCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASCharacter_h_14_SPARSE_DATA \
	GAS_Source_GAS_GASCharacter_h_14_RPC_WRAPPERS \
	GAS_Source_GAS_GASCharacter_h_14_INCLASS \
	GAS_Source_GAS_GASCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAS_Source_GAS_GASCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASCharacter_h_14_SPARSE_DATA \
	GAS_Source_GAS_GASCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	GAS_Source_GAS_GASCharacter_h_14_INCLASS_NO_PURE_DECLS \
	GAS_Source_GAS_GASCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAS_API UClass* StaticClass<class AGASCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAS_Source_GAS_GASCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
