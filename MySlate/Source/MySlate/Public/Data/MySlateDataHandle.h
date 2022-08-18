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


	//�޸�����/Ӣ��
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

	template<typename TEnum>//����ʹ����ͨö�٣�Ҫʹ��UE��ö�ٻ���
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

