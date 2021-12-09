// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGBlueprintFunctionLibrary.h"
#include "ActionRPGLoadingScreen/Public/ActionRPGLoadingScreen.h"

URPGBlueprintFunctionLibrary::URPGBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {

}

bool URPGBlueprintFunctionLibrary::IsInEditor()
{
	return GIsEditor;
}

bool URPGBlueprintFunctionLibrary::DoesEffectContainerSpecHaveEffects(const FRPGGameplayEffectContainerSpec& ContainerSpec)
{
	return ContainerSpec.HasVaildEffects();
}

bool URPGBlueprintFunctionLibrary::DoesEffectContainerSpecHaveTargets(const FRPGGameplayEffectContainerSpec& ContainerSpec)
{
	return ContainerSpec.HasVaildTargets();
}

FRPGGameplayEffectContainerSpec URPGBlueprintFunctionLibrary::AddTargetsToEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec, const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors)
{
	FRPGGameplayEffectContainerSpec NewSpec = ContainerSpec;
	NewSpec.AddTargets(HitResults, TargetActors);
	return NewSpec;
}

TArray<FActiveGameplayEffectHandle> URPGBlueprintFunctionLibrary::ApplyExternalEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec)
{
	TArray<FActiveGameplayEffectHandle> AllEffects;

	for (const FGameplayEffectSpecHandle& SpecHandle : ContainerSpec.TargetGameplayEffectSpecs)
	{
		if (SpecHandle.IsValid())
		{
			for (TSharedPtr<FGameplayAbilityTargetData> Data : ContainerSpec.TargetData.Data)
			{
				AllEffects.Append(Data->ApplyGameplayEffectSpec(*SpecHandle.Data.Get()));
			}
		}
	}

	return AllEffects;
}

FString URPGBlueprintFunctionLibrary::GetProjectVersion()
{
	FString ProjectVersion;
	GConfig->GetString(TEXT("/Script/EngineSettings.GeneralProjectSettings"), TEXT("ProjectVersion"), ProjectVersion, GGameIni);

	return ProjectVersion;
}

void URPGBlueprintFunctionLibrary::PlayLoadingScreen(bool bPlayUntilStopped, float PlayTime)
{
	IActionRPGLoadingScreenModule& LoadingScreenModule = IActionRPGLoadingScreenModule::Get();
	LoadingScreenModule.StartInGameLoadingScreen(bPlayUntilStopped, PlayTime);

}

void URPGBlueprintFunctionLibrary::StopLoadingScreen()
{
	IActionRPGLoadingScreenModule& LoadingScreenModule = IActionRPGLoadingScreenModule::Get();
	LoadingScreenModule.StopInGameLoadingScreen();
}
