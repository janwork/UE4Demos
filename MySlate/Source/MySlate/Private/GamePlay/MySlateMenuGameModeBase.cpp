// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MySlateMenuGameModeBase.h"
#include "UI/HUD/MySlateMenuHUD.h"
#include "GamePlay/MySlateMenuPlayerController.h"

AMySlateMenuGameModeBase::AMySlateMenuGameModeBase()
{
	//通过反射获得类
	PlayerControllerClass = AMySlateMenuPlayerController::StaticClass();
	HUDClass = AMySlateMenuHUD::StaticClass();

}
