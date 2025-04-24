// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UnitBase.h"
#include "Sniper.h"
#include "Brawler.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Obstacle.h"
#include "TurnIndicatorWidget.h"
#include "TurnBasedGameMode.generated.h"

//class UTurnIndicatorWidget;

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
	TSubclassOf<AUnitBase> PlayerSniperClass;

	UPROPERTY(EditAnywhere, Category = "Units")
	TSubclassOf<AUnitBase> PlayerBrawlerClass;

	UPROPERTY(EditAnywhere, Category = "Units")
	TSubclassOf<AUnitBase> EnemySniperClass;

	UPROPERTY(EditAnywhere, Category = "Units")
	TSubclassOf<AUnitBase> EnemyBrawlerClass;
	
	TArray<AUnitBase*> PlayerUnits;
	TArray<AUnitBase*> EnemyUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UTurnIndicatorWidget> TurnIndicatorWidgetClass;

	UPROPERTY()
	UTurnIndicatorWidget* TurnIndicatorWidget;

	UFUNCTION(BlueprintCallable)
	void StartPlayerTurn();

	UFUNCTION(BlueprintCallable)
	void StartEnemyTurn();

	UFUNCTION(BlueprintCallable)
	void ExecuteEnemyAction();

	UFUNCTION(BlueprintCallable)
	AUnitBase* FindClosestPlayerUnit(AUnitBase* EnemyUnit);

	UFUNCTION(BlueprintCallable)
	bool CanAttackPlayerUnit(AUnitBase* EnemyUnit, AUnitBase* PlayerUnit);

	UFUNCTION(BlueprintCallable)
	void EndTurn();

	UFUNCTION(BlueprintCallable)
	void SpawnUnits();

	UFUNCTION(BlueprintCallable)
	void MoveStepByStep();

	UFUNCTION(BlueprintCallable)
	void CoinFlip();

	UFUNCTION(BlueprintCallable)
	void HandlePlayerUnitPlacement(FVector ChosenLocation);

	UFUNCTION(BlueprintCallable)
	void SetObstaclePositions(const TArray<FVector>& Positions);

	TArray<FVector> ObstaclePositions;
	TArray<FVector> FindPath(AUnitBase* Unit, FVector StartLocation, FVector TargetLocation, bool bIsPlayerControlled);

private:
	TArray<FVector> Path;
	int32 CurrentStepIndex;
	FTimerHandle StepMoveTimer;
	AUnitBase* MovingUnit;

	bool bIsPlayerStarting = false;
	bool bIsPlayerPlacingUnits = true;
	bool IsLocationValid(FVector Location);

	int32 CurrentUnitPlacementIndex = 0;
	int32 CurrentPlayerUnitIndex = 0;
	int32 CurrentEnemyUnitIndex = 0;

	FVector CalculateEnemyPlacementLocation();

	void PositionUnitsAlternately();
	void StartGame();
};