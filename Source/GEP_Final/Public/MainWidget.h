// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class GEP_FINAL_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;
	
public:
    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UButton* StartGameButton;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UButton* ContinueButton;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UButton* OptionsButton;

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    class UButton* QuitButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UOptionsWidget> OptionsWidget;

    UFUNCTION()
    void OnStartGameClicked();

    UFUNCTION()
    void OnOptionsClicked();

    UFUNCTION()
    void OnQuitClicked();

    // 인트로 영상 재생 후 레벨 이동
    // void HandleIntroSequence();

private:
    class UOptionsWidget* OptionsUI;
};
