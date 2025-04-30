#include "GridLine.h"
#include "CellActor.h"
#include "Obstacle.h"
#include "TurnBasedGameMode.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "WorldCollision.h"
#include "Components/PrimitiveComponent.h"

AGridLine::AGridLine()
{
	PrimaryActorTick.bCanEverTick = true;

	ObstacleClass = AObstacle::StaticClass();
}

void AGridLine::BeginPlay()
{
	Super::BeginPlay();

	if (ObstacleClass)
	{
		GenerateGrid();
	}
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
					Cell->SetCellColor(FLinearColor(0.4f, 0.26f, 0.13f));	// light brown
				}
				else
				{
					Cell->SetCellColor(FLinearColor(0.3f, 0.2f, 0.1f));		// dark brown
				}
			}
		}
	}
	CreateGridWithObstacles();
}

void AGridLine::CreateGridWithObstacles()
{
	int32 NumCells = GridSize * GridSize;
	int32 NumObstacles = FMath::RoundToInt(NumCells * 0.1f);			//obstacles percent (10)
	int32 NumTrees = FMath::RoundToInt(NumObstacles * TreePercentage);  // trees number 
	int32 NumMountains = NumObstacles - NumTrees;						// mountains number

	// 2D rappresentation of grid
	TArray<TArray<bool>> Grid;
	Grid.SetNum(GridSize);
	for (int32 x = 0; x < GridSize; x++)
	{
		Grid[x].SetNum(GridSize);
		for (int32 y = 0; y < GridSize; y++)
		{
			Grid[x][y] = false; // free first
		}
	}

	while (NumObstacles > 0)
	{
		if (NumObstacles <= 0)
		{
			return;
		}

		int32 x = FMath::RandRange(0, GridSize - 1);
		int32 y = FMath::RandRange(0, GridSize - 1);

		FVector Location = FVector(x * CellSize, y * CellSize, 0);

		// Check if the cell is already occupied
		if (Grid[x][y])
		{
			continue;
		}

		// Cell (0, 0), (24, 0) are not allowed because they are the spawn points and interfere with unit positioning
		if ((x == 0 && y == 0) || (x == (GridSize - 1) && y == 0))
		{
			continue;
		}

		// Checks if is cell is connected or not
		Grid[x][y] = true;				// Starts setting cell occuped
		if (!IsGridFullyConnected(Grid))
		{
			Grid[x][y] = false;			// if not connected sets it free
			continue;
		}

		// Sets mountain/tree casually
		bool bTree = false;
		if (NumTrees > 0 && NumMountains > 0)
		{
			bTree = FMath::RandBool();
		}
		else if (NumTrees > 0)
		{
			bTree = true;				// Tree if NumTrees > 0
		}
		else
		{
			bTree = false;				// Mountain otherwise
		}

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

void AGridLine::SpawnObstaclesAtLocation(const FVector& Location, bool bIsTree)
{
	AObstacle* NewObstacle = GetWorld()->SpawnActor<AObstacle>(ObstacleClass, Location, FRotator::ZeroRotator);
	if (NewObstacle)
	{
		NewObstacle->SetMaterial(bIsTree);
		ObstaclePositions.Add(Location);	// Store location of obstacle in the array
	}

	// Pass obstacle positions to the game mode
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->SetObstaclePositions(ObstaclePositions);
	}
}

bool AGridLine::IsGridFullyConnected(const TArray<TArray<bool>>& Grid)
{
	TArray<FIntPoint> OpenList; // Cells to verify
	TArray<FIntPoint> Visited;	// Cells visited

	// Start finding a cell to visit
	for (int32 x = 0; x < GridSize; x++)
	{
		for (int32 y = 0; y < GridSize; y++)
		{
			if (!Grid[x][y]) // Free cell
			{
				OpenList.Add(FIntPoint(x, y));
				break;
			}
		}
		if (OpenList.Num() > 0)
		{
			break;
		}
	}

	if (OpenList.Num() == 0)
	{
		return true;
	}

	// Flood Fill algorythm
	while (OpenList.Num() > 0)
	{
		FIntPoint Current = OpenList.Pop();
		if (Visited.Contains(Current))
		{
			continue;
		}

		Visited.Add(Current);

		TArray<FIntPoint> Neighbors = {FIntPoint(Current.X + 1, Current.Y), FIntPoint(Current.X - 1, Current.Y), FIntPoint(Current.X, Current.Y + 1), FIntPoint(Current.X, Current.Y - 1)};

		for (const FIntPoint& Neighbor : Neighbors)
		{
			if (Neighbor.X >= 0 && Neighbor.X < GridSize && Neighbor.Y >= 0 && Neighbor.Y < GridSize && !Grid[Neighbor.X][Neighbor.Y] && !Visited.Contains(Neighbor))
			{
				OpenList.Add(Neighbor);
			}
		}
	}

	// Counts all free cells
	int32 FreeCells = 0;
	for (int32 x = 0; x < GridSize; x++)
	{
		for (int32 y = 0; y < GridSize; y++)
		{
			if (!Grid[x][y])
			{
				FreeCells++;
			}
		}
	}

	// If visited cells equals free cells done!
	return Visited.Num() == FreeCells;
}