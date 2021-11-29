// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/RPGAttributeSet.h"


//构造函数
URPGAttributeSet::URPGAttributeSet():Health(1.f),MaxHealth(1.f),Mana(0.f),MaxMana(0.f), AttackPower(1.f),DefensePower(1.f),MoveSpeed(1.f),Damage(0.f)
{

}

//注册属性
void URPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(URPGAttributeSet, Health);


	DOREPLIFETIME(URPGAttributeSet, MaxHealth);
	DOREPLIFETIME(URPGAttributeSet, Mana);
	DOREPLIFETIME(URPGAttributeSet, MaxMana);
	DOREPLIFETIME(URPGAttributeSet, AttackPower);
	DOREPLIFETIME(URPGAttributeSet, DefensePower);
	DOREPLIFETIME(URPGAttributeSet, MoveSpeed);
	//DOREPLIFETIME(URPGAttributeSet, Damage);
}

// 属性改变通知
void URPGAttributeSet::OnRep_Health(const FGameplayAttributeData& oldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Health, oldValue);
}

void URPGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& oldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth, oldValue);

}

void URPGAttributeSet::OnRep_Mana(const FGameplayAttributeData& oldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Mana, oldValue);
}

void URPGAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& oldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxMana, oldValue);

}

void URPGAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& oldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackPower, oldValue);

}

void URPGAttributeSet::OnRep_DefensePower(const FGameplayAttributeData& oldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DefensePower, oldValue);

}

void URPGAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& oldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MoveSpeed, oldValue);

}

