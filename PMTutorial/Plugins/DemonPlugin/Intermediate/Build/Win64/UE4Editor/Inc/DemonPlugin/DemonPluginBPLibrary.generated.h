// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DEMONPLUGIN_DemonPluginBPLibrary_generated_h
#error "DemonPluginBPLibrary.generated.h already included, missing '#pragma once' in DemonPluginBPLibrary.h"
#endif
#define DEMONPLUGIN_DemonPluginBPLibrary_generated_h

#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_SPARSE_DATA
#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTestOpenSqlite); \
	DECLARE_FUNCTION(execTestFunction); \
	DECLARE_FUNCTION(execDemonPluginSampleFunction);


#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTestOpenSqlite); \
	DECLARE_FUNCTION(execTestFunction); \
	DECLARE_FUNCTION(execDemonPluginSampleFunction);


#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDemonPluginBPLibrary(); \
	friend struct Z_Construct_UClass_UDemonPluginBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UDemonPluginBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DemonPlugin"), NO_API) \
	DECLARE_SERIALIZER(UDemonPluginBPLibrary)


#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUDemonPluginBPLibrary(); \
	friend struct Z_Construct_UClass_UDemonPluginBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UDemonPluginBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DemonPlugin"), NO_API) \
	DECLARE_SERIALIZER(UDemonPluginBPLibrary)


#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDemonPluginBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDemonPluginBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDemonPluginBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDemonPluginBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDemonPluginBPLibrary(UDemonPluginBPLibrary&&); \
	NO_API UDemonPluginBPLibrary(const UDemonPluginBPLibrary&); \
public:


#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDemonPluginBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDemonPluginBPLibrary(UDemonPluginBPLibrary&&); \
	NO_API UDemonPluginBPLibrary(const UDemonPluginBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDemonPluginBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDemonPluginBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDemonPluginBPLibrary)


#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET
#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_25_PROLOG
#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_SPARSE_DATA \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_RPC_WRAPPERS \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_INCLASS \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_SPARSE_DATA \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
	PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class DemonPluginBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DEMONPLUGIN_API UClass* StaticClass<class UDemonPluginBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PMTutorial_Plugins_DemonPlugin_Source_DemonPlugin_Public_DemonPluginBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
