// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/RPGItem.h"
#include "RPGSkillItem.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPGTEST_API URPGSkillItem : public URPGItem
{
	GENERATED_BODY()

public:
	URPGSkillItem() {
		ItemType = URPGAssetManager::SkillItemType;
	}
};
