// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"

/**
 * 
 */
class MYSLATE_API MySlateStyle
{
public:
	static void Initialze();

	static FName GetStyleName();

	static void ShutDown();

	static const ISlateStyle& Get();


private:
	static TSharedRef<class FSlateStyleSet> Create();

	static TSharedPtr<FSlateStyleSet> MySlateStyleInstance;
};
