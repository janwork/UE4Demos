// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGTypes.h"
#include "AbilitySystemInterface.h"
#include "Abilities/RPGAbilitySystemComponent.h"
#include "Abilities/RPGAttributeSet.h"
#include "RPGCharacterBase.generated.h"

class URPGGameplayAbility;// 提前声明
class UGameplayEffect;

UCLASS()
class ACTIONRPGTEST_API ARPGCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void UnPossessed() override;

	virtual void OnRep_Controller() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable)
		virtual float GetHealth() const;

	UFUNCTION(BlueprintCallable)
		virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable)
		virtual float GetMana() const;

	UFUNCTION(BlueprintCallable)
		virtual float GetMaxMana() const;

	UFUNCTION(BlueprintCallable)
		virtual float GetAttackPower() const;

	UFUNCTION(BlueprintCallable)
		virtual float GetDefensePower() const;

	UFUNCTION(BlueprintCallable)
		virtual float GetMoveSpeed() const;

	UFUNCTION(BlueprintCallable)
		virtual int32 GetCharacterLevel() const;

	UFUNCTION(BlueprintCallable)
		virtual bool SetCharacterLevel(int32 NewLevel);

	void AddStartupGameplayAbilities(); //应用 gameplayAbilities and Effects;

	void RemoveStartupGameplayAbilities(); // 移除 gameplayAbilities and Effects

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		bool ActivateAbilitiesWithItemSlot(FRPGItemSlot ItemSlot, bool bAllowRemoteActivation = true);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void GetActivateAbilitiesWithItemSlot(FRPGItemSlot ItemSlot, TArray<URPGGameplayAbility*>& ActiveAbilities);



	// 是否激活的技能
	UFUNCTION(BlueprintCallable,  Category = "Abilities")
		bool ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation = true);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<URPGGameplayAbility*>& ActiveAbilities);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		bool GetCooldownRemainingForTag(FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration);

public:

	UPROPERTY()
		URPGAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		URPGAttributeSet* AttributeSet;

	UPROPERTY()
		int32 bAbilitiesInitialized;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
		TMap<FRPGItemSlot, FGameplayAbilitySpecHandle> SlottedAbilities;

	UPROPERTY(EditAnywhere, Replicated, Category = Abilities)
		int32 CharacterLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
		TArray<TSubclassOf<URPGGameplayAbility>> GameplayAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
		TArray<TSubclassOf<UGameplayEffect>> PassiveGameplayEffects;







};
