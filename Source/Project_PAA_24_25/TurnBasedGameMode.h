// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TurnBasedGameMode.generated.h"

UENUM(BlueprintType)
enum class ETurnState : uint8
{
	PlayerTurn,
	EnemyTurn
};

UCLASS()
class PROJECT_PAA_24_25_API ATurnBasedGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATurnBasedGameMode();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite)
	ETurnState CurrentTurn;

	void StartPlayerTurn();
	void StartEnemyTurn();
	void EndTurn();
	//void SpawnUnits();
};
