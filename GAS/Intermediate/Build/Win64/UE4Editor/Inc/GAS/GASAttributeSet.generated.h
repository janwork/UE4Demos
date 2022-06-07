// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Net/Core/PushModel/PushModelMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayAttributeData;
#ifdef GAS_GASAttributeSet_generated_h
#error "GASAttributeSet.generated.h already included, missing '#pragma once' in GASAttributeSet.h"
#endif
#define GAS_GASAttributeSet_generated_h

#define GAS_Source_GAS_GASAttributeSet_h_25_SPARSE_DATA
#define GAS_Source_GAS_GASAttributeSet_h_25_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnRep_AttackPower); \
	DECLARE_FUNCTION(execOnRep_Stamina); \
	DECLARE_FUNCTION(execOnRep_Health);


#define GAS_Source_GAS_GASAttributeSet_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_AttackPower); \
	DECLARE_FUNCTION(execOnRep_Stamina); \
	DECLARE_FUNCTION(execOnRep_Health);


#define GAS_Source_GAS_GASAttributeSet_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGASAttributeSet(); \
	friend struct Z_Construct_UClass_UGASAttributeSet_Statics; \
public: \
	DECLARE_CLASS(UGASAttributeSet, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GAS"), NO_API) \
	DECLARE_SERIALIZER(UGASAttributeSet) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		Stamina, \
		AttackPower, \
		NETFIELD_REP_END=AttackPower	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override; \
private: \
	REPLICATED_BASE_CLASS(UGASAttributeSet) \
public:


#define GAS_Source_GAS_GASAttributeSet_h_25_INCLASS \
private: \
	static void StaticRegisterNativesUGASAttributeSet(); \
	friend struct Z_Construct_UClass_UGASAttributeSet_Statics; \
public: \
	DECLARE_CLASS(UGASAttributeSet, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GAS"), NO_API) \
	DECLARE_SERIALIZER(UGASAttributeSet) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		Stamina, \
		AttackPower, \
		NETFIELD_REP_END=AttackPower	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override; \
private: \
	REPLICATED_BASE_CLASS(UGASAttributeSet) \
public:


#define GAS_Source_GAS_GASAttributeSet_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGASAttributeSet(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGASAttributeSet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGASAttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGASAttributeSet); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGASAttributeSet(UGASAttributeSet&&); \
	NO_API UGASAttributeSet(const UGASAttributeSet&); \
public:


#define GAS_Source_GAS_GASAttributeSet_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGASAttributeSet(UGASAttributeSet&&); \
	NO_API UGASAttributeSet(const UGASAttributeSet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGASAttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGASAttributeSet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGASAttributeSet)


#define GAS_Source_GAS_GASAttributeSet_h_25_PRIVATE_PROPERTY_OFFSET
#define GAS_Source_GAS_GASAttributeSet_h_22_PROLOG
#define GAS_Source_GAS_GASAttributeSet_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASAttributeSet_h_25_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASAttributeSet_h_25_SPARSE_DATA \
	GAS_Source_GAS_GASAttributeSet_h_25_RPC_WRAPPERS \
	GAS_Source_GAS_GASAttributeSet_h_25_INCLASS \
	GAS_Source_GAS_GASAttributeSet_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAS_Source_GAS_GASAttributeSet_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAS_Source_GAS_GASAttributeSet_h_25_PRIVATE_PROPERTY_OFFSET \
	GAS_Source_GAS_GASAttributeSet_h_25_SPARSE_DATA \
	GAS_Source_GAS_GASAttributeSet_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	GAS_Source_GAS_GASAttributeSet_h_25_INCLASS_NO_PURE_DECLS \
	GAS_Source_GAS_GASAttributeSet_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAS_API UClass* StaticClass<class UGASAttributeSet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAS_Source_GAS_GASAttributeSet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
