// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUEST_API UQuestWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	FTimerHandle TimerHandleWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjectiveWidget")
	float TimerRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjectiveWidget")
	int ArrayNumber = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjectiveWidget")
	class UVerticalBox* QuestVerticalBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjectiveWidget")
	TArray<UUserWidget*> QuestWidgetList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjectiveWidget")
	bool bIsVisibleWidget = false;

	UFUNCTION(BlueprintCallable, Category = "ObjectiveWidget")
	void ChangeQuestObjectiveWidget();

	UFUNCTION(BlueprintCallable, Category = "ObjectiveWidget")
	void CreateQuestObjectiveWidget();

	UFUNCTION(BlueprintCallable, Category = "ObjectiveWidget")
	void RemoveQuestObjectiveWidget();

	UFUNCTION(BlueprintCallable, Category = "ObjectiveWidget")
	void StartEventForCreate();

	UFUNCTION(BlueprintCallable, Category = "ObjectiveWidget")
	void StartEventForDelete();

	UFUNCTION(BlueprintCallable, Category = "ObjectiveWidget")
	void AddObjectiveToVerticalBox(UVerticalBox* VerticalBox, TArray<UUserWidget*> WidgetList);

	UFUNCTION(BlueprintCallable, Category = "ObjectiveWidget")
	void RemoveObjectiveToVerticalBox(UVerticalBox* VerticalBox, TArray<UUserWidget*> WidgetList);
};
