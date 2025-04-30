#pragma once

#include "CoreMinimal.h"
#include "StrategyCamera.h"
#include "UnitBase.h"
#include "CellActor.h"
#include "TurnIndicatorWidget.h"
#include "GameFramework/PlayerController.h"
#include "GridPlayerController.generated.h"

class AUnitBase;

UCLASS()
class PROJECT_PAA_24_25_API AGridPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGridPlayerController();

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	AUnitBase* SelectedUnit;
	TArray<ACellActor*> GridCells;

	TArray <ACellActor*> HighlightedCells;
	TArray <ACellActor*> AttackCells;

	UFUNCTION(BlueprintCallable)
	void InitializeGridCells();
	
	UFUNCTION(BlueprintCallable)
	void UpdateAllUnitWidgets();

	UFUNCTION(BlueprintCallable)
	void HandlePlaceUnit();

	UFUNCTION(BlueprintCallable)
	void HandleSelectUnit();

	UFUNCTION(BlueprintCallable)
	ACellActor* FindCellUnderUnit(FVector UnitLocation);

	UFUNCTION(BlueprintCallable)
	void HandleMoveUnit();

	UFUNCTION(BlueprintCallable)
	void MovePlayerStepByStep();

	UFUNCTION(BlueprintCallable)
	void ShowMovementRange();

	UFUNCTION(BlueprintCallable)
	void ClearMovementRange(bool bMovementOrAttack);

	UFUNCTION(BlueprintCallable)
	void HandleAttackUnit();

	UFUNCTION(BlueprintCallable)
	void HandleNextUnit();

	UFUNCTION(BlueprintCallable)
	void HandleEndTurn();

	UFUNCTION(BlueprintCallable)
	void StoreMove(FVector TargetLocation);

	UFUNCTION(BlueprintCallable)
	void StoreAttack(AUnitBase* AttackingUnit, AUnitBase* TargetUnit, int32 CurrentDamage);

	UFUNCTION(BlueprintCallable)
	void DisablePlayerInput();

	UPROPERTY()
	AStrategyCamera* StrategyCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UUnitInfoWidget> UnitInfoWidgetClass;
	
	UPROPERTY()
	UUnitInfoWidget* UnitInfoWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UTurnIndicatorWidget> TurnIndicatorWidgetClass;

	UPROPERTY()
	UTurnIndicatorWidget* TurnIndicatorWidget;

private:
	TMap <FVector, TArray <FVector>> MovementPaths;
	TArray<FVector> PlayerPath;
	int32 PCurrentStepIndex;
	FTimerHandle PStepMoveTimer;
	FTimerHandle TimerHandle;
	AUnitBase* PMovingUnit;
	ACellActor* CurrentlyHighlightedCell;

	bool bIsMovementRangeVisible = false; // first hidden
};