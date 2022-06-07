// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAS_GAS_generated_h
#error "GAS.generated.h already included, missing '#pragma once' in GAS.h"
#endif
#define GAS_GAS_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAS_Source_GAS_GAS_h


#define FOREACH_ENUM_EGASABLITIYINPUTID(op) \
	op(EGASAblitiyInputID::None) \
	op(EGASAblitiyInputID::Confirm) \
	op(EGASAblitiyInputID::Cancel) \
	op(EGASAblitiyInputID::Punch) 

enum class EGASAblitiyInputID : uint8;
template<> GAS_API UEnum* StaticEnum<EGASAblitiyInputID>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
