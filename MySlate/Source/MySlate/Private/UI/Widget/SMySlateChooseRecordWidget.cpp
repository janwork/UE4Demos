// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SMySlateChooseRecordWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/MySlateStyle.h"
#include "UI/Style/MySlateMenuWidgetStyle.h"
#include "Data/MySlateDataHandle.h"
#include "Widgets/Input/STextComboBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySlateChooseRecordWidget::Construct(const FArguments& InArgs)
{
	
	MenuStyle = &MySlateStyle::Get().GetWidgetStyle<FMySlateMenuStyle>("BPMySlateMenuStyle");

	for (TArray<FString>::TIterator It(MySlateDataHandle::Get()->RecordDataList); It; ++It)
	{
		OptionsSource.Add(MakeShareable(new FString(*It)));
	}

	
	ChildSlot
	[
		SNew(SBox)
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

				+SOverlay::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Center)
				.Padding(FMargin(0.f, 0.f, 20.f, 0.f))
				[
					SNew(SBox)
					.WidthOverride(300.f)
					.HeightOverride(60.f)
					[
							SAssignNew(RecordComboBox, STextComboBox)
							.Font(MenuStyle->Font_30)
							.OptionsSource(&OptionsSource)

					]
				]
		]
	];


	RecordComboBox->SetSelectedItem(OptionsSource[0]);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMySlateChooseRecordWidget::UpdateRecordName()
{
	MySlateDataHandle::Get()->RecordName = *RecordComboBox->GetSelectedItem().Get();
}
