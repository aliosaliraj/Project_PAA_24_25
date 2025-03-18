// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UnitBase.h"
#include "Sniper.h"
#include "Brawler.h"
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
	UPROPERTY(BlueprintReadOnly)
	ETurnState CurrentTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridSize = 25;

	UPROPERTY(EditAnywhere, Category = "Units")
	TSubclassOf<AUnitBase> PlayerUnitClass;

	UPROPERTY(EditAnywhere, Category = "Units")
	TSubclassOf<AUnitBase> EnemyUnitClass;

	UFUNCTION(BlueprintCallable)
	void StartPlayerTurn();

	UFUNCTION(BlueprintCallable)
	void StartEnemyTurn();

	UFUNCTION(BlueprintCallable)
	void EndTurn();

	UFUNCTION(BlueprintCallable)
	void SpawnUnits();
};
