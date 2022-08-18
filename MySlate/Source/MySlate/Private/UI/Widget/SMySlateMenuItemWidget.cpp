// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SMySlateMenuItemWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/MySlateStyle.h"
#include "UI/Style/MySlateMenuWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySlateMenuItemWidget::Construct(const FArguments& InArgs)
{

	MenuStyle = &MySlateStyle::Get().GetWidgetStyle<FMySlateMenuStyle>("BPMySlateMenuStyle");

	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();
	ItemText = InArgs._ItemText.Get();

	IsMousetButtonDown = false;
	

	ChildSlot
	[
			SNew(SBox)
			.WidthOverride(500.f)
			.HeightOverride(100.f)
			[
					SNew(SOverlay)
						+SOverlay::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SImage)
								.Image(&MenuStyle->MenuItemBrush)
								.ColorAndOpacity(this, &SMySlateMenuItemWidget::GetTintColor)
						]

						+SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
								.Font(MenuStyle->Font_60)
								.Text(InArgs._ItemText)
						]
			]

	
	];
	 
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMySlateMenuItemWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{

	IsMousetButtonDown = true;

	return FReply::Handled();
}

FReply SMySlateMenuItemWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (IsMousetButtonDown) {
		//OnClicked.Execute(); 不判断是否有判定
		OnClicked.ExecuteIfBound(ItemType);
	}

	
	IsMousetButtonDown = false;
	return FReply::Handled();
}

void SMySlateMenuItemWidget::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	IsMousetButtonDown = false;
}

FSlateColor SMySlateMenuItemWidget::GetTintColor() const
{
	if (IsMousetButtonDown) {
		return FLinearColor(1.f, 1.f, 1.f, 0.5f);
	}

	return FLinearColor(1.f, 1.f, 1.f, 1.f);

}
