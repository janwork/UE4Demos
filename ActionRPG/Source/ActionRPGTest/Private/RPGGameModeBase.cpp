// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameModeBase.h"
#include "RPGGameStateBase.h"
#include "RPGPlayerControllerBase.h"


ARPGGameModeBase::ARPGGameModeBase()
{
	// 绑定新的类
	GameStateClass = ARPGGameStateBase::StaticClass();
	PlayerControllerClass = ARPGPlayerControllerBase::StaticClass();
	bGameOver = false;
}

void ARPGGameModeBase::GameOver()
{
	if (bGameOver == false) {
		
		K2_OnGameOver();
		bGameOver = true;
	}
}

void ARPGGameModeBase::ResetLevel()
{
	K2_DoRestart();
}

bool ARPGGameModeBase::HasMatchEnded() const
{
	return bGameOver;
}
