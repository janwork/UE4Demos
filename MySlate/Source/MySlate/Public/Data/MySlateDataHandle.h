// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MySlateTypes.h"
#include "CoreMinimal.h"
#include "Sound\SoundCue.h"


/**
 * 
 */
class MYSLATE_API MySlateDataHandle
{
public:
	MySlateDataHandle();

	static void Initialze();

	static TSharedPtr<MySlateDataHandle> Get();


	//修改中文/英文
	void ChangeLocalizationCulture(ECultureTeam Culture);

	void ResetMenuVolume(float MusicVal, float SoundVal);

public:

	ECultureTeam CurrentCulture;

	float MusicVolume;

	float SoundVolume;

	TArray<FString> RecordDataList;

	FString RecordName;

private:

	static TSharedRef<MySlateDataHandle> Create();

	template<typename TEnum>//不能使用普通枚举，要使用UE的枚举基类
	FString GetEnumValueAsString(const FString& Name, TEnum Value);

	template<typename TEnum>
	TEnum GetEnumValuefromString(const FString& Name, FString Value);

	void InitRecordData();

	void InitialzedMenuAudio();

private:
	static TSharedPtr<MySlateDataHandle> DataInstance;

	TMap<FString, TArray<USoundCue*>> MenuAudioResource;

	const struct FMySlateMenuStyle* MenuStyle;
};

