// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "C:/Users/sowon/Documents/Unreal Projects/UE4_final_ex/Source/GEP_Final/GEP_FinalGameMode.h"

void UOptionsWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (BackButton)
        BackButton->OnClicked.AddDynamic(this, &UOptionsWidget::OnBackClicked);
}

void UOptionsWidget::OnBackClicked()
{
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Back button clicked"));
    RemoveFromParent();

    if (AGEP_FinalGameMode* GM = Cast<AGEP_FinalGameMode>(UGameplayStatics::GetGameMode(this)))
    {
        GM->ShowMainWidget();
    }
}