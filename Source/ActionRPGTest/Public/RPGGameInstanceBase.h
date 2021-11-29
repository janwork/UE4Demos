// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RPGGameInstanceBase.generated.h"
/**
 * 
 */
UCLASS()
class ACTIONRPGTEST_API URPGGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

public:

	URPGGameInstanceBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
		TMap<FPrimaryAssetType, int32> ItemSlotsPerType;
	
};
