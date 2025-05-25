// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class GEP_FINAL_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UButton* RetryButton;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UButton* QuitButton;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UTextBlock* PlayTimeHour;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UTextBlock* PlayTimeMinute;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UTextBlock* DeathCount;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UTextBlock* GotAbilityCount;

    UFUNCTION()
    void OnRetryClicked();

    UFUNCTION()
    void OnQuitClicked();
};
