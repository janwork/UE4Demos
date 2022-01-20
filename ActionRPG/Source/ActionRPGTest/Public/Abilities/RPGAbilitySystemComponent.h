// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionRPGTest/ActionRPGTest.h"
#include "AbilitySystemComponent.h"
#include "Abilities/RPGAbilityTypes.h"
#include "Abilities/RPGGameplayAbility.h"
#include "RPGAbilitySystemComponent.generated.h"

class UPRGGameplayAbility;

/**
 * 
 */
UCLASS()
class ACTIONRPGTEST_API URPGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	URPGAbilitySystemComponent();

	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<URPGGameplayAbility*>& ActiveAbilities);

	int32 GetDefaultAbilityLevel() const;

	static URPGAbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);

};
