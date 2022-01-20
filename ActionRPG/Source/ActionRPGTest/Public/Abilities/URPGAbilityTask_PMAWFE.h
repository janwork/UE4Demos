// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionRPGTest/ActionRPGTest.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "URPGAbilityTask_PMAWFE.generated.h"

class URPGAbilitySystemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRPGPlayMontageAndWaitForEventDelegate1, FGameplayTag, EventTag, FGameplayEventData, EventData);


/**
 * RPGAbilityTask_PlayMontageAndWaitForEvent
 */
UCLASS()
class ACTIONRPGTEST_API URPGAbilityTask_PMAWFE : public UAbilityTask
{
	GENERATED_BODY()

public:

	URPGAbilityTask_PMAWFE(const FObjectInitializer& ObjectInitializer);

	virtual void Activate() override;
	virtual void ExternalCancel() override;
	virtual FString GetDebugString() const override;
	virtual void OnDestroy(bool AbilityEnded) override;

	UPROPERTY(BlueprintAssignable)
		FRPGPlayMontageAndWaitForEventDelegate1 OnCompleted;

	UPROPERTY(BlueprintAssignable)
		FRPGPlayMontageAndWaitForEventDelegate1 OnBlendOut;

	UPROPERTY(BlueprintAssignable)
		FRPGPlayMontageAndWaitForEventDelegate1 OnInterrupted;

	UPROPERTY(BlueprintAssignable)
		FRPGPlayMontageAndWaitForEventDelegate1 OnCancelled;

	UPROPERTY(BlueprintAssignable)
		FRPGPlayMontageAndWaitForEventDelegate1 EventReceived;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
		static URPGAbilityTask_PMAWFE* PlayMontageAndWaitForEvent(
			UGameplayAbility* OwningAbility,
			FName TaskInstanceName,
			UAnimMontage* MontageToPlay,
			FGameplayTagContainer EventTags,
			float Rate = 1.0f,
			FName StartSection = NAME_None,
			bool bStopWhenAbilityEnds = true,
			float AnimRootMotionTranslationScale = 1.f);

private:

	UPROPERTY()
		UAnimMontage* MontageToPlay;

	UPROPERTY()
		FGameplayTagContainer EventTags;

	UPROPERTY()
		float Rate;

	UPROPERTY()
		FName StartSection;

	UPROPERTY()
		float AnimRootMotionTranslationScale;

	UPROPERTY()
		bool bStopWhenAbilityEnds;

	bool StopPlayingMontage();

	URPGAbilitySystemComponent* GetTargetASC();

	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
	void OnAbilityCancelled();
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	void OnGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload);

	FOnMontageBlendingOutStarted BlendingOutDelegate;
	FOnMontageEnded MontageEndedDelegate;
	FDelegateHandle CancelledHandle;
	FDelegateHandle EventHandle;



};
