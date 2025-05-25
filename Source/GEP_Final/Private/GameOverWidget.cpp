// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UGameOverWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (RetryButton)
        RetryButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnRetryClicked);

    if (QuitButton)
        QuitButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnQuitClicked);
}

void UGameOverWidget::OnRetryClicked()
{
    // ���̺� ����Ʈ�� (�����ϴ� ���� ���� ��)
    // UGameplayStatics::OpenLevel(this, TEXT("SavePointLevel"));
}

void UGameOverWidget::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
