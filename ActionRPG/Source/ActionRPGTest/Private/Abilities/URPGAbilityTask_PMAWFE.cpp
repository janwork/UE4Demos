// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/URPGAbilityTask_PMAWFE.h"
#include "Abilities/RPGAbilitySystemComponent.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

URPGAbilityTask_PMAWFE::URPGAbilityTask_PMAWFE(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	Rate = 1.f;
	bStopWhenAbilityEnds = true;
}

URPGAbilitySystemComponent* URPGAbilityTask_PMAWFE::GetTargetASC()
{
	return Cast<URPGAbilitySystemComponent>(AbilitySystemComponent);
}

void URPGAbilityTask_PMAWFE::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
	if (Ability && Ability->GetCurrentMontage() == MontageToPlay) 
	{
		if (Montage == MontageToPlay)
		{
			AbilitySystemComponent->ClearAnimatingAbility(Ability);

			ACharacter* Character = Cast<ACharacter>(GetAvatarActor());
			if (Character && (Character->GetLocalRole() == ROLE_Authority ||
							(Character->GetLocalRole() == ROLE_AutonomousProxy && Ability->GetNetExecutionPolicy() == EGameplayAbilityNetExecutionPolicy::LocalPredicted)))
			{
				Character->SetAnimRootMotionTranslationScale(1.f);
			}
		}
	}

	if (bInterrupted) {
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnInterrupted.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}
	else
	{
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			GetDebugString();
			OnBlendOut.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}
}

void URPGAbilityTask_PMAWFE::OnAbilityCancelled()
{
	if (StopPlayingMontage())
	{
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			GetDebugString();
			OnCancelled.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}
}

void URPGAbilityTask_PMAWFE::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (!bInterrupted)
	{
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			GetDebugString();
			OnCompleted.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}

	EndTask();
}

void URPGAbilityTask_PMAWFE::OnGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		FGameplayEventData TempData = *Payload;
		TempData.EventTag = EventTag;

		GetDebugString();
		EventReceived.Broadcast(EventTag, TempData);
	}
}

URPGAbilityTask_PMAWFE* URPGAbilityTask_PMAWFE::PlayMontageAndWaitForEvent(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, FGameplayTagContainer EventTags, float Rate /*= 1.0f*/, FName StartSection /*= NAME_None*/, bool bStopWhenAbilityEnds /*= true*/, float AnimRootMotionTranslationScale /*= 1.f*/)
{
	UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(Rate);

	URPGAbilityTask_PMAWFE* MyObj = NewAbilityTask<URPGAbilityTask_PMAWFE>(OwningAbility, TaskInstanceName);
	MyObj->MontageToPlay = MontageToPlay;
	MyObj->EventTags = EventTags;
	MyObj->Rate = Rate;
	MyObj->StartSection = StartSection;
	MyObj->AnimRootMotionTranslationScale = AnimRootMotionTranslationScale;
	MyObj->bStopWhenAbilityEnds = bStopWhenAbilityEnds;


	return MyObj;
}


void URPGAbilityTask_PMAWFE::Activate()
{
	if (Ability == nullptr)
	{
		return;
	}

	bool bPlayedMontage = false;
	URPGAbilitySystemComponent* RPGAbilitySystemComponent = GetTargetASC();

	if (RPGAbilitySystemComponent)
	{
		const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();

		UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();

		if (AnimInstance != nullptr)
		{
			EventHandle = RPGAbilitySystemComponent->AddGameplayEventTagContainerDelegate(EventTags, FGameplayEventTagMulticastDelegate::FDelegate::CreateUObject(this, &URPGAbilityTask_PMAWFE::OnGameplayEvent));

			if (RPGAbilitySystemComponent->PlayMontage(Ability, Ability->GetCurrentActivationInfo(), MontageToPlay, Rate, StartSection) > 0.f)
			{
				if (ShouldBroadcastAbilityTaskDelegates() == false)
				{
					return;
				}

				CancelledHandle = Ability->OnGameplayAbilityCancelled.AddUObject(this, &URPGAbilityTask_PMAWFE::OnAbilityCancelled);

				BlendingOutDelegate.BindUObject(this, &URPGAbilityTask_PMAWFE::OnMontageBlendingOut);
				AnimInstance->Montage_SetBlendingOutDelegate(BlendingOutDelegate, MontageToPlay);

				MontageEndedDelegate.BindUObject(this, &URPGAbilityTask_PMAWFE::OnMontageEnded);
				AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate, MontageToPlay);

				ACharacter* Character = Cast<ACharacter>(GetAvatarActor());

				if (Character && (Character->GetLocalRole() == ROLE_Authority ||
									(Character->GetLocalRole() == ROLE_AutonomousProxy && Ability->GetNetExecutionPolicy() == EGameplayAbilityNetExecutionPolicy::LocalPredicted)))
				{
					Character->SetAnimRootMotionTranslationScale(AnimRootMotionTranslationScale);
				}

				bPlayedMontage = true;

			}
		}
		else {
			ABILITY_LOG(Warning, TEXT("URPGAbilityTask_PlayMontageAndWaitForEvent call to PlayMontage failed!"));
		}
	}
	else
	{
		ABILITY_LOG(Warning, TEXT("URPGAbilityTask_PlayMontageAndWaitForEvent called on invalid AbilitySystemComponent"));
	}

	if (!bPlayedMontage) {
		ABILITY_LOG(Warning, TEXT("URPGAbilityTask_PlayMontageAndWaitForEvent called in Ability %s failed to play montage %s; Task Instance Name %s."), *Ability->GetName(), *GetNameSafe(MontageToPlay), *InstanceName.ToString());
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnCancelled.Broadcast(FGameplayTag(), FGameplayEventData());
		}
	}



	SetWaitingOnAvatar();


}

void URPGAbilityTask_PMAWFE::ExternalCancel()
{
	check(AbilitySystemComponent);

	OnAbilityCancelled();

	Super::ExternalCancel();
}

void URPGAbilityTask_PMAWFE::OnDestroy(bool AbilityEnded)
{
	if (Ability)
	{
		Ability->OnGameplayAbilityCancelled.Remove(CancelledHandle);
		if (AbilityEnded && bStopWhenAbilityEnds)
		{
			StopPlayingMontage();
		}
	}

	URPGAbilitySystemComponent* RPGAbilitySystemComponent = GetTargetASC();

	if (RPGAbilitySystemComponent)
	{
		RPGAbilitySystemComponent->RemoveGameplayEventTagContainerDelegate(EventTags, EventHandle);
	}

	Super::OnDestroy(AbilityEnded);
}


bool URPGAbilityTask_PMAWFE::StopPlayingMontage()
{
	const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
	if (!ActorInfo)
	{
		return false;
	}

	UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();

	if (AnimInstance == nullptr)
	{
		return false;
	}

	if (AbilitySystemComponent && Ability)
	{
		if (AbilitySystemComponent->GetAnimatingAbility() == Ability && AbilitySystemComponent->GetCurrentMontage() == MontageToPlay)
		{
			FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(MontageToPlay);

			if (MontageInstance)
			{
				MontageInstance->OnMontageBlendingOutStarted.Unbind();
				MontageInstance->OnMontageEnded.Unbind();
			}

			AbilitySystemComponent->CurrentMontageStop();
			return true;
		}
	}


	return false;
}



FString URPGAbilityTask_PMAWFE::GetDebugString() const
{
	UAnimMontage* PlayingMontage = nullptr;
	if (Ability)
	{
		const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
		UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();

		if (AnimInstance != nullptr)
		{
			PlayingMontage = AnimInstance->Montage_IsActive(MontageToPlay) ? MontageToPlay : AnimInstance->GetCurrentActiveMontage();
		}
	}

	return FString::Printf(TEXT("PlayMontageAndWaitForEvent. MontageToPlay: %s  (Currently Playing): %s"), *GetNameSafe(MontageToPlay), *GetNameSafe(PlayingMontage));
}
