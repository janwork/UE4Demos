// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYSLATE_API MySlateInternation
{
public:
	static void Register(FText Value) {
		return;
	}
};


#define LOCTEXT_NAMESPACE "MySlateMenu"

MySlateInternation::Register(LOCTEXT("Menu", "Menu"));
MySlateInternation::Register(LOCTEXT("StartGame", "StartGame"));
MySlateInternation::Register(LOCTEXT("GameOption", "GameOption"));
MySlateInternation::Register(LOCTEXT("QuitGame", "QuitGame"));

MySlateInternation::Register(LOCTEXT("NewGame", "NewGame"));
MySlateInternation::Register(LOCTEXT("LoadRecord", "LoadRecord"));
MySlateInternation::Register(LOCTEXT("ChooseRecord", "ChooseRecord"));
MySlateInternation::Register(LOCTEXT("RecordName", "RecordName"));
MySlateInternation::Register(LOCTEXT("EnterGame", "EnterGame"));
MySlateInternation::Register(LOCTEXT("RecordNameHint", "Input Record Name!")); // ´æµµÃû
MySlateInternation::Register(LOCTEXT("NameRepeateHint", "Record Name Repeated!"));


MySlateInternation::Register(LOCTEXT("Chinese", "Chinese"));
MySlateInternation::Register(LOCTEXT("English", "English"));
MySlateInternation::Register(LOCTEXT("Music", "Music"));
MySlateInternation::Register(LOCTEXT("Sound", "Sound"));
MySlateInternation::Register(LOCTEXT("GoBack", "GoBack"));


#undef LOCTEXT_NAMESPACE
