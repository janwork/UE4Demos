// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DemonPlugin/Public/DemonPluginBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDemonPluginBPLibrary() {}
// Cross Module References
	DEMONPLUGIN_API UClass* Z_Construct_UClass_UDemonPluginBPLibrary_NoRegister();
	DEMONPLUGIN_API UClass* Z_Construct_UClass_UDemonPluginBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_DemonPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UDemonPluginBPLibrary::execTestOpenSqlite)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UDemonPluginBPLibrary::TestOpenSqlite();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDemonPluginBPLibrary::execTestFunction)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UDemonPluginBPLibrary::TestFunction();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDemonPluginBPLibrary::execDemonPluginSampleFunction)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Param);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UDemonPluginBPLibrary::DemonPluginSampleFunction(Z_Param_Param);
		P_NATIVE_END;
	}
	void UDemonPluginBPLibrary::StaticRegisterNativesUDemonPluginBPLibrary()
	{
		UClass* Class = UDemonPluginBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DemonPluginSampleFunction", &UDemonPluginBPLibrary::execDemonPluginSampleFunction },
			{ "TestFunction", &UDemonPluginBPLibrary::execTestFunction },
			{ "TestOpenSqlite", &UDemonPluginBPLibrary::execTestOpenSqlite },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics
	{
		struct DemonPluginBPLibrary_eventDemonPluginSampleFunction_Parms
		{
			float Param;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Param;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DemonPluginBPLibrary_eventDemonPluginSampleFunction_Parms, Param), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DemonPluginBPLibrary_eventDemonPluginSampleFunction_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::NewProp_Param,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "DemonPluginTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "DemonPlugin sample test testing" },
		{ "ModuleRelativePath", "Public/DemonPluginBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDemonPluginBPLibrary, nullptr, "DemonPluginSampleFunction", nullptr, nullptr, sizeof(DemonPluginBPLibrary_eventDemonPluginSampleFunction_Parms), Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics
	{
		struct DemonPluginBPLibrary_eventTestFunction_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DemonPluginBPLibrary_eventTestFunction_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "Test" },
		{ "DisplayName", "Test If Library Works" },
		{ "ModuleRelativePath", "Public/DemonPluginBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDemonPluginBPLibrary, nullptr, "TestFunction", nullptr, nullptr, sizeof(DemonPluginBPLibrary_eventTestFunction_Parms), Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite_Statics::Function_MetaDataParams[] = {
		{ "Category", "Test" },
		{ "ModuleRelativePath", "Public/DemonPluginBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDemonPluginBPLibrary, nullptr, "TestOpenSqlite", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UDemonPluginBPLibrary_NoRegister()
	{
		return UDemonPluginBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UDemonPluginBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDemonPluginBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_DemonPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDemonPluginBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDemonPluginBPLibrary_DemonPluginSampleFunction, "DemonPluginSampleFunction" }, // 3303170825
		{ &Z_Construct_UFunction_UDemonPluginBPLibrary_TestFunction, "TestFunction" }, // 3420312477
		{ &Z_Construct_UFunction_UDemonPluginBPLibrary_TestOpenSqlite, "TestOpenSqlite" }, // 2092619327
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDemonPluginBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
		{ "IncludePath", "DemonPluginBPLibrary.h" },
		{ "ModuleRelativePath", "Public/DemonPluginBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDemonPluginBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDemonPluginBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDemonPluginBPLibrary_Statics::ClassParams = {
		&UDemonPluginBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDemonPluginBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDemonPluginBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDemonPluginBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDemonPluginBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDemonPluginBPLibrary, 3045014427);
	template<> DEMONPLUGIN_API UClass* StaticClass<UDemonPluginBPLibrary>()
	{
		return UDemonPluginBPLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDemonPluginBPLibrary(Z_Construct_UClass_UDemonPluginBPLibrary, &UDemonPluginBPLibrary::StaticClass, TEXT("/Script/DemonPlugin"), TEXT("UDemonPluginBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDemonPluginBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
