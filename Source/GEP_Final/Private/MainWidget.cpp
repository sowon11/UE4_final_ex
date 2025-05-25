// Fill out your copyright notice in the Description page of Project Settings.

#include "MainWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "OptionsWidget.h"
#include "C:/Users/sowon/Documents/Unreal Projects/UE4_final_ex/Source/GEP_Final/GEP_FinalGameMode.h"

void UMainWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartGameButton)
        StartGameButton->OnClicked.AddDynamic(this, &UMainWidget::OnStartGameClicked);

    if (OptionsButton)
        OptionsButton->OnClicked.AddDynamic(this, &UMainWidget::OnOptionsClicked);

    if (QuitButton)
        QuitButton->OnClicked.AddDynamic(this, &UMainWidget::OnQuitClicked);
}

void UMainWidget::OnStartGameClicked()
{
    RemoveFromParent();

    if (AGEP_FinalGameMode* GM = Cast<AGEP_FinalGameMode>(UGameplayStatics::GetGameMode(this)))
    {
        GM->ShowIntroWidget();
    }
}

void UMainWidget::OnOptionsClicked()
{
    if (OptionsWidget && !OptionsUI)
    {
        OptionsUI = CreateWidget<UOptionsWidget>(GetWorld(), OptionsWidget);
        if (OptionsUI)
        {
            OptionsUI->AddToViewport();

            APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
            PC->SetInputMode(FInputModeUIOnly());
            PC->bShowMouseCursor = true;
        }
    }
}

void UMainWidget::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}