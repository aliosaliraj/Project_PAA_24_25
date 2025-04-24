// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	AGridLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GenerateGrid();
	void CreateGridWithObstacles();
	void SpawnObstaclesAtLocation(const FVector& Location, bool bisTree);
	
	TArray<FVector> ObstaclePositions;

private:
	UPROPERTY(EditAnywhere, Category = "Gridline")
	int32 GridSize = 25;

	UPROPERTY(EditAnywhere, Category = "Gridline")
	float CellSize = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	TSubclassOf<class AObstacle> ObstacleClass;

	UPROPERTY(EditAnywhere, Category = "Obstacle")
	float TreePercentage = 0.6f;

	TArray<class AActor*> GridCells;

	//Flood Fill algotirhm for connectivity check
	bool IsGridFullyConnected(const TArray<TArray<bool>>& Grid);
};