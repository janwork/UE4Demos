// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MySlateMenuHUD.h"
#include "UI/Widget/SMySlateMenuHUDWidget.h"
#include "SlateBasics.h"


AMySlateMenuHUD::AMySlateMenuHUD()
{
	if (GEngine && GEngine->GameViewport) {

		SAssignNew(MenuHUDWidget, SMySlateMenuHUDWidget);//����һ��ָ������
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
	}
}
