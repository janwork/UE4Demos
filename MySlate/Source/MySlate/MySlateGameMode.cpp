// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySlateGameMode.h"
#include "MySlateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMySlateGameMode::AMySlateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
