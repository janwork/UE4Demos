// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySlate.h"
#include "Modules/ModuleManager.h"
#include "MySlate/Public/UI/Style/MySlateStyle.h"

void MySlateModule::StartupModule()
{
	//��ʼ����ʽ
	FSlateStyleRegistry::UnRegisterSlateStyle(MySlateStyle::GetStyleName());
	MySlateStyle::Initialze();

}

void MySlateModule::ShutdownModule()
{

	//ж����ʽ
	MySlateStyle::ShutDown();
}

IMPLEMENT_PRIMARY_GAME_MODULE( MySlateModule, MySlate, "MySlate" );


