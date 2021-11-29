// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGInventoryInterface.h"
#include "RPGTypes.h"
#include "Item/RPGItem.h"
#include "../ActionRPGTest.h"
#include "RPGPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPGTEST_API ARPGPlayerControllerBase : public APlayerController, public IRPGInventoryInterface
{
	GENERATED_BODY()

public:

	ARPGPlayerControllerBase();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
		TMap<URPGItem*, FRPGItemData> InventoryData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
		TMap<FRPGItemSlot, URPGItem*> SlottedItems;

	UPROPERTY(BlueprintAssignable, Category = Inventory)
		FOnInventoryItemChanged OnInventoryItemChanged;

	FOnInventoryItemChangedNative OnInventoryItemChangedNative;

	UPROPERTY(BlueprintAssignable, Category = Inventory)
		FOnSlottedItemChanged OnSlottedItemChanged;

	FOnSlottedItemChangedNative OnSlottedItemChangedNative;

	UPROPERTY(BlueprintAssignable, Category = Inventory)
		FOnInventoryLoaded OnInventoryLoaded;


	FOnInventoryLoadedNative OnInventoryLoadedNative;

	UFUNCTION(BlueprintCallable, Category = Inventory)
		bool AddInventoryItem(URPGItem* NewItem, int32 ItemCount = 1, int32 ItemLevel = 1, bool  bAutoSlot = true);
	
	UFUNCTION(BlueprintCallable, Category = Inventory)
		bool RemoveInventoryItem(URPGItem* RemoveItem,  int32 RemoveCount = 1);

	UFUNCTION(BlueprintCallable, Category = Inventory)
		void GetInventoryItems(TArray<URPGItem*>& Items, FPrimaryAssetType ItemType);
	
	UFUNCTION(BlueprintCallable, Category = Inventory)
		int32 GetInventoryItemCount(URPGItem* Item) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
		bool GetInventoryItemData(URPGItem* Item, FRPGItemData & ItemData) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
		bool SetSlottedItem(FRPGItemSlot ItemSlot, URPGItem* Item);

	UFUNCTION(BlueprintCallable, Category = Inventory)
		URPGItem* GetSlottedItem(FRPGItemSlot ItemSlot) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
		void GetSlottedItems(TArray<URPGItem*>& Items, FPrimaryAssetType ItemType, bool bOutputEmptyIndexes);

	UFUNCTION(BlueprintCallable, Category = Inventory)
		void FillEmptySlots();

	UFUNCTION(BlueprintCallable, Category = Inventory)
		bool SaveInventory();

	UFUNCTION(BlueprintCallable, Category = Inventory)
		bool LoadInventory();

	UFUNCTION(BlueprintImplementableEvent, Category = Inventory)
		void InventoryItemChanged(bool bAdded, URPGItem* Item);

	UFUNCTION(BlueprintImplementableEvent, Category = Inventory)
		void SlottedItemChanged(FRPGItemSlot ItemSlot, URPGItem* Item);

	virtual const TMap<URPGItem*, FRPGItemData>& GetInventoryDataMap() const override 
	{
		return InventoryData;
	}

	virtual const TMap<FRPGItemSlot, URPGItem*>& GetSlottedItemMap() const override
	{
		return SlottedItems;
	}


	virtual FOnInventoryItemChangedNative& GetInventoryItemChangedDelegate() override
	{
		return OnInventoryItemChangedNative;
	}


	virtual FOnInventoryLoadedNative& GetInventoryLoadedDelegate() override
	{
		return OnInventoryLoadedNative;
	}


	virtual FOnSlottedItemChangedNative& GetSlottedItemChangedDelegate() override
	{
		return OnSlottedItemChangedNative;
	}


protected:

	bool FillEmptySlotWithItem(URPGItem* NewItem);


	void NotifyInventoryItemChanged(bool bAdded, URPGItem* Item);

	void NotifySlottedItemChanged(FRPGItemSlot ItemSlot, URPGItem* Item);

	void NotifyInventoryLoaded();

	void HandledSaveSameLoaded();

	

};
