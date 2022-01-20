// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ActionRPGTest.h"
#include "Engine/DataAsset.h"
//#include "Styling/SlateBrush.h"
#include "Abilities/RPGGameplayAbility.h"
#include "RPGAssetManager.h"
#include "RPGItem.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class ACTIONRPGTEST_API URPGItem : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	URPGItem():Price(0), MaxCount(1), MaxLevel(1),AbilityLevel(1) {}


	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Item)
		FPrimaryAssetType ItemType;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Item)
		FText ItemName;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Item)
		FText ItemDescription;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	//	FSlateBrush ItemIcon;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Item)
		int32 Price;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Max)
		int32 MaxCount;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Max)
		int32 MaxLevel;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Abilities)
		TSubclassOf<URPGGameplayAbility> GrantedAbility;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Abilities)
		int32 AbilityLevel;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Max)
		bool IsConSumable() const;

	UFUNCTION(BlueprintCallable, Category = Item)
		FString GetIdentifierString() const;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

};
