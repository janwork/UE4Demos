// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySlate.h"
#include "Modules/ModuleManager.h"
#include "MySlate/Public/UI/Style/MySlateStyle.h"

void MySlateModule::StartupModule()
{
	//初始化样式
	FSlateStyleRegistry::UnRegisterSlateStyle(MySlateStyle::GetStyleName());
	MySlateStyle::Initialze();

}

void MySlateModule::ShutdownModule()
{

	//卸载样式
	MySlateStyle::ShutDown();
}

IMPLEMENT_PRIMARY_GAME_MODULE( MySlateModule, MySlate, "MySlate" );


