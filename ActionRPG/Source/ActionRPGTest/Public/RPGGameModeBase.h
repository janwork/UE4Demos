// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RPGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPGTEST_API ARPGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARPGGameModeBase();

	UFUNCTION(BlueprintCallable, Category=Game)
		virtual void GameOver();

	UFUNCTION(BlueprintImplementableEvent, Category = Game, meta = (DisplayName = "DoRestart", ScriptName = "DoRestart"))
		void K2_DoRestart();

	UFUNCTION(BlueprintImplementableEvent, Category = Game, meta = (DisplayName = "OnGameOver", ScriptName = "OnGameOver"))
		void K2_OnGameOver();


	virtual void ResetLevel() override;

	virtual bool HasMatchEnded() const override;




public:
	UPROPERTY(BlueprintReadOnly, Category = Game)
		uint32 bGameOver : 1;



	
};
