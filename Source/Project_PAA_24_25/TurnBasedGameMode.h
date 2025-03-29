// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UnitBase.h"
#include "Sniper.h"
#include "Brawler.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Obstacle.h"
#include "TurnBasedGameMode.generated.h"

UENUM(BlueprintType)
enum class ETurnState : uint8
{
	PlayerTurn,
	EnemyTurn
};

USTRUCT()
struct FPathNode
{
	GENERATED_BODY()

	FVector Position;
	float GCost;
	float HCost;
	float FCost;
	FPathNode* Parent;

	FPathNode()
		: Position(FVector::ZeroVector), GCost(0), HCost(0), FCost(0), Parent(nullptr) {}

	FPathNode(FVector InPosition)
		: Position(InPosition), GCost(0), HCost(0), FCost(0), Parent(nullptr) {}
};

UCLASS()
class PROJECT_PAA_24_25_API ATurnBasedGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATurnBasedGameMode();

protected:
	virtual void BeginPlay() override;

	bool IsValidMove(FVector Position, FVector TargetLocation, AUnitBase* Unit);
	FTimerHandle TimerHandle;

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

	UFUNCTION(BlueprintCallable)
	TArray<FVector> FindPath(AUnitBase* Unit, FVector StartLocation, FVector TargetLocation);

private:
	TArray<FVector> Path;
	int32 CurrentStepIndex;
	FTimerHandle StepMoveTimer;
	AUnitBase* MovingUnit;

	void MoveStepByStep();
};