// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGTypes.h"
#include "AbilitySystemInterface.h"
#include "RPGInventoryInterface.h"
#include "UObject/ScriptInterface.h"
#include "Abilities/RPGAbilitySystemComponent.h"
#include "Abilities/RPGAttributeSet.h"
#include "RPGCharacterBase.generated.h"

class URPGGameplayAbility;// ��ǰ����
class UGameplayEffect;

UCLASS()
class ACTIONRPGTEST_API ARPGCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacterBase();

public:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	virtual void OnRep_Controller() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

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

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		bool ActivateAbilitiesWithItemSlot(FRPGItemSlot ItemSlot, bool bAllowRemoteActivation = true);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void GetActivateAbilitiesWithItemSlot(FRPGItemSlot ItemSlot, TArray<URPGGameplayAbility*>& ActiveAbilities);

	// �Ƿ񼤻�ļ���
	UFUNCTION(BlueprintCallable, Category = "Abilities")
		bool ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation = true);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<URPGGameplayAbility*>& ActiveAbilities);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		bool GetCooldownRemainingForTag(FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration);

protected:
	// Called every frame

	UPROPERTY(EditAnywhere, Replicated, Category = Abilities)
		int32 CharacterLevel;
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
		TArray<TSubclassOf<URPGGameplayAbility>> GameplayAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TMap<FRPGItemSlot, TSubclassOf<URPGGameplayAbility>> DefaultSlottedAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
		TArray<TSubclassOf<UGameplayEffect>> PassiveGameplayEffects;

	UPROPERTY()
		URPGAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		URPGAttributeSet* AttributeSet;

	UPROPERTY()
		TScriptInterface<IRPGInventoryInterface> InventorySource;

	UPROPERTY()
		int32 bAbilitiesInitialized;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Inventory)
		TMap<FRPGItemSlot, FGameplayAbilitySpecHandle> SlottedAbilities;

	FDelegateHandle InventoryUpdateHandle;
	FDelegateHandle InventoryLoadedHandle;

	UFUNCTION(BlueprintImplementableEvent)
		void OnMoveSpeedChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags);

	void OnItemSlotChanged(FRPGItemSlot ItemSlot, URPGItem* Item);
	void RefreshSlottedGameplayAbilities();

	void AddStartupGameplayAbilities(); //Ӧ�� gameplayAbilities and Effects;

	void RemoveStartupGameplayAbilities(); // �Ƴ� gameplayAbilities and Effects

	void AddSlottedGameplayAbilities();

	void FillSlottedGameplayAbilities(TMap<FRPGItemSlot, FGameplayAbilitySpec>& SlottedAbilitySpecs);

	void RemoveSlottedGameplayAbilities(bool bRemoveAll);

	friend URPGAttributeSet;

};
