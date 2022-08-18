// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/MySlateTypes.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE_OneParam(FItemClicked, const EMenuItem::Type)
/**
 * 
 */
class MYSLATE_API SMySlateMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlateMenuItemWidget)
	{}
    // ί��
	SLATE_EVENT(FItemClicked, OnClicked)

	SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)

	SLATE_ATTRIBUTE(FText, ItemText)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	//��д�����ť�¼�
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;


private:
	FSlateColor GetTintColor() const;

private:

	//
	const struct  FMySlateMenuStyle* MenuStyle;


	//ί�б���
	FItemClicked OnClicked;

	//���水ť����
	EMenuItem::Type ItemType;

	FText ItemText;

	bool IsMousetButtonDown;
};
