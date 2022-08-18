// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
//class MYSLATE_API MySlateTypes
//{
//public:
//	MySlateTypes();
//	~MySlateTypes();
//};


UENUM()
enum class ECultureTeam: uint8
{
	EN = 0,
	ZH
};


namespace EMenuItem
{
	enum  Type
	{
		None,
		StartGame,
		GameOption,
		QuitGame,
		NewGame,
		LoadRecord,
		StartGameGoBack,
		GameOptionGoBack,
		NewGameGoBack,
		ChoooseRecordGoBack,
		EnterGame,
		EnterRecord
	};
}


namespace EMenuType
{
	enum Type
	{
		None,
		MainMenu,
		StartGame,
		GameOption,
		NewGame,
		ChooseRecord
	};
}

namespace EMenuAnim
{
	enum Type
	{
		Stop,
		Close,
		Open
	};
}

