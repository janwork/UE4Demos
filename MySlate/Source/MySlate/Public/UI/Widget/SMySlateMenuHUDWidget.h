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
	//��ȡMenu��ʽ
	const struct FMySlateMenuStyle* MenuStyle;


	//DPI����ϵ��
	TAttribute<float> UIScaler;

	////��ȡImage��Slot
	//SOverlay::FOverlaySlot* ImageSlot;

	TSharedPtr<class SMySlateMenuWidget> MenuWidget;
};
