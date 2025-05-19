// Copyright Epic Games, Inc. All Rights Reserved.

#include "GEP_FinalGameMode.h"
#include "GEP_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGEP_FinalGameMode::AGEP_FinalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
