// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemonPluginBPLibrary.h"
#include "DemonPlugin.h"
#include "Engine/Engine.h"
#include "Interfaces/IPluginManager.h"

#include "SQLiteDatabase.h"

UDemonPluginBPLibrary::UDemonPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UDemonPluginBPLibrary::DemonPluginSampleFunction(float Param)
{
	return -1;
}

int UDemonPluginBPLibrary::TestFunction()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DemoPlugin Test Function"));
	return 0;
}

void UDemonPluginBPLibrary::TestOpenSqlite()
{
	static FString CttDir = IPluginManager::Get().FindPlugin(TEXT("DemonPlugin"))->GetContentDir();
	FSQLiteDatabase Db;
	FString DBPath = CttDir + "/Data/Items.db";
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *DBPath);

	if (Db.Open(*DBPath))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Open db Success..."));
	}

	Db.Close();
}

