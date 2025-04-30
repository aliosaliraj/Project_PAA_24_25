#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "GameFramework/Actor.h"
#include "GridLine.generated.h"

UCLASS()
class PROJECT_PAA_24_25_API AGridLine : public AActor
{
	GENERATED_BODY()

public:
	AGridLine();

protected:
	virtual void BeginPlay() override;

public:
	void GenerateGrid();
	void CreateGridWithObstacles();
	void SpawnObstaclesAtLocation(const FVector& Location, bool bisTree);
	
	TArray<FVector> ObstaclePositions;
	TArray<class ACellActor*> GridCells;

	TArray<ACellActor*> GetGridCells() const { return GridCells; }

private:
	UPROPERTY(EditAnywhere, Category = "Gridline")
	int32 GridSize = 25;

	UPROPERTY(EditAnywhere, Category = "Gridline")
	float CellSize = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	TSubclassOf<class AObstacle> ObstacleClass;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	float TreePercentage = 0.6f;

	//Flood Fill algotirhm for connectivity check
	bool IsGridFullyConnected(const TArray<TArray<bool>>& Grid);
};