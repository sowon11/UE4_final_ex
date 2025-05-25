// Copyright Epic Games, Inc. All Rights Reserved.

#include "GEP_FinalGameMode.h"
#include "GEP_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MainWidget.h"
#include "IntroWidget.h"
#include "GameOverWidget.h"
#include "EndingWidget.h"

AGEP_FinalGameMode::AGEP_FinalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AGEP_FinalGameMode::BeginPlay()
{
	Super::BeginPlay();

	FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);

	if (CurrentLevelName == TEXT("StartGameLevel") && MainWidget)
	{
		ShowMainWidget();
	}

	if ((CurrentLevelName == TEXT("Dungeon_Demo_00"))||(CurrentLevelName == TEXT("Dungeon_Demo_1")) && GameHUDWidget)
	{
		ShowGameHUD();
	}
}

void AGEP_FinalGameMode::ShowMainWidget()
{
	if (MainWidget && !MainUI)
	{
		MainUI = CreateWidget<UMainWidget>(GetWorld(), MainWidget);
		if (MainUI)
		{
			MainUI->AddToViewport();

			APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
			PC->SetInputMode(FInputModeUIOnly());
			PC->bShowMouseCursor = true;
		}
	}
}

void AGEP_FinalGameMode::ShowIntroWidget()
{
	if (IntroWidget)
	{
		IntroUI = CreateWidget<UIntroWidget>(GetWorld(), IntroWidget);
		if (IntroUI)
		{
			IntroUI->AddToViewport();

			APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
			PC->SetInputMode(FInputModeUIOnly());
			PC->bShowMouseCursor = true;
		}
	}
}

void AGEP_FinalGameMode::ShowGameHUD()
{
	if (GameHUDWidget && !GameHUDUI)
	{
		GameHUDUI = CreateWidget<UUserWidget>(GetWorld(), GameHUDWidget);
		if (GameHUDUI)
		{
			GameHUDUI->AddToViewport();
		}
	}
}

void AGEP_FinalGameMode::ShowGameOver()
{
	if (GameOverWidget && !GameOverUI)
	{
		GameOverUI = CreateWidget<UGameOverWidget>(GetWorld(), GameOverWidget);
		if (GameOverUI)
		{
			GameOverUI->AddToViewport();

			APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
			PC->SetInputMode(FInputModeUIOnly());
			PC->bShowMouseCursor = true;
		}
	}
}

void AGEP_FinalGameMode::ShowEnding()
{
	if (EndingWidget && !EndingUI)
	{
		EndingUI = CreateWidget<UEndingWidget>(GetWorld(), EndingWidget);
		if (EndingUI)
		{
			EndingUI->AddToViewport();

			APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
			PC->SetInputMode(FInputModeUIOnly());
			PC->bShowMouseCursor = true;
		}
	}
}