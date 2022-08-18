// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class STextComboBox;
/**
 * 
 */
class MYSLATE_API SMySlateChooseRecordWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlateChooseRecordWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	void UpdateRecordName();

private:
	const struct  FMySlateMenuStyle* MenuStyle;

	TSharedPtr<STextComboBox> RecordComboBox;

	TArray<TSharedPtr<FString>>  OptionsSource;





};
