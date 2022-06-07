// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LearnWebSocket/LearnWebSocketGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLearnWebSocketGameMode() {}
// Cross Module References
	LEARNWEBSOCKET_API UClass* Z_Construct_UClass_ALearnWebSocketGameMode_NoRegister();
	LEARNWEBSOCKET_API UClass* Z_Construct_UClass_ALearnWebSocketGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_LearnWebSocket();
// End Cross Module References
	void ALearnWebSocketGameMode::StaticRegisterNativesALearnWebSocketGameMode()
	{
	}
	UClass* Z_Construct_UClass_ALearnWebSocketGameMode_NoRegister()
	{
		return ALearnWebSocketGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ALearnWebSocketGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALearnWebSocketGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LearnWebSocket,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALearnWebSocketGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LearnWebSocketGameMode.h" },
		{ "ModuleRelativePath", "LearnWebSocketGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALearnWebSocketGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALearnWebSocketGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALearnWebSocketGameMode_Statics::ClassParams = {
		&ALearnWebSocketGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ALearnWebSocketGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALearnWebSocketGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALearnWebSocketGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALearnWebSocketGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALearnWebSocketGameMode, 3666457509);
	template<> LEARNWEBSOCKET_API UClass* StaticClass<ALearnWebSocketGameMode>()
	{
		return ALearnWebSocketGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALearnWebSocketGameMode(Z_Construct_UClass_ALearnWebSocketGameMode, &ALearnWebSocketGameMode::StaticClass, TEXT("/Script/LearnWebSocket"), TEXT("ALearnWebSocketGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALearnWebSocketGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
