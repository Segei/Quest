// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestGameMode.h"
#include "QuestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AQuestGameMode::AQuestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
