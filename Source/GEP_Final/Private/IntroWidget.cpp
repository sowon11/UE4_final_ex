// Fill out your copyright notice in the Description page of Project Settings.


#include "IntroWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UIntroWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (SkipIntroButton)
    {
        SkipIntroButton->OnClicked.AddDynamic(this, &UIntroWidget::OnSkipIntroClicked);
    }
    // MediaPlayer->OnEndReached.AddDynamic(this, &UIntroWidget::OnIntroFinished);
}

void UIntroWidget::OnIntroFinished()
{
    UGameplayStatics::OpenLevel(this, TEXT("level1"));
}

void UIntroWidget::OnSkipIntroClicked()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Skip Button Clicked"));

    RemoveFromParent();
    UGameplayStatics::OpenLevel(this, TEXT("Dungeon_Demo_00"));
}