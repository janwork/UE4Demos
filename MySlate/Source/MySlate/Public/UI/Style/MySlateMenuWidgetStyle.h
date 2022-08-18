// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "MySlateMenuWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct MYSLATE_API FMySlateMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMySlateMenuStyle();
	virtual ~FMySlateMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMySlateMenuStyle& GetDefault();


	UPROPERTY(EditAnywhere, Category = "MenuHUD" )
	FSlateBrush MenuHUDBackgroundBrush;

	UPROPERTY(EditAnywhere, Category = "Menu" )
	FSlateBrush MenuBackgroundBrush;

	UPROPERTY(EditAnywhere, Category = "Menu" )
	FSlateBrush LeftIconBrush;

	UPROPERTY(EditAnywhere, Category = "Menu" )
	FSlateBrush RightIconBrush;

	UPROPERTY(EditAnywhere, Category = "Menu" )
	FSlateBrush TitleBorderBrush;

	UPROPERTY(EditAnywhere, Category = "Common" )
	FSlateBrush MenuItemBrush;

	UPROPERTY(EditAnywhere, Category = "Menu" )
	FSlateFontInfo TitleFont;

	UPROPERTY(EditAnywhere, Category = "Common")
	FSlateFontInfo Font_30;

	UPROPERTY(EditAnywhere, Category = "Common" )
	FSlateFontInfo Font_40;

	UPROPERTY(EditAnywhere, Category = "Common" )
	FSlateFontInfo Font_60;

	UPROPERTY(EditAnywhere, Category = "Common" )
	FLinearColor FontColor_White;

	UPROPERTY(EditAnywhere, Category = "Common" )
	FLinearColor FontColor_Black;

	UPROPERTY(EditAnywhere, Category = "GameOption" )
	FSlateBrush GameOptionBrush;

	UPROPERTY(EditAnywhere, Category = "GameOption" )
	FSlateBrush CheckBoxBrush;

	UPROPERTY(EditAnywhere, Category = "GameOption")
	FSlateBrush UnCheckBoxBrush;

	UPROPERTY(EditAnywhere, Category = "GameOption" )
	FSlateBrush SliderBarBrush;

	UPROPERTY(EditAnywhere, Category = "GameOption")
	FSliderStyle SliderStyle;

	UPROPERTY(EditAnywhere, Category = "Sound")
	FSlateSound StartGameSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	FSlateSound ExitGameSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	FSlateSound MenuItemChangeSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	FSlateSound MenuBackgroundMusic;

};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UMySlateMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMySlateMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
