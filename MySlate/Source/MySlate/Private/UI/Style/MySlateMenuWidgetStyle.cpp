// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Style/MySlateMenuWidgetStyle.h"

FMySlateMenuStyle::FMySlateMenuStyle()
{
}

FMySlateMenuStyle::~FMySlateMenuStyle()
{
}

const FName FMySlateMenuStyle::TypeName(TEXT("FMySlateMenuStyle"));

const FMySlateMenuStyle& FMySlateMenuStyle::GetDefault()
{
	static FMySlateMenuStyle Default;
	return Default;
}

void FMySlateMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

