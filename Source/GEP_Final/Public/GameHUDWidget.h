// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class GEP_FINAL_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* LevelText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* LevelData;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	class UTextBlock* HPText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HPData;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PowerText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PowerData;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* AttackText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* AttackData;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* DefenseText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* DefenseData;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* AttackSpeedText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* AttackSpeedData;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CriticalText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* CriticalData;


};
