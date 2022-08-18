// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class MYSLATE_API SMySlateMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlateMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	float getUIScaler() const;

	FVector2D GetViewportSize() const;

	//FReply OnClick();


private:
	//获取Menu样式
	const struct FMySlateMenuStyle* MenuStyle;


	//DPI缩放系数
	TAttribute<float> UIScaler;

	////获取Image的Slot
	//SOverlay::FOverlaySlot* ImageSlot;

	TSharedPtr<class SMySlateMenuWidget> MenuWidget;
};
