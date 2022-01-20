// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/RPGAbilityTypes.h"
#include "Abilities/RPGAbilitySystemComponent.h"

bool FRPGGameplayEffectContainerSpec::HasVaildEffects() const
{
	return TargetGameplayEffectSpecs.Num() > 0;
}

bool FRPGGameplayEffectContainerSpec::HasVaildTargets() const
{
	return TargetData.Num() > 0;
}

void FRPGGameplayEffectContainerSpec::AddTargets(const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors)
{
	for (const FHitResult& HitResults : HitResults) {
		FGameplayAbilityTargetData_SingleTargetHit* NewData = new FGameplayAbilityTargetData_SingleTargetHit(HitResults);
		TargetData.Add(NewData);
	}

	if (TargetActors.Num() > 0)
	{
		FGameplayAbilityTargetData_ActorArray* NewData = new FGameplayAbilityTargetData_ActorArray();
		NewData->TargetActorArray.Append(TargetActors);
		TargetData.Add(NewData);
	}
}
