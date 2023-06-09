// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestWidget.h"
#include "Components/VerticalBox.h"

void UQuestWidget::ChangeQuestObjectiveWidget()
{
	bIsVisibleWidget ? RemoveQuestObjectiveWidget() : CreateQuestObjectiveWidget();
	bIsVisibleWidget = !bIsVisibleWidget;
}

void UQuestWidget::CreateQuestObjectiveWidget()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandleWidget, this, &UQuestWidget::StartEventForCreate, TimerRate, false);
}

void UQuestWidget::RemoveQuestObjectiveWidget()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandleWidget, this, &UQuestWidget::StartEventForDelete, TimerRate, false);
}

void UQuestWidget::StartEventForCreate()
{
	AddObjectiveToVerticalBox(QuestVerticalBox, QuestWidgetList);
}

void UQuestWidget::StartEventForDelete()
{
	RemoveObjectiveToVerticalBox(QuestVerticalBox, QuestWidgetList);
}

void UQuestWidget::AddObjectiveToVerticalBox(UVerticalBox* VerticalBox, TArray<UUserWidget*> WidgetList)
{
	if (!IsValid(VerticalBox) || WidgetList.Num() == 0 || ArrayNumber > WidgetList.Num() - 1)
	{
		return;
	}
	VerticalBox->AddChildToVerticalBox(WidgetList[ArrayNumber]);
	ArrayNumber++;
	CreateQuestObjectiveWidget();
}

void UQuestWidget::RemoveObjectiveToVerticalBox(UVerticalBox* VerticalBox, TArray<UUserWidget*> WidgetList)
{
	ArrayNumber--;
	WidgetList[ArrayNumber]->RemoveFromParent();
	if (!IsValid(VerticalBox) || ArrayNumber == 0)
	{
		return;
	}
	RemoveQuestObjectiveWidget();
}

