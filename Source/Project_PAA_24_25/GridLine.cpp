// Fill out your copyright notice in the Description page of Project Settings.


#include "GridLine.h"
#include "CellActor.h"
#include "Sniper.h"
#include "Brawler.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

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
	PlaceUnits();
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
}

void AGridLine::PlaceUnits()
{
	FVector SniperPosition = FVector(0, 0, 50);
	FVector BrawlerPosition = FVector(500, 500, 50);

	GetWorld()->SpawnActor<ASniper>(SniperPosition, FRotator::ZeroRotator);

	GetWorld()->SpawnActor<ABrawler>(BrawlerPosition, FRotator::ZeroRotator);
}

