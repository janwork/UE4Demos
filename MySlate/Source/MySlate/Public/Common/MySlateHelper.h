// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Engine/GameEngine.h"
//#include "SlateApplication.h"
//#include "SlateSound.h"
#include "TimerManager.h"


namespace MySlateHelper {
	FORCEINLINE void Debug(FString Message, float Duration = 3.f) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, Duration, FColor::Red, Message);
		}
	}



	template<class UserClass>
	FORCEINLINE FTimerHandle PlayerSoundAndCall(UWorld* world, const FSlateSound Sound, UserClass* InUserObject, typename FTimerDelegate::TRawMethodDelegate<UserClass>::FMethodPtr InMethod) {
		FSlateApplication::Get().PlaySound(Sound);

		FTimerHandle Result;

		const float SoundDuration = FMath::Max(FSlateApplication::Get().GetSoundDuration(Sound), 0.1f);
		
		FTimerDelegate Callback;

		Callback.BindRaw(InUserObject, InMethod);

		world->GetTimerManager().SetTimer(Result, Callback, SoundDuration, false);
		return Result;

	}





}