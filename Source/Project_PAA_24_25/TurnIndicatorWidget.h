// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "TurnIndicatorWidget.generated.h"


UCLASS()
class PROJECT_PAA_24_25_API UTurnIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UTurnIndicatorWidget> TurnIndicatorWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TurnText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* EndTurnButton;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetTurnText(const FString& NewText);

	UFUNCTION(BlueprintCallable, Category = "UI")
	ESlateVisibility GetEndTurnButtonVisibility();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnEndTurnButtonPressed();
};