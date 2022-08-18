// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SMySlateMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SDPIScaler.h"
#include "UI/Style/MySlateStyle.h"
#include "UI/Style/MySlateMenuWidgetStyle.h"
#include "UI/Widget/SMySlateMenuWidget.h"
#include "UI/Widget/SMySlateGameOptionWidget.h"
#include "Engine/Engine.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySlateMenuHUDWidget::Construct(const FArguments& InArgs)
{

	//获取样式
	MenuStyle = &MySlateStyle::Get().GetWidgetStyle<FMySlateMenuStyle>("BPMySlateMenuStyle");

	//绑定缩放规则

	UIScaler.Bind(this, &SMySlateMenuHUDWidget::getUIScaler);


	//插槽加入image
	ChildSlot
	[
			SNew(SDPIScaler)
			.DPIScale(UIScaler)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(FMargin(30.f))
				[
					SNew(SImage)
					.Image(&MenuStyle->MenuHUDBackgroundBrush)
				]

		
				+SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SAssignNew(MenuWidget, SMySlateMenuWidget)
					
				]

			]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

float SMySlateMenuHUDWidget::getUIScaler() const
{
	return GetViewportSize().Y / 1080.f;
}

FVector2D SMySlateMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(Result);
	}

	return Result;
}

//FReply SMySlateMenuHUDWidget::OnClick()
//{
//	ImageSlot->HAlign(HAlign_Right).VAlign(VAlign_Bottom);
//	return FReply::Handled();
//}
