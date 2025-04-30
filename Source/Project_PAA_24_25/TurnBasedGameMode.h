#pragma once

#include "UnitBase.h"
#include "Sniper.h"
#include "Brawler.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Obstacle.h"
#include "TurnIndicatorWidget.h"
#include "TurnBasedGameMode.generated.h"

UENUM(BlueprintType)
enum class ETurnState : uint8
{
	None,
	PlayerPlacement,
	EnemyPlacement,
	PlayerTurn,
	EnemyTurn
};

UENUM(BlueprintType)
enum class EAIBehaviorMode : uint8
{
	StrategicLogic UMETA(DisplayName = "Strategic Logic"), // Mode A*
	RandomLogic UMETA(DisplayName = "Random Logic")        // Mode random
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

protected:
	virtual void BeginPlay() override;

	bool IsValidMove(FVector Position, AUnitBase* Unit);
	FTimerHandle TimerHandle;

public:
	ATurnBasedGameMode();

	UPROPERTY(BlueprintReadOnly)
	ETurnState CurrentTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	EAIBehaviorMode CurrentAIBehaviorMode;	// AI behavior mode

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
	
	UPROPERTY()
	TArray<AUnitBase*> PlayerUnits;

	UPROPERTY()
	TArray<AUnitBase*> EnemyUnits;

	UPROPERTY()
	TArray<AUnitBase*> EliminatedPlayerUnits;	// to keep track of eliminated player units

	UPROPERTY()
	TArray<AUnitBase*> EliminatedEnemyUnits;	// to keep track of eliminated enemy units

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UTurnIndicatorWidget> TurnIndicatorWidgetClass;

	UPROPERTY()
	UTurnIndicatorWidget* TurnIndicatorWidget;

	UFUNCTION(BlueprintCallable)
	void SetAIBehaviorMode(EAIBehaviorMode NewMode);

	UFUNCTION(BlueprintCallable)
	void StartPlayerTurn();

	UFUNCTION(BlueprintCallable)
	void StartEnemyTurn();

	UFUNCTION(BlueprintCallable)
	void ExecuteRandomEnemyAction();

	UFUNCTION(BlueprintCallable)
	TArray<FVector> CalculateValidMovementLocations(AUnitBase* Unit);

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
	void SelectPrePositionedUnit(AUnitBase* SelectedUnit);

	UFUNCTION(BlueprintCallable)
	void HandlePlayerUnitPlacement(FVector ChosenLocation);

	UFUNCTION(BlueprintCallable)
	void SetObstaclePositions(const TArray<FVector>& Positions);

	UFUNCTION(BlueprintCallable)
	void LogMove(const FString& PlayerID, const FString& UnitType, const FString& OriginCell, const FString& DestinationCell);

	UFUNCTION(BlueprintCallable)
	void LogAttack(const FString& PlayerID, const FString& UnitType, const FString& TargetCell, int32 Damage);

	UFUNCTION(BlueprintCallable)
	FString ConvertPositionToNotation(const FVector& Position);

	UFUNCTION(BlueprintCallable)
	void CheckEndGameCondition();

	UFUNCTION(BlueprintCallable)
	void EndGame();

	UPROPERTY(BlueprintReadWrite, Category = "Player Unit Placement")
	AUnitBase* SelectedPlayerUnit;

	TArray<FVector> ObstaclePositions;
	TArray<FVector> FindPath(AUnitBase* Unit, FVector StartLocation, FVector TargetLocation, bool bIsPlayerControlled);

	// Getter for History
	const TArray<FString>& GetHistory() const { return History; }

	int32 CurrentEnemyUnitIndex = 0;
	
	bool bIsPlayerStarting = false;

private:
	TArray<FVector> Path;
	int32 CurrentStepIndex;
	FTimerHandle StepMoveTimer;
	AUnitBase* MovingUnit;

	
	bool bIsPlayerPlacingUnits = true;

	int32 CurrentUnitPlacementIndex = 0;
	int32 CurrentPlayerUnitIndex = 0;

	FVector CalculateEnemyPlacementLocation();

	UFUNCTION(BlueprintCallable)
	void PositionUnitsAlternately();

	UFUNCTION(BlueprintCallable)
	void StartGame();

	TArray<FString> History; // History
};