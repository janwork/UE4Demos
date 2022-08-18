// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Style/MySlateStyle.h"
#include "Slate/SlateGameResources.h"


TSharedPtr<FSlateStyleSet> MySlateStyle::MySlateStyleInstance = NULL;

void MySlateStyle::Initialze()
{
	if (!MySlateStyleInstance.IsValid()) {
		MySlateStyleInstance = Create();
		// 向系统注册当前Slate Style
		FSlateStyleRegistry::RegisterSlateStyle(*MySlateStyleInstance);
	}
}

FName MySlateStyle::GetStyleName()
{
	static FName SlateSetName(TEXT("MySlateStyle"));

	return SlateSetName;
}

void MySlateStyle::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MySlateStyleInstance);
	ensure(MySlateStyleInstance.IsUnique());

	MySlateStyleInstance.Reset();

}

const ISlateStyle& MySlateStyle::Get()
{
	return *MySlateStyleInstance;
}

TSharedRef<class FSlateStyleSet> MySlateStyle::Create()
{

	////UE4下的
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(MySlateStyle::GetStyleName(), "/Game/UI/Style", "/Game/UI/Style");
	StyleRef->Set("MenuItemFont", FSlateFontInfo("Roboto-Regular.ttf", 50));


	return StyleRef;
}


