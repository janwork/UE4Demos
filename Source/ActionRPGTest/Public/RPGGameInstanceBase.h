// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ActionRPGTest.h"
#include "RPGTypes.h"
#include "RPGSaveGame.h"
#include "Engine/GameInstance.h"
#include "RPGGameInstanceBase.generated.h"

class URPGItem;
class URPGSaveGame;
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
		TMap<FPrimaryAssetId, FRPGItemData> DefaultInventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
		TMap<FPrimaryAssetType, int32> ItemSlotsPerType;

	UPROPERTY(BlueprintReadWrite, Category = Save)
		FString SaveSlot;

	UPROPERTY(BlueprintReadWrite, Category = Save)
		int32 SaveUserIndex;

	UPROPERTY(BlueprintAssignable, Category = Inventory)
		FOnSaveGameLoaded OnSaveGameLoaded;

	FOnSaveGameLoadedNative OnSaveGameLoadedNative;


	UFUNCTION(BlueprintCallable, Category = Inventory)
		void AddDefaultInventory(URPGSaveGame* SaveGame, bool  bRmoveExtra = false);

	UFUNCTION(BlueprintCallable, Category = Inventory)
		bool IsValidItemSlot(FRPGItemSlot ItemSlot) const;

	UFUNCTION(BlueprintPure, Category = Save)
		URPGSaveGame* GetCurrentSaveGame();

	UFUNCTION(BlueprintCallable, Category = Save)
		void SetSavingEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category = Save)
		bool LoadOrCreateSaveGame();

	UFUNCTION(BlueprintCallable, Category = Save)
		bool HandleSaveGameLoaded(USaveGame* SaveGameObject);

	UFUNCTION(BlueprintCallable, Category = Save)
		void GetSaveSlotInfo(FString& SlotName, int32& UserIndex) const;

	UFUNCTION(BlueprintCallable, Category = Save)
		bool WriteSaveGame();

	UFUNCTION(BlueprintCallable, Category = Save)
		void ResetSaveGame();

protected:

	UPROPERTY()
		URPGSaveGame* CurrentSaveGame;

	UPROPERTY()
		bool bSavingEnabled;

	UPROPERTY()
		bool bCurrentlySaving;

	UPROPERTY()
		bool bPendingSaveRequested;

	virtual void HandleAsyncSave(const FString& SlotName, const int32 UserIndex, bool bSuccess);

};
