// Fill out your copyright notice in the Description page of Project Settings.



#include "UI/Widget/SMySlateMenuWidget.h"
#include "UI/Widget/SMySlateMenuItemWidget.h"
#include "UI/Widget/SMySlateGameOptionWidget.h"
#include "UI/Widget/SMySlateNewGameWidget.h"
#include "UI/Widget/SMySlateChooseRecordWidget.h"
#include "SlateOptMacros.h"
#include "Internationalization/Internationalization.h"
#include "UI/Style/MySlateStyle.h"
#include "UI/Style/MySlateMenuWidgetStyle.h"
#include "Data/MySlateDataHandle.h"
#include "Common/MySlateHelper.h"
#include "GamePlay/MySlateMenuPlayerController.h"
#include "Kismet/GameplayStatics.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySlateMenuWidget::Construct(const FArguments& InArgs)
{

	MenuStyle = &MySlateStyle::Get().GetWidgetStyle<FMySlateMenuStyle>("BPMySlateMenuStyle");

	FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
	
	ChildSlot
	[
		SAssignNew(RootSizeBox, SBox)
		[
			SNew(SOverlay)
				+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(FMargin(0.f,50.f,0.f,0.f))
				[
					SNew(SImage)
					.Image(&MenuStyle->MenuBackgroundBrush)
				]

				+SOverlay::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.Padding(FMargin(0.f,25.f,0.f,0.f))
				[
					SNew(SImage)
					.Image(&MenuStyle->LeftIconBrush)
				]

				+SOverlay::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Center)
				.Padding(FMargin(0.f,25.f,0.f,0.f))
				[
					SNew(SImage)
					.Image(&MenuStyle->RightIconBrush)
				]

				+SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				[
					SNew(SBox)
					.WidthOverride(400.f)
					.HeightOverride(100.f)
					[
						SNew(SBorder)
						.BorderImage(&MenuStyle->TitleBorderBrush)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SAssignNew(TitleText, STextBlock)
							.Font(MenuStyle->TitleFont)
							.Text(NSLOCTEXT("MySlateMenu","Menu", "Menu"))
						]
					]

				]


				+SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				.Padding(FMargin(0.f, 130.f, 0.f, 0.f))
				[
					SAssignNew(ContentBox, SVerticalBox)
				]


		]

	];


	//创建一个自定义按钮
	/*ContentBox->AddSlot()[
		SNew(SMySlateMenuItemWidget)
		.ItemText(NSLOCTEXT("MySlateMenu", "StartGame", "StartGame"))
		.ItemType(EMenuItem::StartGame)
		.OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked)
	];*/


	InitializedMenuList();

	InitializedAniamtion();

	FSlateApplication::Get().PlaySound(MenuStyle->MenuBackgroundMusic);

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


void SMySlateMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{

	if (ControlLocked) return;

	ControlLocked = true;

	switch (ItemType)
	{
	case EMenuItem::StartGame:
		PlayClose(EMenuType::StartGame);
		break;
	case EMenuItem::GameOption:
		PlayClose(EMenuType::GameOption);
		break;
	case EMenuItem::QuitGame:
		//ChooseWidget(EMenuType::StartGame);
		MySlateHelper::PlayerSoundAndCall(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(),MenuStyle->ExitGameSound, this, &SMySlateMenuWidget::QuitGame);
		ControlLocked = false;
		break;
	case EMenuItem::NewGame:
		PlayClose(EMenuType::NewGame);
		break;
	case EMenuItem::LoadRecord:
		PlayClose(EMenuType::ChooseRecord);
		break;
	case EMenuItem::StartGameGoBack:
		PlayClose(EMenuType::MainMenu);
		break;
	case EMenuItem::GameOptionGoBack:
		PlayClose(EMenuType::MainMenu);
		break;
	case EMenuItem::NewGameGoBack:
		PlayClose(EMenuType::StartGame);
		break;
	case EMenuItem::ChoooseRecordGoBack:
		PlayClose(EMenuType::StartGame);
		break;
	case EMenuItem::EnterGame:
		MySlateHelper::PlayerSoundAndCall(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(),MenuStyle->StartGameSound, this, &SMySlateMenuWidget::EnterGame);
		break;
	case EMenuItem::EnterRecord:
		MySlateHelper::PlayerSoundAndCall(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(),MenuStyle->StartGameSound, this, &SMySlateMenuWidget::EnterGame);
		break;
	}
}

void SMySlateMenuWidget::ChangeCulture(ECultureTeam Culture)
{
	MySlateDataHandle::Get()->ChangeLocalizationCulture(Culture);
}

void SMySlateMenuWidget::ChangeVolume(const float MusicVal, const float SoundVal)
{
	MySlateDataHandle::Get()->ResetMenuVolume(MusicVal, SoundVal);
}

void SMySlateMenuWidget::InitializedMenuList()
{
	/*RootSizeBox->SetWidthOverride(600.f);
	RootSizeBox->SetHeightOverride(510.f);*/

	TArray<TSharedPtr<SCompoundWidget>> MainMenuList;
	MainMenuList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "StartGame", "StartGame")).ItemType(EMenuItem::StartGame).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "GameOption", "GameOption")).ItemType(EMenuItem::GameOption).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "QuitGame", "QuitGame")).ItemType(EMenuItem::QuitGame).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::MainMenu, MakeShareable(new MenuGroup(NSLOCTEXT("MySlateMenu", "Menu", "Menu"), 510.f, &MainMenuList)));


	TArray<TSharedPtr<SCompoundWidget>> StartGameList;
	StartGameList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "NewGame", "NewGame")).ItemType(EMenuItem::NewGame).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "LoadRecord", "LoadRecord")).ItemType(EMenuItem::LoadRecord).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::StartGame, MakeShareable(new MenuGroup(NSLOCTEXT("MySlateMenu", "StartGame", "StartGame"), 510.f, &StartGameList)));


	TArray<TSharedPtr<SCompoundWidget>> GameOptionList;
	SAssignNew(GameOptionWidget, SMySlateGameOptionWidget).ChangeCulture(this, &SMySlateMenuWidget::ChangeCulture).ChangeVolume(this, &SMySlateMenuWidget::ChangeVolume);
	GameOptionList.Add(GameOptionWidget);
	GameOptionList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "GoBack", "GoBack")).ItemType(EMenuItem::GameOptionGoBack).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("MySlateMenu", "GameOption", "GameOption"), 610.f, &GameOptionList)));


	TArray<TSharedPtr<SCompoundWidget>> NewGameList;
	SAssignNew(NewGameWidget, SMySlateNewGameWidget);
	NewGameList.Add(NewGameWidget);
	NewGameList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "EnterGame", "EnterGame")).ItemType(EMenuItem::EnterGame).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	NewGameList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "GoBack", "GoBack")).ItemType(EMenuItem::NewGameGoBack).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::NewGame, MakeShareable(new MenuGroup(NSLOCTEXT("MySlateMenu", "NewGame", "NewGame"), 510.f, &NewGameList)));


	TArray<TSharedPtr<SCompoundWidget>> ChooseRecordList;
	SAssignNew(ChooseRecordWidget, SMySlateChooseRecordWidget);
	ChooseRecordList.Add(NewGameWidget);
	ChooseRecordList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "EnterRecord", "EnterGame")).ItemType(EMenuItem::EnterRecord).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	NewGameList.Add(SNew(SMySlateMenuItemWidget).ItemText(NSLOCTEXT("MySlateMenu", "GoBack", "GoBack")).ItemType(EMenuItem::ChoooseRecordGoBack).OnClicked(this, &SMySlateMenuWidget::MenuItemOnClicked));
	MenuMap.Add(EMenuType::ChooseRecord, MakeShareable(new MenuGroup(NSLOCTEXT("MySlateMenu", "LoadRecord", "LoadRecord"), 510, &ChooseRecordList)));


}

void SMySlateMenuWidget::ChooseWidget(EMenuType::Type WidgetType)
{
	IsMenuShow = WidgetType != EMenuType::None;

	ContentBox->ClearChildren();

	if (WidgetType == EMenuType::None) {
		return;
	}

	for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It((*MenuMap.Find(WidgetType))->ChildWidget); It; ++It){
		ContentBox->AddSlot().AutoHeight()[(*It)->AsShared()];
	}

	TitleText->SetText((*MenuMap.Find(WidgetType))->MenuName);

}

void SMySlateMenuWidget::ResetWidgetSize(float NewWidth, float NewHeight)
{
	RootSizeBox->SetWidthOverride(NewWidth);
	if (NewHeight < 0) {
		return;
	}

	RootSizeBox->SetHeightOverride(NewHeight);
}

void SMySlateMenuWidget::InitializedAniamtion()
{
	const float StartDelay = 0.3f;

	const float AnimDuration = 0.6f;

	MenuAniamtion = FCurveSequence();
	MenuCurve = MenuAniamtion.AddCurve(StartDelay, AnimDuration, ECurveEaseFunction::QuadInOut);

	ResetWidgetSize(600.0f, 510.f);

	ChooseWidget(EMenuType::MainMenu);

	ControlLocked = false;

	AnimState = EMenuAnim::Stop;

	MenuAniamtion.JumpToEnd();

}

void SMySlateMenuWidget::PlayClose(EMenuType::Type NewMenu)
{
	CurrentMenu = NewMenu;

	CurrentHeight = (*MenuMap.Find(NewMenu))->MenuHeight;

	AnimState = EMenuAnim::Close;

	MenuAniamtion.PlayReverse(this->AsShared());

	FSlateApplication::Get().PlaySound(MenuStyle->MenuItemChangeSound);

}

void SMySlateMenuWidget::QuitGame()
{
	Cast<AMySlateMenuPlayerController>(UGameplayStatics::GetPlayerController(GWorld, 0))->ConsoleCommand("quit");
}

void SMySlateMenuWidget::EnterGame()
{
		ControlLocked = false;
}

void SMySlateMenuWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	switch (AnimState)
	{
	case EMenuAnim::Stop:
		break;
	case EMenuAnim::Close:
		if (MenuAniamtion.IsPlaying()) {
			ResetWidgetSize(MenuCurve.GetLerp() * 600.f, -1.0f);

			if (MenuCurve.GetLerp() < 0.6f && IsMenuShow)
			{
				ChooseWidget(EMenuType::None);
			}
		}
		else {
			AnimState = EMenuAnim::Open;
			MenuAniamtion.Play(this->AsShared());
		}

		break;
	case EMenuAnim::Open:
		if (MenuAniamtion.IsPlaying()) {
			ResetWidgetSize(MenuCurve.GetLerp() * 600.f, CurrentHeight);

			if (MenuCurve.GetLerp() > 0.6f && !IsMenuShow) {
				ChooseWidget(CurrentMenu);
			}
		}
		 
		if (MenuAniamtion.IsAtEnd()) {
			AnimState = EMenuAnim::Stop;
			ControlLocked = false;
		}
		break;
	default:
		break;
	}
}
