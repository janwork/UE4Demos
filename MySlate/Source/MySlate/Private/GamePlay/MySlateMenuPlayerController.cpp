// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MySlateMenuPlayerController.h"

AMySlateMenuPlayerController::AMySlateMenuPlayerController()
{
	// ��ʾ���
	bShowMouseCursor = true;
}

void AMySlateMenuPlayerController::BeginPlay()
{
	//��������ģʽ��
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}
