// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */


class SBox;
class SEditableTextBox;


class MYSLATE_API SMySlateNewGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlateNewGameWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	bool AllowEnterGame();


private:

	const struct  FMySlateMenuStyle* MenuStyle;

	TSharedPtr<SBox> RootSizeBox;

	TSharedPtr<SEditableTextBox> EditTextBox;

	
};
