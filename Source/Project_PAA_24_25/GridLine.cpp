// Fill out your copyright notice in the Description page of Project Settings.


#include "GridLine.h"
#include "CellActor.h"
#include "Obstacle.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "WorldCollision.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AGridLine::AGridLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObstacleClass = AObstacle::StaticClass();
	if (!ObstacleClass)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find Obstacle class"));
	}
}

// Called when the game starts or when spawned
void AGridLine::BeginPlay()
{
	Super::BeginPlay();

	GenerateGrid();
}

// Called every frame
void AGridLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGridLine::GenerateGrid()
{
	for (int32 x = 0; x < GridSize; x++)
	{
		for (int32 y = 0; y < GridSize; y++)
		{
			FVector Position = FVector(x * CellSize, y * CellSize, 0);
			FActorSpawnParameters SpawnParams;
			ACellActor* Cell = GetWorld()->SpawnActor<ACellActor>(ACellActor::StaticClass(), Position, FRotator::ZeroRotator, SpawnParams);

			if (Cell)
			{
				GridCells.Add(Cell);

				if ((x + y) % 2 == 0)
				{
					Cell->SetCellColor(FColor::Black);
				}
				else
				{
					Cell->SetCellColor(FColor::White);
				}
			}

		}
	}
	CreateGridWithObstacles();
}

void AGridLine::CreateGridWithObstacles()
{
	int32 NumCells = GridSize * GridSize;
	int32 NumObstacles = NumCells * 0.1f;	//obstacles percent (10)

	int32 NumTrees = FMath::RoundToInt(NumObstacles * TreePercentage);
	int32 NumMountains = NumObstacles - NumTrees;

	for (int32 x = 0; x < GridSize; x++)
	{
		for (int32 y = 0; y < GridSize; y++)
		{
			if (NumObstacles <= 0) break;

			if (FMath::RandRange(0, NumCells) < NumObstacles)
			{
				FVector Location = FVector(x * CellSize, y * CellSize, 0);

				bool bTree = (NumTrees > 0);
				SpawnObstaclesAtLocation(Location, bTree);

				if (bTree)
				{
					NumTrees--;
				}
				else
				{
					NumMountains--;
				}

				--NumObstacles;
			}
		}
	}
}

void AGridLine::SpawnObstaclesAtLocation(const FVector& Location, bool bIsTree)
{
	if (ObstacleClass && ObstacleClass->IsChildOf(AObstacle::StaticClass()))
	{
		AObstacle* NewObstacle = GetWorld()->SpawnActor<AObstacle>(ObstacleClass, Location, FRotator::ZeroRotator);
		if (NewObstacle)
		{
			NewObstacle->SetMaterial(bIsTree);
			UE_LOG(LogTemp, Warning, TEXT("Spawned obstacle at %s"), *Location.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to spawn obstacle at location"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Obstacle class not assigned or not child of AActor"));
	}
}