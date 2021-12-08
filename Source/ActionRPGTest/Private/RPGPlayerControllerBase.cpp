// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerControllerBase.h"
#include "RPGCharacterBase.h"
#include "RPGGameInstanceBase.h"
#include "Item/RPGItem.h"



ARPGPlayerControllerBase::ARPGPlayerControllerBase()
{
}

void ARPGPlayerControllerBase::BeginPlay()
{
	LoadInventory();
	Super::BeginPlay();
}

bool ARPGPlayerControllerBase::AddInventoryItem(URPGItem* NewItem, int32 ItemCount /*= 1*/, int32 ItemLevel /*= 1*/, bool bAutoSlot /*= true*/)
{
	bool bChanged = false;

	if (!NewItem) {
		return false;
	}

	if (ItemCount <= 0 || ItemLevel <= 0)
	{
		return false;
	}

	FRPGItemData OldData;
	GetInventoryItemData(NewItem, OldData);

	FRPGItemData NewData = OldData;
	NewData.UpdateItemData(FRPGItemData(ItemCount, ItemLevel), NewItem->MaxCount, NewItem->MaxLevel);

	if (OldData != NewData)
	{
		InventoryData.Add(NewItem, NewData);
		NotifyInventoryItemChanged(true, NewItem);
		bChanged = true;
	}

	if (bAutoSlot)
	{
		bChanged |= FillEmptySlotWithItem(NewItem);
	}

	if (bChanged)
	{
		SaveInventory();
		return true;
	}

	return false;
}

bool ARPGPlayerControllerBase::RemoveInventoryItem(URPGItem* RemoveItem, int32 RemoveCount /*= 1*/)
{
	if (!RemoveItem) {
		return false;
	}

	FRPGItemData NewData;
	GetInventoryItemData(RemoveItem, NewData);

	if (!NewData.IsValid())
	{
		return false;
	}

	if (RemoveCount <= 0)
	{
		NewData.ItemCount = 0;
	}
	else {
		NewData.ItemCount -= RemoveCount;
	}

	if (NewData.ItemCount > 0) {
		InventoryData.Add(RemoveItem, NewData);
	}
	else {
		InventoryData.Remove(RemoveItem);

		for (TPair<FRPGItemSlot, URPGItem*>& Pair : SlottedItems)
		{
			if (Pair.Value == RemoveItem)
			{
				Pair.Value = nullptr;
				NotifySlottedItemChanged(Pair.Key, Pair.Value);
			}
		}
	}

	NotifyInventoryItemChanged(false, RemoveItem);

	SaveInventory();

	return true;
}

void ARPGPlayerControllerBase::GetInventoryItems(TArray<URPGItem*>& Items, FPrimaryAssetType ItemType)
{
	for (const TPair<URPGItem*, FRPGItemData>& Pair : InventoryData)
	{
		if (Pair.Key)
		{
			FPrimaryAssetId AssetId = Pair.Key->GetPrimaryAssetId();

			if (AssetId.PrimaryAssetType == ItemType || !ItemType.IsValid())
			{
				Items.Add(Pair.Key);
			}

		}
	}
}

int32 ARPGPlayerControllerBase::GetInventoryItemCount(URPGItem* Item) const
{
	const FRPGItemData* FoundItem = InventoryData.Find(Item);

	if (FoundItem)
	{
		return FoundItem->ItemCount;
	}
	return 0;
}

bool ARPGPlayerControllerBase::GetInventoryItemData(URPGItem* Item, FRPGItemData& ItemData) const
{
	const FRPGItemData* FoundItem = InventoryData.Find(Item);

	if (FoundItem)
	{
		ItemData = *FoundItem;
		return true;
	}

	ItemData = FRPGItemData(0, 0);
	return false;
}

bool ARPGPlayerControllerBase::SetSlottedItem(FRPGItemSlot ItemSlot, URPGItem* Item)
{

	bool bFound = false;

	for (TPair<FRPGItemSlot, URPGItem*>& Pair : SlottedItems)
	{
		if (Pair.Key == ItemSlot)
		{
			bFound = true;
			Pair.Value = Item;
			NotifySlottedItemChanged(Pair.Key, Pair.Value);
		}
		else if (Item != nullptr)
		{
			Pair.Value = nullptr;
			NotifySlottedItemChanged(Pair.Key, Pair.Value);
		}
	}

	if (bFound)
	{
		SaveInventory();
		return true;
	}

	return false;

}

URPGItem* ARPGPlayerControllerBase::GetSlottedItem(FRPGItemSlot ItemSlot) const
{
	URPGItem* const* FoundItem = SlottedItems.Find(ItemSlot);

	if (FoundItem) {
		return *FoundItem;
	}

	return nullptr;
}

void ARPGPlayerControllerBase::GetSlottedItems(TArray<URPGItem*>& Items, FPrimaryAssetType ItemType, bool bOutputEmptyIndexes)
{
	for (TPair<FRPGItemSlot, URPGItem*>& Pair : SlottedItems)
	{
		if (Pair.Key.ItemType == ItemType || !ItemType.IsValid())
		{
			Items.Add(Pair.Value);
		}
	}
}

void ARPGPlayerControllerBase::FillEmptySlots()
{
	bool bShouldSave = false;

	for (const TPair<URPGItem*, FRPGItemData>& Pair : InventoryData)
	{
		bShouldSave |= FillEmptySlotWithItem(Pair.Key);
	}

	if (bShouldSave)
	{
		SaveInventory();
	}
}

bool ARPGPlayerControllerBase::SaveInventory()
{
	return true;
}

bool ARPGPlayerControllerBase::LoadInventory()
{

	InventoryData.Reset();
	SlottedItems.Reset();

	UWorld* World = GetWorld();
	URPGGameInstanceBase* GameInstance = World ? World->GetGameInstance<URPGGameInstanceBase>() : nullptr;

	if (!GameInstance) {
		return false;
	}

	for (const TPair<FPrimaryAssetType, int32>& Pair : GameInstance->ItemSlotsPerType)
	{
		for (int32 SlotNumber = 0; SlotNumber < Pair.Value; SlotNumber++)
		{
			SlottedItems.Add(FRPGItemSlot(Pair.Key, SlotNumber), nullptr);
		}
	}

	return true;

}

bool ARPGPlayerControllerBase::FillEmptySlotWithItem(URPGItem* NewItem)
{
	FPrimaryAssetType NewItemType = NewItem->GetPrimaryAssetId().PrimaryAssetType;
	FRPGItemSlot EmptySlot;
	for (TPair<FRPGItemSlot, URPGItem*>& Pair : SlottedItems)
	{
		if (Pair.Key.ItemType == NewItemType)
		{
			if (Pair.Value == NewItem)
			{
				return false;
			}
			else if (Pair.Value == nullptr && (!EmptySlot.IsValid() || EmptySlot.SlotNumber > Pair.Key.SlotNumber))
			{
				EmptySlot = Pair.Key;
			}
		}
	}

	if (EmptySlot.IsValid())
	{
		SlottedItems[EmptySlot] = NewItem;
		NotifySlottedItemChanged(EmptySlot, NewItem);
		return true;
	}

	return false;
}

void ARPGPlayerControllerBase::NotifyInventoryItemChanged(bool bAdded, URPGItem* Item)
{
	OnInventoryItemChangedNative.Broadcast(bAdded, Item);
	OnInventoryItemChanged.Broadcast(bAdded, Item);

	InventoryItemChanged(bAdded, Item);
}

void ARPGPlayerControllerBase::NotifySlottedItemChanged(FRPGItemSlot ItemSlot, URPGItem* Item)
{
	OnSlottedItemChangedNative.Broadcast(ItemSlot, Item);
	OnSlottedItemChanged.Broadcast(ItemSlot, Item);

	SlottedItemChanged(ItemSlot, Item);
}

void ARPGPlayerControllerBase::NotifyInventoryLoaded()
{
	OnInventoryLoadedNative.Broadcast();
	OnInventoryLoaded.Broadcast();
}

void ARPGPlayerControllerBase::HandledSaveSameLoaded()
{
	LoadInventory();
}


