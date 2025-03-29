// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StrategyCamera.h"
#include "UnitBase.h"
#include "GameFramework/PlayerController.h"
#include "GridPlayerController.generated.h"

class AUnitBase;
//class UUnitInfoWidget;

UCLASS()
class PROJECT_PAA_24_25_API AGridPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGridPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void HandleSelectUnit();
	void HandleMoveUnit();

	void ShowMovementRange();
	void ClearMovementRange();

	UFUNCTION()
	void HandleAttackUnit();

	AUnitBase* SelectedUnit;

	UPROPERTY()
	AStrategyCamera* StrategyCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UUnitInfoWidget> UnitInfoWidgetClass;

	UPROPERTY()
	UUnitInfoWidget* UnitInfoWidget;

	UFUNCTION(BlueprintCallable)
	void ShowUnitInfo();
};