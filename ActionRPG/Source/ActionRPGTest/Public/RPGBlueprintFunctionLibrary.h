// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ActionRPGTest.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Abilities/RPGAbilityTypes.h"
#include "RPGBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class URPGBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:

	UFUNCTION(BlueprintPure,Category = Loading)
		static bool IsInEditor();

	UFUNCTION(BlueprintPure, Category = Ability)
		static bool DoesEffectContainerSpecHaveEffects(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	UFUNCTION(BlueprintPure, Category = Ability)
		static bool DoesEffectContainerSpecHaveTargets(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	UFUNCTION(BlueprintCallable, Category = Ability, meta = (AutoCreateRefTerm = "HitResults,TargetActors"))
		static FRPGGameplayEffectContainerSpec AddTargetsToEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec, const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors);

	UFUNCTION(BlueprintCallable, Category = Ability)
		static TArray<FActiveGameplayEffectHandle> ApplyExternalEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	UFUNCTION(BlueprintPure, Category = "Project")
		static FString GetProjectVersion();

	UFUNCTION(BlueprintCallable, Category = Loading)
		static void PlayLoadingScreen(bool bPlayUntilStopped, float PlayTime);


	UFUNCTION(BlueprintCallable, Category = Loading)
		static void StopLoadingScreen();
};
