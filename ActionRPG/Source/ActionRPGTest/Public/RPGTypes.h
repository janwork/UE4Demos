// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "RPGSaveGame.h"
#include "UObject/PrimaryAssetId.h"
#include "RPGTypes.generated.h"

class URPGItem;
//class URPGSaveGame;


/**
 * 
 */
USTRUCT(BlueprintType)
struct ACTIONRPGTEST_API FRPGItemSlot
{
	GENERATED_BODY()

	FRPGItemSlot() : SlotNumber(-1) {

	}

	FRPGItemSlot(const FPrimaryAssetType& InItemType, int32 InSlotNumber):ItemType(InItemType), SlotNumber(InSlotNumber){}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		int32 SlotNumber;


	bool operator==(const FRPGItemSlot& Other) const {
		return ItemType == Other.ItemType && SlotNumber == Other.SlotNumber;
	}

	bool operator!=(const FRPGItemSlot& Other) const {
		return !(*this == Other);
	}

	friend inline uint32 GetTypeHash(const FRPGItemSlot& Key)
	{
		uint32 Hash = 0;

		Hash = HashCombine(Hash, GetTypeHash(Key.ItemType));
		Hash = HashCombine(Hash, (uint32)Key.SlotNumber);

		return Hash;
	}

	bool IsValid() const
	{
		return ItemType.IsValid() && SlotNumber >= 0;
	}

};


USTRUCT(BlueprintType)
struct ACTIONRPGTEST_API FRPGItemData
{
	GENERATED_BODY()

	FRPGItemData():ItemCount(1), ItemLevel(1){}

	FRPGItemData(int32 InItemCount, int32 InItemLevel) : ItemCount(InItemCount), ItemLevel(InItemLevel) {}


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		int32  ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		int32  ItemLevel;

	bool operator==(const FRPGItemData& Other) const {
		return ItemCount == Other.ItemCount && ItemLevel == Other.ItemLevel;
	}

	bool operator!=(const FRPGItemData& Other) const {
		return !(*this == Other);
	}

	bool IsValid() const
	{
		return ItemCount > 0;
	}

	void UpdateItemData(const FRPGItemData& Other, int32 MaxCount, int32 MaxLevel)
	{
		if (MaxCount <= 0)
		{
			MaxCount = MAX_int32;
		}

		if (MaxLevel <= 0)
		{
			MaxLevel = MAX_int32;
		}

		ItemCount = FMath::Clamp(ItemCount + Other.ItemCount, 1, MaxCount);
		ItemLevel = FMath::Clamp(Other.ItemLevel, 1, MaxLevel);
	}
};

//  ί���¼�
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemChanged, bool, bAdded, URPGItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemChangedNative, bool, URPGItem*);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSlottedItemChanged, FRPGItemSlot, ItemSlot, URPGItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSlottedItemChangedNative, FRPGItemSlot, URPGItem*);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryLoaded);
DECLARE_MULTICAST_DELEGATE(FOnInventoryLoadedNative);
//
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveGameLoaded, URPGSaveGame*, SaveGame);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSaveGameLoadedNative, URPGSaveGame*);