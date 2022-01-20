// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "../ActionRPGTest.h"
#include "RPGTypes.h"
#include "Item/RPGItem.h"
#include "GameFramework/SaveGame.h"
#include "RPGSaveGame.generated.h"

struct FRPGItemData;

namespace ERPGSaveGameVersion
{
	enum type
	{
		// Initial version
		Initial,
		// Added Inventory
		AddedInventory,
		// Added ItemData to store count/level
		AddedItemData,

		// -----<new versions must be added before this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne - 1
	};
}

/** Object that is written to and read from the save game archive, with a data version */
UCLASS(BlueprintType)
class ACTIONRPGTEST_API URPGSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	/** Constructor */
	URPGSaveGame()
	{
		// Set to current version, this will get overwritten during serialization when loading
		SavedDataVersion = ERPGSaveGameVersion::LatestVersion;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
		TMap<FPrimaryAssetId, FRPGItemData> InventoryData;
								
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
		TMap<FRPGItemSlot, FPrimaryAssetId> SlottedItems;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
		FString UserId;

protected:
	UPROPERTY()
		TArray<FPrimaryAssetId> InventoryItems_DEPRECATED;

	UPROPERTY()
		int32 SavedDataVersion;

	virtual void Serialize(FArchive& Ar) override;
};
