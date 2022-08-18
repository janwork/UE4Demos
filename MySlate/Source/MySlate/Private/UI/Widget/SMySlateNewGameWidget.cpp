// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SMySlateNewGameWidget.h"
#include "UI/Style/MySlateStyle.h"
#include "UI/Style/MySlateMenuWidgetStyle.h"
#include "SlateOptMacros.h"
#include "Data/MySlateDataHandle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySlateNewGameWidget::Construct(const FArguments& InArgs)
{

	MenuStyle = &MySlateStyle::Get().GetWidgetStyle<FMySlateMenuStyle>("BPMySlateMenuStyle");
	


	ChildSlot
	[
		SAssignNew(RootSizeBox, SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
				+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SImage)
					.Image(&MenuStyle->MenuItemBrush)
				]

				+SOverlay::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.Padding(FMargin(20.f, 0.f, 0.f, 0.f))
				[
					SNew(STextBlock)
					.Font(MenuStyle->Font_40)
					.Text(NSLOCTEXT("MySlateMenu", "NewGame", "NewGame"))
				]

				+ SOverlay::Slot()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.Padding(FMargin(0.f, 0.f, 20.f, 0.f))
					[
						SNew(SBox)
						.WidthOverride(300.f)
						.HeightOverride(100.f)
						[
							SAssignNew(EditTextBox, SEditableTextBox)
							.HintText(NSLOCTEXT("MySlateMenu",  "RecordNameHint","RecordNameHint"))
							.Font(MenuStyle->Font_30)
						]

				]


		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

bool SMySlateNewGameWidget::AllowEnterGame()
{
	FText NewRecordName = EditTextBox->GetText();

	if (NewRecordName.ToString().IsEmpty()) {
		return false;
	}

	for (TArray<FString>::TIterator It(MySlateDataHandle::Get()->RecordDataList); It; ++It)
	{
		if ((*It).Equals(NewRecordName.ToString())) {
			EditTextBox->SetText(FText::FromString(""));

			EditTextBox->SetHintText(NSLOCTEXT("MySlateMenu", "RecordNameHint", "RecordNameHint"));


			return false;
		}
	}


	MySlateDataHandle::Get()->RecordName = NewRecordName.ToString();

	return true;
}
