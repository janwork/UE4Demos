// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MySlateMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYSLATE_API AMySlateMenuHUD : public AHUD
{
	GENERATED_BODY()
public:

	AMySlateMenuHUD();

	TSharedPtr<class SMySlateMenuHUDWidget> MenuHUDWidget;
};
