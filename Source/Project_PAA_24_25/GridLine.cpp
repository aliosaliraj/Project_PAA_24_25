// Fill out your copyright notice in the Description page of Project Settings.


#include "GridLine.h"
#include "CellActor.h"
#include "Obstacle.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "WorldCollision.h"

// Sets default values
AGridLine::AGridLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	int32 NumObstacles = NumCells * 0.1f; //obstacles percent (10)

	for (int32 x = 0; x < GridSize; x++)
	{
		for (int32 y = 0; y < GridSize; y++)
		{
			FVector Location = FVector(x * CellSize, y * CellSize, 0);

			if (FMath::RandRange(0, NumCells) < NumObstacles)
			{
				SpawnObstaclesAtLocation(Location);
				--NumObstacles;
			}
		}
	}
}

void AGridLine::SpawnObstaclesAtLocation(const FVector& Location)
{
	TArray<FOverlapResult> OverlappingActors;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	GetWorld()->OverlapMultiByChannel(OverlappingActors, Location, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeBox(FVector(CellSize / 2, CellSize / 2, CellSize / 2)), CollisionParams);

	if (OverlappingActors.Num() == 0)
	{
		GetWorld()->SpawnActor<AObstacle>(ObstacleClass, Location, FRotator::ZeroRotator);
	}
}