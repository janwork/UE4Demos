// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/RPGGameplayAbility.h"
#include "Abilities/RPGTargetType.h"
#include "Abilities/RPGAbilitySystemComponent.h"
#include "Abilities/RPGAbilityTypes.h"
#include "RPGCharacterBase.h"


URPGGameplayAbility::URPGGameplayAbility()
{

}

FRPGGameplayEffectContainerSpec URPGGameplayAbility::MakeEffectContainerFromContainer(const FRPGGameplayEffectContainer& Container, const FGameplayEventData& EventData, int32 OverrideGameplayLevel /*= -1*/)
{
	FRPGGameplayEffectContainerSpec ReturnSpec;
	AActor* OwningActor = GetOwningActorFromActorInfo();
	ARPGCharacterBase* OwningCharacter = Cast<ARPGCharacterBase>(OwningActor);
	URPGAbilitySystemComponent* OwningASC = URPGAbilitySystemComponent::GetAbilitySystemComponentFromActor(OwningActor);
	if (OwningASC)
	{
		if (Container.TargetType.Get())
		{
			TArray<FHitResult> HitResults;
			TArray<AActor*> TargetActors;
			const URPGTargetType* TargetTypeCDO = Container.TargetType.GetDefaultObject();

			AActor* AvatarActor = GetAvatarActorFromActorInfo();
			TargetTypeCDO->GetTargets(OwningCharacter, AvatarActor, EventData, HitResults, TargetActors);

			ReturnSpec.AddTargets(HitResults, TargetActors);
		}

		if (OverrideGameplayLevel == INDEX_NONE)
		{
			OverrideGameplayLevel = this->GetAbilityLevel();
		}

		for (const TSubclassOf<UGameplayEffect>& EffectClass : Container.TargetGameplayEffectClasses)
		{
			ReturnSpec.TargetGameplayEffectSpecs.Add(MakeOutgoingGameplayEffectSpec(EffectClass, OverrideGameplayLevel));
		}
	}


	return ReturnSpec;
}

FRPGGameplayEffectContainerSpec URPGGameplayAbility::MakeEffectContainerSpec(FGameplayTag ContainerTag, const FGameplayEventData& EventData, int32 OverrideGameplayLevel /*= -1*/)
{
	FRPGGameplayEffectContainer* FoundContainer = EffectContainerMap.Find(ContainerTag);

	if (FoundContainer)
	{
		return MakeEffectContainerFromContainer(*FoundContainer, EventData, OverrideGameplayLevel);
	}

	return FRPGGameplayEffectContainerSpec();
}

TArray<FActiveGameplayEffectHandle> URPGGameplayAbility::ApplyEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec)
{
	TArray<FActiveGameplayEffectHandle> AllEffects;

	for (const FGameplayEffectSpecHandle& SpecHandle : ContainerSpec.TargetGameplayEffectSpecs)
	{
		AllEffects.Append(K2_ApplyGameplayEffectSpecToTarget(SpecHandle, ContainerSpec.TargetData));

	}

	return AllEffects;
}

TArray<FActiveGameplayEffectHandle> URPGGameplayAbility::ApplyEffectContainer(FGameplayTag ContainerTag, const FGameplayEventData& EventData, int32 OverrideGameplayLevel /*= -1*/)
{
	FRPGGameplayEffectContainerSpec Spec = MakeEffectContainerSpec(ContainerTag, EventData, OverrideGameplayLevel);
	return ApplyEffectContainerSpec(Spec);
}
