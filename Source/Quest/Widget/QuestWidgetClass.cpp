// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestWidgetClass.h"
#include "Components/VerticalBox.h"

void UQuestWidgetClass::ChangeQuestObjectiveWidget()
{
	bIsVisibleWidget ? RemoveQuestObjectiveWidget() : CreateQuestObjectiveWidget();
	bIsVisibleWidget = !bIsVisibleWidget;
}

void UQuestWidgetClass::CreateQuestObjectiveWidget()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandleWidget, this, &UQuestWidgetClass::StartEventForCreate, TimerRate, false);
}

void UQuestWidgetClass::RemoveQuestObjectiveWidget()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandleWidget, this, &UQuestWidgetClass::StartEventForDelete, TimerRate, false);
}

void UQuestWidgetClass::StartEventForCreate()
{
	AddObjectiveToVerticalBox(QuestVerticalBox, QuestWidgetList);
}

void UQuestWidgetClass::StartEventForDelete()
{
	RemoveObjectiveToVerticalBox(QuestVerticalBox, QuestWidgetList);
}

void UQuestWidgetClass::AddObjectiveToVerticalBox(UVerticalBox* VerticalBox, TArray<UUserWidget*> WidgetList)
{
	if (!IsValid(VerticalBox) || WidgetList.Num() == 0 || ArrayNumber > WidgetList.Num() - 1)
	{
		return;
	}
	VerticalBox->AddChildToVerticalBox(WidgetList[ArrayNumber]);
	ArrayNumber++;
	CreateQuestObjectiveWidget();
}

void UQuestWidgetClass::RemoveObjectiveToVerticalBox(UVerticalBox* VerticalBox, TArray<UUserWidget*> WidgetList)
{
	ArrayNumber--;
	WidgetList[ArrayNumber]->RemoveFromParent();
	if (!IsValid(VerticalBox) || ArrayNumber == 0)
	{
		return;
	}
	RemoveQuestObjectiveWidget();
}
