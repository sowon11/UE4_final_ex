// Fill out your copyright notice in the Description page of Project Settings.


#include "EndingWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UEndingWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (MainMenuButton)
        MainMenuButton->OnClicked.AddDynamic(this, &UEndingWidget::OnMainMenuClicked);

    if (QuitButton)
        QuitButton->OnClicked.AddDynamic(this, &UEndingWidget::OnQuitClicked);
}

void UEndingWidget::OnMainMenuClicked()
{
    UGameplayStatics::OpenLevel(this, TEXT("StartGameLevel")); // 시작 화면으로
}

void UEndingWidget::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
