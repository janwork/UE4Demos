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

}
