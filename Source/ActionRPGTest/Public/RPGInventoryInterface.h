// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ActionRPGTest.h"
#include "UObject/Interface.h"
#include "RPGInventoryInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class URPGInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPGTEST_API IRPGInventoryInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual const TMap<URPGItem*, FRPGItemData>& GetInventoryDataMap() const = 0;

	virtual const TMap<FRPGItemSlot, URPGItem*>& GetSlottedItemMap() const = 0;

	virtual FOnInventoryItemChangedNative& GetInventoryItemChangedDelegate() = 0;

	virtual FOnSlottedItemChangedNative& GetSlottedItemChangedDelegate() = 0;

	virtual FOnInventoryLoadedNative& GetInventoryLoadedDelegate() = 0;

};
