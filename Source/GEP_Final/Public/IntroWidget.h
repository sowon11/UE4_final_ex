// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IntroWidget.generated.h"

/**
 * 
 */
UCLASS()
class GEP_FINAL_API UIntroWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* SkipIntroButton;

	void OnIntroFinished();
	void OnSkipIntroClicked();
};