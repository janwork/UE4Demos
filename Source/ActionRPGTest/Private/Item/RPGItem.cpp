// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RPGItem.h"

bool URPGItem::IsConSumable() const
{

	return MaxCount <= 0;
}

FString URPGItem::GetIdentifierString() const
{
	return GetPrimaryAssetId().ToString();
}

FPrimaryAssetId URPGItem::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemType, GetFName());
}
