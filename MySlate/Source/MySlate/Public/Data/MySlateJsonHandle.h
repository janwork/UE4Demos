// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/MySlateTypes.h"
#include "Json.h"

/**
 * 
 */
class MYSLATE_API MySlateJsonHandle
{
public:
	MySlateJsonHandle();

	//解析存档
	void RecordDataJsonRead(FString& Culture, float& MusicVolume, float & SoundVolume, TArray<FString>& RecordDataList);

	//修改存档
	void UpdateRecordData(FString Culture, float MusicVolumn, float SoundVolume, TArray<FString>* RecordDataList);

private:

	bool LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString);

	bool GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr);

	bool WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName);

private:

	//存档文件名
	FString RecordDataFileName;

	//相对路径
	FString RelativePath;


};
