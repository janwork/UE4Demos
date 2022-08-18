// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SMySlateGameOptionWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/MySlateStyle.h"
#include "UI/Style/MySlateMenuWidgetStyle.h"
#include "Data/MySlateDataHandle.h"
#include "Internationalization/Internationalization.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySlateGameOptionWidget::Construct(const FArguments& InArgs)
{

	MenuStyle = &MySlateStyle::Get().GetWidgetStyle<FMySlateMenuStyle>("BPMySlateMenuStyle");

	ChangeCulture = InArgs._ChangeCulture;
	ChangeVolume = InArgs._ChangeVolume;
	
	ChildSlot
	[
		SNew(SBox)
			.WidthOverride(500.f)
			.HeightOverride(510.f)
			[
					SNew(SOverlay)
						+SOverlay::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SImage)
							.Image(&MenuStyle->GameOptionBrush)
						]
						
						+SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.Padding(FMargin(50.f))
						[

							SNew(SVerticalBox)
								+SVerticalBox::Slot()
								.HAlign(HAlign_Fill)
								.VAlign(VAlign_Fill)
								.FillHeight(1.f)
							    [
									SNew(SHorizontalBox)
										+SHorizontalBox::Slot()
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										[
											SAssignNew(ZhCheckBox,SCheckBox)
											.OnCheckStateChanged(this, &SMySlateGameOptionWidget::ZhCheckBoxStateChanged)
											[
												SNew(STextBlock)
												.Font(MenuStyle->Font_40)
												.ColorAndOpacity(MenuStyle->FontColor_Black)
												.Text(NSLOCTEXT("MySlateMenu", "Chinese", "Chinese"))

											]
											
										]

										+SHorizontalBox::Slot()
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										[
											SAssignNew(EnCheckBox, SCheckBox)
											.OnCheckStateChanged(this, &SMySlateGameOptionWidget::EnCheckBoxStateChanged)
											[
												SNew(STextBlock)
												.Font(MenuStyle->Font_40)
												.ColorAndOpacity(MenuStyle->FontColor_Black)
												.Text(NSLOCTEXT("MySlateMenu", "English", "English"))
											]
										]
								]

								+SVerticalBox::Slot()
								.HAlign(HAlign_Fill)
								.VAlign(VAlign_Fill)
								.FillHeight(1.f)
								[
									SNew(SOverlay)
										+SOverlay::Slot()
										.HAlign(HAlign_Left)
										.VAlign(VAlign_Center)
										[
											SNew(STextBlock)
											.Font(MenuStyle->Font_40)
											.ColorAndOpacity(MenuStyle->FontColor_Black)
											.Text(NSLOCTEXT("MySlateMenu", "Music", "Music"))
										]

										+SOverlay::Slot()
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										[
											SNew(SBox)
											.WidthOverride(240.f)
											[
												SNew(SOverlay)
													+SOverlay::Slot()
													.HAlign(HAlign_Fill)
													.VAlign(VAlign_Center)
													.Padding(FMargin(30.f, 0.f))
													[
														SNew(SImage)
														.Image(&MenuStyle->SliderBarBrush)
													]
													

													+SOverlay::Slot()
													.HAlign(HAlign_Fill)
													.VAlign(VAlign_Center)
													[
														SAssignNew(MusicSlider,SSlider)
														.Style(&MenuStyle->SliderStyle)
														.OnValueChanged(this, &SMySlateGameOptionWidget::MusicSliderChanged)
													]


													+SOverlay::Slot()
													.HAlign(HAlign_Right)
													.VAlign(VAlign_Center)
													[
														SAssignNew(MusicText, STextBlock)
														.Font(MenuStyle->Font_40)
														.ColorAndOpacity(MenuStyle->FontColor_Black)
													]


											]
										]
										
								]


								+SVerticalBox::Slot()
								.HAlign(HAlign_Fill)
								.VAlign(VAlign_Fill)
								.FillHeight(1.f)
								[
									SNew(SOverlay)
										+SOverlay::Slot()
										.HAlign(HAlign_Left)
										.VAlign(VAlign_Center)
										[
											SNew(STextBlock)
											.Font(MenuStyle->Font_40)
											.ColorAndOpacity(MenuStyle->FontColor_Black)
											.Text(NSLOCTEXT("MySlateMenu", "Sound", "Sound"))
										]

										+SOverlay::Slot()
										.HAlign(HAlign_Center)
										.VAlign(VAlign_Center)
										[
											SNew(SBox)
											.WidthOverride(240.f)
											[
												SNew(SOverlay)
													+SOverlay::Slot()
													.HAlign(HAlign_Fill)
													.VAlign(VAlign_Center)
													.Padding(FMargin(30.f, 0.f))
													[
														SNew(SImage)
														.Image(&MenuStyle->SliderBarBrush)
													]
													

													+SOverlay::Slot()
													.HAlign(HAlign_Fill)
													.VAlign(VAlign_Center)
													[
														SAssignNew(SoundSlider,SSlider)
														.Style(&MenuStyle->SliderStyle)
														.OnValueChanged(this, &SMySlateGameOptionWidget::SoundSliderChanged)
													]


													+SOverlay::Slot()
													.HAlign(HAlign_Right)
													.VAlign(VAlign_Center)
													[
														SAssignNew(SoundText, STextBlock)
														.Font(MenuStyle->Font_40)
														.ColorAndOpacity(MenuStyle->FontColor_Black)
													]
											]
										]	
								]

						]	
			]
	];

	MusicSlider->SetValue(MySlateDataHandle::Get()->MusicVolume);
	SoundSlider->SetValue(MySlateDataHandle::Get()->SoundVolume);
	MusicSliderChanged(MySlateDataHandle::Get()->MusicVolume);
	SoundSliderChanged(MySlateDataHandle::Get()->SoundVolume);

	StyleInitialize();
	
}

void SMySlateGameOptionWidget::StyleInitialize()
{
		ZhCheckBox->SetUncheckedImage(&MenuStyle->UnCheckBoxBrush);
		ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckBoxBrush);
		ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckBoxBrush);
		ZhCheckBox->SetCheckedImage(&MenuStyle->CheckBoxBrush);
		ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckBoxBrush);
		ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckBoxBrush);

		EnCheckBox->SetUncheckedImage(&MenuStyle->UnCheckBoxBrush);
		EnCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckBoxBrush);
		EnCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckBoxBrush);
		EnCheckBox->SetCheckedImage(&MenuStyle->CheckBoxBrush);
		EnCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckBoxBrush);
		EnCheckBox->SetCheckedPressedImage(&MenuStyle->CheckBoxBrush);


		switch(MySlateDataHandle::Get()->CurrentCulture)
		{
		case  ECultureTeam::ZH:
			ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
			EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
			break;
		case ECultureTeam::EN:
			EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
			ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
			break;
		}
	
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMySlateGameOptionWidget::ZhCheckBoxStateChanged(ECheckBoxState NewState)
{
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);

	ChangeCulture.ExecuteIfBound(ECultureTeam::ZH);
	//MySlateDataHandle::Get()->ChangeLocalizationCulture(ECultureTeam::ZH);
}

void SMySlateGameOptionWidget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);

	ChangeCulture.ExecuteIfBound(ECultureTeam::EN);
	//MySlateDataHandle::Get()->ChangeLocalizationCulture(ECultureTeam::EN);
}

void SMySlateGameOptionWidget::MusicSliderChanged(float Value)
{
	MusicText->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value*100)) +  FString("%")));
	//MySlateDataHandle::Get()->ResetMenuVolume(Value, -1.f);
	ChangeVolume.ExecuteIfBound(Value, -1.f);
}

void SMySlateGameOptionWidget::SoundSliderChanged(float Value)
{
	SoundText->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value*100)) +  FString("%")));
	//MySlateDataHandle::Get()->ResetMenuVolume(-1.f, Value);
	ChangeVolume.ExecuteIfBound(-1.f, Value);
}

