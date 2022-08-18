// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/MySlateTypes.h"
#include "Widgets/SCompoundWidget.h"


class STextBlock;
class SCheckBox;
class SSlider;

DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultureTeam)
DECLARE_DELEGATE_TwoParams(FChangeVolume, const float, const float)

/**
 * 
 */
class MYSLATE_API SMySlateGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlateGameOptionWidget)
	{}

    // 委托

	SLATE_EVENT(FChangeCulture, ChangeCulture)

	SLATE_EVENT(FChangeVolume, ChangeVolume)
		
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:

	//设置样式
	void StyleInitialize();

	void ZhCheckBoxStateChanged(ECheckBoxState NewState);

	void EnCheckBoxStateChanged(ECheckBoxState NewState);

	void MusicSliderChanged(float Value);

	void SoundSliderChanged(float Value);


private:

	const struct  FMySlateMenuStyle* MenuStyle;

	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;

	TSharedPtr<STextBlock> MusicText;

	TSharedPtr<STextBlock> SoundText;

	TSharedPtr<SSlider>  MusicSlider;
	TSharedPtr<SSlider>  SoundSlider;

	FChangeCulture ChangeCulture;

	FChangeVolume ChangeVolume;
};
