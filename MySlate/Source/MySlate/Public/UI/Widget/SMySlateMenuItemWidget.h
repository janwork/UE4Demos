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
    // 委托
	SLATE_EVENT(FItemClicked, OnClicked)

	SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)

	SLATE_ATTRIBUTE(FText, ItemText)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	//重写点击按钮事件
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;


private:
	FSlateColor GetTintColor() const;

private:

	//
	const struct  FMySlateMenuStyle* MenuStyle;


	//委托变量
	FItemClicked OnClicked;

	//保存按钮类型
	EMenuItem::Type ItemType;

	FText ItemText;

	bool IsMousetButtonDown;
};
