// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/MySlateTypes.h"
#include "Widgets/SCompoundWidget.h"



struct MenuGroup
{
	FText MenuName;
	float MenuHeight;
	TArray<TSharedPtr<SCompoundWidget>> ChildWidget;

	MenuGroup(const FText Name, const float Height, TArray<TSharedPtr<SCompoundWidget>>* Children)
	{
		MenuName = Name;
		MenuHeight = Height;
		
		for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It(*Children); It; ++It)
		{
			ChildWidget.Add(*It);
		}

	}
};

class SBox;
class STextBlock;
class SMySlateGameOptionWidget;
class SMySlateNewGameWidget;
class SMySlateChooseRecordWidget;



/**
 * 
 */
class MYSLATE_API SMySlateMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlateMenuWidget)
	{}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

private:

	void MenuItemOnClicked(EMenuItem::Type ItemType);

	void ChangeCulture(ECultureTeam Culture);

	void ChangeVolume(const float MusicVal, const float SoundVal);

	void InitializedMenuList();

	void ChooseWidget(EMenuType::Type WidgetType);

	void ResetWidgetSize(float NewWidth, float NewHeight);

	void InitializedAniamtion();

	void PlayClose(EMenuType::Type NewMenu);

	void QuitGame();

	void EnterGame();

private:

	TSharedPtr<SBox> RootSizeBox;

	const struct FMySlateMenuStyle* MenuStyle;

	TSharedPtr<STextBlock> TitleText;

	TSharedPtr<SVerticalBox> ContentBox;

	TMap<EMenuType::Type, TSharedPtr<MenuGroup>> MenuMap;

	TSharedPtr<SMySlateGameOptionWidget> GameOptionWidget;

	TSharedPtr<SMySlateNewGameWidget> NewGameWidget;

	TSharedPtr<SMySlateChooseRecordWidget> ChooseRecordWidget;

	FCurveSequence MenuAniamtion;

	FCurveHandle MenuCurve;

	float CurrentHeight;

	bool IsMenuShow;

	bool ControlLocked;

	EMenuAnim::Type AnimState;

	EMenuType::Type CurrentMenu;

};
