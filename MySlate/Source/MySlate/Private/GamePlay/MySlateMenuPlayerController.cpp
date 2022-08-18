// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MySlateMenuPlayerController.h"

AMySlateMenuPlayerController::AMySlateMenuPlayerController()
{
	// 显示鼠标
	bShowMouseCursor = true;
}

void AMySlateMenuPlayerController::BeginPlay()
{
	//设置输入模式。
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}
