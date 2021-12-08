// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameInstanceBase.h"
#include "RPGAssetManager.h"
#include "RPGSaveGame.h"
#include "Item/RPGItem.h"
#include "Kismet/GameplayStatics.h"

URPGGameInstanceBase::URPGGameInstanceBase():SaveSlot(TEXT("SaveGame")), SaveUserIndex(0)
{
}

void URPGGameInstanceBase::AddDefaultInventory(URPGSaveGame* SaveGame, bool bRmoveExtra /*= false*/)
{
	if (bRmoveExtra)
	{
		SaveGame->InventoryData.Reset();
	}

	for (const TPair<FPrimaryAssetId, FRPGItemData>& Pair : DefaultInventory)
	{
		if (!SaveGame->InventoryData.Contains(Pair.Key))
		{
			SaveGame->InventoryData.Add(Pair.Key, Pair.Value);
		}
	}
}

bool URPGGameInstanceBase::IsValidItemSlot(FRPGItemSlot ItemSlot) const
{
	if (ItemSlot.IsValid())
	{
		const int32* FoundCount = ItemSlotsPerType.Find(ItemSlot.ItemType);

		if (FoundCount)
		{
			return ItemSlot.SlotNumber < *FoundCount;
		}
	}
	return false;
}

URPGSaveGame* URPGGameInstanceBase::GetCurrentSaveGame()
{
	return CurrentSaveGame;
}

void URPGGameInstanceBase::SetSavingEnabled(bool bEnabled)
{
	bSavingEnabled = bEnabled;
}

bool URPGGameInstanceBase::LoadOrCreateSaveGame()
{

	URPGSaveGame* LoadedSave = nullptr;

	if (UGameplayStatics::DoesSaveGameExist(SaveSlot, SaveUserIndex) && bSavingEnabled)
	{
		LoadedSave = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, SaveUserIndex));
	}

	return HandleSaveGameLoaded(LoadedSave);
}

bool URPGGameInstanceBase::HandleSaveGameLoaded(USaveGame* SaveGameObject)
{
	bool bLoaded = false;

	if (!bSavingEnabled)
	{
		SaveGameObject = nullptr;
	}
	
	CurrentSaveGame = Cast<URPGSaveGame>(SaveGameObject);

	if (CurrentSaveGame)
	{
		AddDefaultInventory(CurrentSaveGame, false);
		bLoaded = true;
	}
	else
	{
		CurrentSaveGame = Cast<URPGSaveGame>(UGameplayStatics::CreateSaveGameObject(URPGSaveGame::StaticClass()));
		AddDefaultInventory(CurrentSaveGame, true);
	}

	OnSaveGameLoaded.Broadcast(CurrentSaveGame);
	OnSaveGameLoadedNative.Broadcast(CurrentSaveGame);

	return true;
}

void URPGGameInstanceBase::GetSaveSlotInfo(FString& SlotName, int32& UserIndex) const
{
	SlotName = SaveSlot;
	UserIndex = SaveUserIndex;

}

bool URPGGameInstanceBase::WriteSaveGame()
{
	if (bSavingEnabled)
	{
		if (bCurrentlySaving)
		{
			bPendingSaveRequested = true;
			return true;
		}

		bCurrentlySaving = true;

		UGameplayStatics::AsyncSaveGameToSlot(GetCurrentSaveGame(), SaveSlot, SaveUserIndex, FAsyncSaveGameToSlotDelegate::CreateUObject(this, &URPGGameInstanceBase::HandleAsyncSave));
		return true;
	}
	return false;
}

void URPGGameInstanceBase::ResetSaveGame()
{
	HandleSaveGameLoaded(nullptr);
}

void URPGGameInstanceBase::HandleAsyncSave(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	ensure(bCurrentlySaving);

	bCurrentlySaving = false;

	if (bPendingSaveRequested)
	{
		bPendingSaveRequested = false;
		WriteSaveGame();
	}
}
