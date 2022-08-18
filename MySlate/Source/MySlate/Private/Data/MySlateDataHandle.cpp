// Fill out your copyright notice in the Description page of Project Settings.



#include "Data/MySlateDataHandle.h"
#include "Data/MySlateJsonHandle.h"
#include "Data/MySlateSingleton.h"
#include "Common/MySlateHelper.h"
#include "UI/Style/MySlateStyle.h"
#include "UI/Style/MySlateMenuWidgetStyle.h"

TSharedPtr<MySlateDataHandle> MySlateDataHandle::DataInstance = NULL;

void MySlateDataHandle::Initialze()
{
	if (!DataInstance.IsValid()) {
		DataInstance = Create();
	}
}

TSharedPtr<MySlateDataHandle> MySlateDataHandle::Get()
{
	Initialze();
	return DataInstance;
}

TSharedRef<MySlateDataHandle> MySlateDataHandle::Create()
{
	TSharedRef<MySlateDataHandle> DataRef = MakeShareable(new MySlateDataHandle());

	return DataRef;
}

MySlateDataHandle::MySlateDataHandle()
{
	InitRecordData();
	InitialzedMenuAudio();
}

void MySlateDataHandle::ChangeLocalizationCulture(ECultureTeam Culture)
{
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::ZH:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	}

	CurrentCulture = Culture;

	MySlateSingleton<MySlateJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume,SoundVolume, &RecordDataList );
}

void MySlateDataHandle::ResetMenuVolume(float MusicVal, float SoundVal)
{
	if (MusicVal > 0) {
		MusicVolume = MusicVal;

		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Music"))->CreateIterator()); It; ++It)
		{
			(*It)->VolumeMultiplier = MusicVolume;
		}
	}

	if (SoundVal > 0) {
		SoundVolume = SoundVal;

		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Sound"))->CreateIterator()); It; ++It)
		{
			(*It)->VolumeMultiplier = SoundVolume;
		}
	}

	MySlateSingleton<MySlateJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume,SoundVolume, &RecordDataList );
}

template<typename TEnum>
//不能使用普通枚举，要使用UE的枚举基类
FString MySlateDataHandle::GetEnumValueAsString(const FString& Name, TEnum Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr) {
		return FString("InVaild");
	}

	return EnumPtr->GetEnumName((int32)Value);
}

template<typename TEnum>
TEnum MySlateDataHandle::GetEnumValuefromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr) {
		return TEnum(0);
	}

	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
}

void MySlateDataHandle::InitRecordData()
{
	FString Culture;

	RecordName = FString("");

	MySlateSingleton<MySlateJsonHandle>::Get()->RecordDataJsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);

	MySlateHelper::Debug(Culture + FString("--") + FString::SanitizeFloat(MusicVolume) + FString("--") + FString::SanitizeFloat(SoundVolume));

	for (TArray<FString>::TIterator It(RecordDataList); It; ++It)
	{
		MySlateHelper::Debug(*It, 10.f);
	}

	ChangeLocalizationCulture(GetEnumValuefromString<ECultureTeam>(FString("ECultureTeam"),Culture));

}

void MySlateDataHandle::InitialzedMenuAudio()
{
	MenuStyle = &MySlateStyle::Get().GetWidgetStyle<FMySlateMenuStyle>("BPMySlateMenuStyle");

	TArray<USoundCue*> MusicList;
	MusicList.Add(Cast<USoundCue>(MenuStyle->MenuBackgroundMusic.GetResourceObject()));

	TArray<USoundCue*> SoundList;
	SoundList.Add(Cast<USoundCue>(MenuStyle->ExitGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->StartGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->MenuItemChangeSound.GetResourceObject()));

	MenuAudioResource.Add(FString("Music"), MusicList);
	MenuAudioResource.Add(FString("Sound"), SoundList);

	ResetMenuVolume(MusicVolume, SoundVolume);
}

