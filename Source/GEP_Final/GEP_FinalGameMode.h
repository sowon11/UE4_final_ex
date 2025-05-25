// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GEP_FinalGameMode.generated.h"

UCLASS(minimalapi)
class AGEP_FinalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGEP_FinalGameMode();

	virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UMainWidget> MainWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UIntroWidget> IntroWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> GameHUDWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UGameOverWidget> GameOverWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UEndingWidget> EndingWidget;

    void ShowMainWidget();
    void ShowIntroWidget();
    void ShowGameHUD();
    void ShowGameOver();
    void ShowEnding();

private:
    class UMainWidget* MainUI;
    class UIntroWidget* IntroUI;
    class UUserWidget* GameHUDUI;
    class UGameOverWidget* GameOverUI;
    class UEndingWidget* EndingUI;
    
};



