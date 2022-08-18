// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MySlateMenuHUD.h"
#include "UI/Widget/SMySlateMenuHUDWidget.h"
#include "SlateBasics.h"


AMySlateMenuHUD::AMySlateMenuHUD()
{
	if (GEngine && GEngine->GameViewport) {

		SAssignNew(MenuHUDWidget, SMySlateMenuHUDWidget);//返回一个指针引用
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
	}
}
