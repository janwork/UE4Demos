// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAS/GAS.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAS() {}
// Cross Module References
	GAS_API UEnum* Z_Construct_UEnum_GAS_EGASAblitiyInputID();
	UPackage* Z_Construct_UPackage__Script_GAS();
// End Cross Module References
	static UEnum* EGASAblitiyInputID_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_GAS_EGASAblitiyInputID, Z_Construct_UPackage__Script_GAS(), TEXT("EGASAblitiyInputID"));
		}
		return Singleton;
	}
	template<> GAS_API UEnum* StaticEnum<EGASAblitiyInputID>()
	{
		return EGASAblitiyInputID_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EGASAblitiyInputID(EGASAblitiyInputID_StaticEnum, TEXT("/Script/GAS"), TEXT("EGASAblitiyInputID"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_GAS_EGASAblitiyInputID_Hash() { return 1397441402U; }
	UEnum* Z_Construct_UEnum_GAS_EGASAblitiyInputID()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_GAS();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EGASAblitiyInputID"), 0, Get_Z_Construct_UEnum_GAS_EGASAblitiyInputID_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EGASAblitiyInputID::None", (int64)EGASAblitiyInputID::None },
				{ "EGASAblitiyInputID::Confirm", (int64)EGASAblitiyInputID::Confirm },
				{ "EGASAblitiyInputID::Cancel", (int64)EGASAblitiyInputID::Cancel },
				{ "EGASAblitiyInputID::Punch", (int64)EGASAblitiyInputID::Punch },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Cancel.Name", "EGASAblitiyInputID::Cancel" },
				{ "Comment", "/*\n* ???\xe5\xbc\xbc??\n*/" },
				{ "Confirm.Name", "EGASAblitiyInputID::Confirm" },
				{ "ModuleRelativePath", "GAS.h" },
				{ "None.Name", "EGASAblitiyInputID::None" },
				{ "Punch.Name", "EGASAblitiyInputID::Punch" },
				{ "ToolTip", "* ???\xe5\xbc\xbc??" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_GAS,
				nullptr,
				"EGASAblitiyInputID",
				"EGASAblitiyInputID",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
