// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAS_GASAbilitySystemComponent_generated_h
#error "GASAbilitySystemComponent.generated.h already included, missing '#pragma once' in GASAbilitySystemComponent.h"
#endif
#define GAS_GASAbilitySystemComponent_generated_h

#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_SPARSE_DATA
#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_RPC_WRAPPERS
#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGASAbilitySystemComponent(); \
	friend struct Z_Construct_UClass_UGASAbilitySystemComponent_Statics; \
public: \
	DECLARE_CLASS(UGASAbilitySystemComponent, UAbilitySystemComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAS"), NO_API) \
	DECLARE_SERIALIZER(UGASAbilitySystemComponent)


#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUGASAbilitySystemComponent(); \
	friend struct Z_Construct_UClass_UGASAbilitySystemComponent_Statics; \
public: \
	DECLARE_CLASS(UGASAbilitySystemComponent, UAbilitySystemComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAS"), NO_API) \
	DECLARE_SERIALIZER(UGASAbilitySystemComponent)


#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGASAbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGASAbilitySystemComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGASAbilitySystemComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGASAbilitySystemComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGASAbilitySystemComponent(UGASAbilitySystemComponent&&); \
	NO_API UGASAbilitySystemComponent(const UGASAbilitySystemComponent&); \
public:


#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGASAbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGASAbilitySystemComponent(UGASAbilitySystemComponent&&); \
	NO_API UGASAbilitySystemComponent(const UGASAbilitySystemComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGASAbilitySystemComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGASAbilitySystemComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGASAbilitySystemComponent)


#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_PRIVATE_PROPERTY_OFFSET
#define GAS_Source_GAS_GASAbilitySystemComponent_h_12_PROLOG
#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_SPARSE_DATA \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_RPC_WRAPPERS \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_INCLASS \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAS_Source_GAS_GASAbilitySystemComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_SPARSE_DATA \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_INCLASS_NO_PURE_DECLS \
	GAS_Source_GAS_GASAbilitySystemComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAS_API UClass* StaticClass<class UGASAbilitySystemComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAS_Source_GAS_GASAbilitySystemComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
