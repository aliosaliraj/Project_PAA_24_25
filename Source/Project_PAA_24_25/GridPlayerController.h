// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitBase.h"
#include "GameFramework/PlayerController.h"
#include "GridPlayerController.generated.h"

class AUnitBase;

UCLASS()
class PROJECT_PAA_24_25_API AGridPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGridPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	AUnitBase* SelectedUnit;

	void HandleSelectUnit();
	void HandleMoveUnit();

	void ShowMovementRange();
	void ClearMovementRange();
};
