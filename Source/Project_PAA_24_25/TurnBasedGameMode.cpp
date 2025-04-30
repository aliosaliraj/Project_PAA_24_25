#include "TurnBasedGameMode.h"
#include "GridPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UnitBase.h"
#include "Sniper.h"
#include "Brawler.h"
#include "Obstacle.h"
#include "GridLine.h"
#include "TurnIndicatorWidget.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "Math/Vector.h"
#include "Containers/Array.h"
#include "Algo/Find.h"
#include "GameFramework/Actor.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "Misc/OutputDeviceNull.h"



ATurnBasedGameMode::ATurnBasedGameMode()
{
	PlayerControllerClass = AGridPlayerController::StaticClass();
	GridSize = 25;
}

void ATurnBasedGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (TurnIndicatorWidgetClass)
	{
		TurnIndicatorWidget = CreateWidget<UTurnIndicatorWidget>(GetWorld(), TurnIndicatorWidgetClass);
		TurnIndicatorWidget->AddToViewport(1);
	}
}

void ATurnBasedGameMode::SetAIBehaviorMode(EAIBehaviorMode NewMode)
{
	CurrentAIBehaviorMode = NewMode;
}

void ATurnBasedGameMode::CoinFlip()
{
	bIsPlayerStarting = FMath::RandBool(); // Random starting player
	CurrentTurn = bIsPlayerStarting ? ETurnState::PlayerPlacement : ETurnState::EnemyPlacement;

	if (TurnIndicatorWidget)
	{
		if (bIsPlayerStarting)
		{
			TurnIndicatorWidget->SetTurnText(TEXT("Player won flip coin and starts placing its units!"));
		}
		else
		{
			TurnIndicatorWidget->SetTurnText(TEXT("AI won flip coin and starts placing its units!"));
		}
	}
	SpawnUnits();
}

void ATurnBasedGameMode::SpawnUnits()
{
	CurrentUnitPlacementIndex = 0;

	// Spawn player unit at default positions
	if (PlayerSniperClass && PlayerBrawlerClass)
	{
		AUnitBase* PlayerSniper = GetWorld()->SpawnActor<AUnitBase>(PlayerSniperClass, FVector(0, 0, 0), FRotator::ZeroRotator);
		if (PlayerSniper)
		{
			PlayerSniper->bIsPlayerControlled = true;
			PlayerSniper->UnitType = EUnitType::Sniper;
			PlayerSniper->UnitRole = TEXT("Player Sniper");
			PlayerSniper->UpdateMaterial();
			PlayerUnits.Add(PlayerSniper);
		}			
			
		AUnitBase* PlayerBrawler = GetWorld()->SpawnActor<AUnitBase>(PlayerBrawlerClass, FVector(0, 2400, 0), FRotator::ZeroRotator);
		if (PlayerBrawler)
		{
			PlayerBrawler->bIsPlayerControlled = true;
			PlayerBrawler->UnitType = EUnitType::Brawler;
			PlayerBrawler->UnitRole = TEXT("Player Brawler");
			PlayerBrawler->UpdateMaterial();
			PlayerUnits.Add(PlayerBrawler);
		}
	}

	// Spawn enemy unit at default positions
	if (EnemySniperClass && EnemyBrawlerClass)
	{
		AUnitBase* EnemySniper = GetWorld()->SpawnActor<AUnitBase>(EnemySniperClass, FVector(2400, 0, 0), FRotator::ZeroRotator);
		if (EnemySniper)
		{
			EnemySniper->bIsPlayerControlled = false;
			EnemySniper->UnitType = EUnitType::Sniper;
			EnemySniper->UnitRole = TEXT("Enemy Sniper");
			EnemySniper->UpdateMaterial();
			EnemyUnits.Add(EnemySniper);
		}

		AUnitBase* EnemyBrawler = GetWorld()->SpawnActor<AUnitBase>(EnemyBrawlerClass, FVector(2400, 2400, 0), FRotator::ZeroRotator);
		if (EnemyBrawler)
		{
			EnemyBrawler->bIsPlayerControlled = false;
			EnemyBrawler->UnitType = EUnitType::Brawler;
			EnemyBrawler->UnitRole = TEXT("Enemy Brawler");
			EnemyBrawler->UpdateMaterial();
			EnemyUnits.Add(EnemyBrawler);
		}
	}
	PositionUnitsAlternately();
}

void ATurnBasedGameMode::PositionUnitsAlternately()
{
	// If all units are positioned, start the game
	if (CurrentPlayerUnitIndex >= PlayerUnits.Num() && CurrentEnemyUnitIndex >= EnemyUnits.Num())
	{
		StartGame();
		return;
	}

	// Determinates whos's turn is to place the unit
	if (CurrentTurn == ETurnState::PlayerPlacement && CurrentPlayerUnitIndex < PlayerUnits.Num())
	{
		bIsPlayerPlacingUnits = true; // Allows the player to select a unit
	}
	else if (CurrentTurn == ETurnState::EnemyPlacement && CurrentEnemyUnitIndex < EnemyUnits.Num())
	{
		FVector EnemyPlacementLocation = CalculateEnemyPlacementLocation();
		EnemyUnits[CurrentEnemyUnitIndex]->SetActorLocation(EnemyPlacementLocation);

		CurrentEnemyUnitIndex++;						// Pass to next unit

		// Change placement turn to player
		CurrentTurn = ETurnState::PlayerPlacement;
		PositionUnitsAlternately();						// Recall for the next unit
	}
}

FVector ATurnBasedGameMode::CalculateEnemyPlacementLocation()
{
	FVector PlacementLocation;
	bool bIsValidLocation = false;

	while (!bIsValidLocation)
	{
		// Generates a random position on the grid
		int32 GridX = FMath::RandRange(0, 24);
		int32 GridY = FMath::RandRange(0, 24);
		PlacementLocation = FVector(GridX * 100.0f, GridY * 100.0f, 0.0f);

		// Checks if the position is valid
		bIsValidLocation = IsValidMove(PlacementLocation, EnemyUnits[CurrentEnemyUnitIndex]);
	}
	return PlacementLocation;
}

void ATurnBasedGameMode::SelectPrePositionedUnit(AUnitBase* SelectedUnit)
{
	if (!bIsPlayerPlacingUnits || CurrentTurn != ETurnState::PlayerPlacement)
	{
		return;
	}

	AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerUnits.Contains(SelectedUnit) && !SelectedUnit->bIsPlaced)
	{
		SelectedPlayerUnit = SelectedUnit;
		SelectedPlayerUnit->bIsPlaced = true;	// Mark the unit as positioned
		PlayerController->ClearMovementRange(true);
	}
}

void ATurnBasedGameMode::HandlePlayerUnitPlacement(FVector ChosenLocation)
{
	if (SelectedPlayerUnit)
	{
		// Posiziona l'unità selezionata
		SelectedPlayerUnit->SetActorLocation(ChosenLocation);
		CurrentPlayerUnitIndex++;
		bIsPlayerPlacingUnits = false;	// to alternate between player and AI positioning
		SelectedPlayerUnit = nullptr;

		// Continue to next positioning
		CurrentTurn = ETurnState::EnemyPlacement;
		PositionUnitsAlternately();
	}
}

void ATurnBasedGameMode::StartGame()
{
	if (CurrentTurn == ETurnState::PlayerPlacement)
	{
		StartPlayerTurn();
	}
	else
	{
		StartEnemyTurn();
	}
}

void ATurnBasedGameMode::StartPlayerTurn()
{
	CurrentTurn = ETurnState::PlayerTurn;

	if (TurnIndicatorWidget)
	{
		TurnIndicatorWidget->SetTurnText(TEXT("PLAYER TURN"));
	}

	// Player units reset for new turn
	for (AUnitBase* Unit : PlayerUnits)
	{
		Unit->bCanMove = true;
		Unit->bCanAttack = true;
		Unit->bCanAttackAfterMove = false;
		Unit->bHasCompletedAction = false;
	}
}

void ATurnBasedGameMode::StartEnemyTurn()
{
	CurrentTurn = ETurnState::EnemyTurn;

	if (TurnIndicatorWidget)
	{
		TurnIndicatorWidget->SetTurnText(TEXT("AI TURN"));
	}
	CurrentEnemyUnitIndex = 0;

	if (CurrentAIBehaviorMode == EAIBehaviorMode::RandomLogic)
	{
		ExecuteRandomEnemyAction(); // Random Logic
	}
	else if (CurrentAIBehaviorMode == EAIBehaviorMode::StrategicLogic)
	{
		ExecuteEnemyAction();		// Strategic Logic
	}
}

void ATurnBasedGameMode::ExecuteRandomEnemyAction()
{
	// Update enemy units list
	EnemyUnits.RemoveAll([](AUnitBase* Unit) {
		return !IsValid(Unit) || Unit->Health <= 0;
		});

	// If all units have acted end turn
	if (CurrentEnemyUnitIndex >= EnemyUnits.Num()) 
	{
		EndTurn();
		return;
	}

	// In case unit is not valid skip to next one
	AUnitBase* EnemyUnit = EnemyUnits[CurrentEnemyUnitIndex];
	if (!EnemyUnit)
	{
		CurrentEnemyUnitIndex++;
		ExecuteRandomEnemyAction();
		return;
	}

	// Find closest player unit and try to attack if possible
	AUnitBase* ClosestPlayerUnit = FindClosestPlayerUnit(EnemyUnit);

	// If not found a player unit skip to next one
	if (!ClosestPlayerUnit)
	{
		CurrentEnemyUnitIndex++;
		ExecuteRandomEnemyAction();
		return;
	}

	// If found a player unit, check if it can be attacked first
	if (CanAttackPlayerUnit(EnemyUnit, ClosestPlayerUnit))
	{
		// Attack
		int32 CurrentDamage = FMath::RandRange(EnemyUnit->DamageMin, EnemyUnit->DamageMax);
		ClosestPlayerUnit->ApplyDamage(CurrentDamage);

		// Convert positions to notation
		FVector TargetPosition = ClosestPlayerUnit->GetActorLocation();
		FString TargetCell = ConvertPositionToNotation(TargetPosition);

		// Log the attack
		FString UnitType = EnemyUnit->GetUnitType(); // "S" or "B"
		LogAttack(TEXT("AI"), UnitType, TargetCell, CurrentDamage);

		// Update unit widget
		AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
		if (PlayerController)
		{
			PlayerController->UpdateAllUnitWidgets();

			// Highlight the cell where the attack occurred
			PlayerController->FindCellUnderUnit(ClosestPlayerUnit->GetActorLocation())->HighlightCell(false);
			PlayerController->AttackCells.Add(PlayerController->FindCellUnderUnit(ClosestPlayerUnit->GetActorLocation()));
		}

		// Counterattack if the attacker was a sniper
		if (EnemyUnit->UnitType == EUnitType::Sniper)
		{
			ClosestPlayerUnit->CounterAttack(EnemyUnit);
		}

		// Check if the conditions for the end of the game are valid
		CheckEndGameCondition();

		// Continue with next unit
		CurrentEnemyUnitIndex++;
		ExecuteRandomEnemyAction();
	}
	else
	{
		// If could not attack move casually inside the range
		TArray<FVector> ValidMoves = CalculateValidMovementLocations(EnemyUnit);
		if (ValidMoves.Num() > 0)
		{
			FVector StartLocation = EnemyUnit->GetActorLocation();
			FVector TargetLocation = ValidMoves[FMath::RandRange(0, ValidMoves.Num() - 1)];

			// Snap the positions to the grid
			StartLocation.X = FMath::GridSnap(StartLocation.X, 100.0f);
			StartLocation.Y = FMath::GridSnap(StartLocation.Y, 100.0f);
			TargetLocation.X = FMath::GridSnap(TargetLocation.X, 100.0f);
			TargetLocation.Y = FMath::GridSnap(TargetLocation.Y, 100.0f);

			Path.Empty();
			Path = FindPath(EnemyUnit, StartLocation, TargetLocation, false);

			if (Path.Num() > 0)
			{
				// Set the number of steps to move between the max movement possible and the path length
				int32 StepsToMove = FMath::Min(EnemyUnit->MaxMovement, Path.Num());

				// Limit the path to the number of steps the unit can actually move
				Path.SetNum(StepsToMove);

				// Convert positions to notation
				FString OriginCell = ConvertPositionToNotation(StartLocation);
				FString DestinationCell = ConvertPositionToNotation(Path.Last());
				LogMove(TEXT("AI"), EnemyUnit->GetUnitType(), OriginCell, DestinationCell);

				CurrentStepIndex = 0;
				MovingUnit = EnemyUnit;

				GetWorld()->GetTimerManager().SetTimer(StepMoveTimer, this, &ATurnBasedGameMode::MoveStepByStep, 0.2f, true);
				return;
			}
			else
			{
				CurrentEnemyUnitIndex++;
				ExecuteRandomEnemyAction();
			}
		}
	}
}

TArray<FVector> ATurnBasedGameMode::CalculateValidMovementLocations(AUnitBase* Unit)
{
	TArray<FVector> ValidLocations;
	FVector StartLocation = Unit->GetActorLocation();
	int32 MovementRange = Unit->MaxMovement;

	// Generate all possible movement locations within the range
	for (int32 X = -MovementRange; X <= MovementRange; X++)
	{
		for (int32 Y = -MovementRange; Y <= MovementRange; Y++)
		{
			FVector CandidateLocation = StartLocation + FVector(X * 100.0f, Y * 100.0f, 0.0f);
			// Skip starting position
			if (CandidateLocation == StartLocation) continue;
			// Check if valid
			if (IsValidMove(CandidateLocation, Unit)) ValidLocations.Add(CandidateLocation);
		}
	}
	return ValidLocations;
}

void ATurnBasedGameMode::ExecuteEnemyAction()
{
	// Update enemy units list
	EnemyUnits.RemoveAll([](AUnitBase* Unit) {
		return !IsValid(Unit) || Unit->Health <= 0;
		});

	// If all units have acted end turn
	if (CurrentEnemyUnitIndex >= EnemyUnits.Num()) 
	{
		EndTurn();
		return;
	}

	// In case unit is not valid skip to next one
	AUnitBase* EnemyUnit = EnemyUnits[CurrentEnemyUnitIndex];
	if (!EnemyUnit)
	{
		CurrentEnemyUnitIndex++;
		ExecuteEnemyAction();
		return;
	}

	// Find closest player unit
	AUnitBase* ClosestPlayerUnit = FindClosestPlayerUnit(EnemyUnit);

	// If not found a player unit skip to next one
	if (!ClosestPlayerUnit)
	{
		CurrentEnemyUnitIndex++;
		ExecuteEnemyAction();
		return;
	}

	// If found a player unit, check if it can be attacked first
	if (CanAttackPlayerUnit(EnemyUnit, ClosestPlayerUnit))
	{
		// Attack:
		int32 CurrentDamage = FMath::RandRange(EnemyUnit->DamageMin, EnemyUnit->DamageMax);
		ClosestPlayerUnit->ApplyDamage(CurrentDamage);

		// Convert positions to notation
		FVector TargetPosition = ClosestPlayerUnit->GetActorLocation();
		FString TargetCell = ConvertPositionToNotation(TargetPosition);

		// Log the attack
		LogAttack(TEXT("AI"), EnemyUnit->GetUnitType(), TargetCell, CurrentDamage);

		// Update unit widget
		AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
		if (PlayerController)
		{
			PlayerController->UpdateAllUnitWidgets();

			// Highlight the cell where the attack occurred
			PlayerController->FindCellUnderUnit(ClosestPlayerUnit->GetActorLocation())->HighlightCell(false);
			PlayerController->AttackCells.Add(PlayerController->FindCellUnderUnit(ClosestPlayerUnit->GetActorLocation()));
		}

		// Counterattack
		if (EnemyUnit->UnitType == EUnitType::Sniper)
		{
			ClosestPlayerUnit->CounterAttack(EnemyUnit);
		}

		// Check if the conditions for the end of the game are valid
		CheckEndGameCondition();

		// Continue with next unit
		CurrentEnemyUnitIndex++;
		ExecuteEnemyAction();
	}
	else
	{
		// If could not attack move towards enemy
		FVector StartLocation = EnemyUnit->GetActorLocation();
		FVector TargetLocation = ClosestPlayerUnit->GetActorLocation();

		StartLocation.X = FMath::GridSnap(StartLocation.X, 100.0f);
		StartLocation.Y = FMath::GridSnap(StartLocation.Y, 100.0f);
		TargetLocation.X = FMath::GridSnap(TargetLocation.X, 100.0f);
		TargetLocation.Y = FMath::GridSnap(TargetLocation.Y, 100.0f);

		Path.Empty();
		Path = FindPath(EnemyUnit, StartLocation, TargetLocation, false);

		if (Path.Num() > 0)
		{
			// Set the number of steps to move between the max movement possible and the path length
			int32 StepsToMove = FMath::Min(EnemyUnit->MaxMovement, Path.Num()); 

			// Limit the path to the number of steps the unit can actually move
			Path.SetNum(StepsToMove); 

			// Convert positions to notation
			FString OriginCell = ConvertPositionToNotation(StartLocation);
			FString DestinationCell = ConvertPositionToNotation(Path.Last());

			// Log the move
			LogMove(TEXT("AI"), EnemyUnit->GetUnitType(), OriginCell, DestinationCell);

			CurrentStepIndex = 0;
			MovingUnit = EnemyUnit;

			GetWorld()->GetTimerManager().SetTimer(StepMoveTimer, this, &ATurnBasedGameMode::MoveStepByStep, 0.2f, true);
			return;
		}
		else
		{
			// If no path is found, skip to the next unit
			CurrentEnemyUnitIndex++;
			ExecuteEnemyAction();
		}
	}
}

AUnitBase* ATurnBasedGameMode::FindClosestPlayerUnit(AUnitBase* EnemyUnit)
{
	// If the enemy unit is not valid, return nullptr
	if (!EnemyUnit)
	{
		return nullptr;
	}

	// Early exit if no player units exist
	if (PlayerUnits.Num() == 0)
	{
		CheckEndGameCondition();
		return nullptr;
	}

	AUnitBase* ClosestPlayerUnit = nullptr;
	float ClosestDistance = FLT_MAX;	// set to maximum float value

	// Try to find the closest player unit between the all the player units
	for (AUnitBase* PlayerUnit : PlayerUnits)
	{
		// If the player unit is not valid, skip to the next one
		if (!PlayerUnit) continue;

		// Calculate the distance between the enemy unit and the player unit
		float Distance = FVector::Dist(EnemyUnit->GetActorLocation(), PlayerUnit->GetActorLocation());

		// If true we found the closest player unit
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			ClosestPlayerUnit = PlayerUnit;
		}
	}
	return ClosestPlayerUnit;
}

bool ATurnBasedGameMode::CanAttackPlayerUnit(AUnitBase* EnemyUnit, AUnitBase* PlayerUnit)
{
	FVector EnemyPosition = EnemyUnit->GetActorLocation();
	FVector PlayerPosition = PlayerUnit->GetActorLocation();

	// Calculate the Manhattan distance between the enemy and player units
	int32 Distance = FMath::Abs(PlayerPosition.X - EnemyPosition.X) / 100 + FMath::Abs(PlayerPosition.Y - EnemyPosition.Y) / 100;

	return (Distance <= EnemyUnit->AttackRange); // true if player unit is in attack range
}

void ATurnBasedGameMode::EndTurn()
{
	AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());

	// Change turn state
	if (CurrentTurn == ETurnState::PlayerTurn)
	{
		// Clear movement and attack ranges for all units before starting enemy turn
		if (PlayerController)
		{
			PlayerController->ClearMovementRange(true);		// Clear movements
			PlayerController->ClearMovementRange(false);	// Clear attacks
		}
		// No control needed because change turn button appears only if all units have acted
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATurnBasedGameMode::StartEnemyTurn, 0.5f, false);
	}
	else if (CurrentTurn == ETurnState::EnemyTurn)
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATurnBasedGameMode::StartPlayerTurn, 1.0f, false);
	}
}

TArray<FVector> ATurnBasedGameMode::FindPath(AUnitBase* Unit, FVector StartLocation, FVector TargetLocation, bool bIsPlayerControlled)
{
	Path.Empty();

	TMap<FVector, FPathNode*> OpenList;
	TSet<FVector> ClosedList;

	FPathNode* StartNode = new FPathNode(StartLocation);
	StartNode->HCost = FMath::Abs(TargetLocation.X - StartLocation.X) + FMath::Abs(TargetLocation.Y - StartLocation.Y);		// Manhattan distance between Start and Target
	StartNode->GCost = 0;
	StartNode->FCost = StartNode->GCost + StartNode->HCost;

	OpenList.Add(StartLocation, StartNode);

	int32 MaxIterations = 1000; // Limit the number of iterations to prevent infinite loops
	int32 Iterations = 0;

	while (OpenList.Num() > 0 && Iterations++ < MaxIterations)
	{
		// Find the node with the lowest FCost
		FVector LowestCostKey;
		FPathNode* CurrentNode = nullptr;
		int32 LowestCost = INT_MAX;

		for (auto& Elem : OpenList)
		{
			if (Elem.Value->FCost < LowestCost)
			{
				LowestCost = Elem.Value->FCost;
				CurrentNode = Elem.Value;
				LowestCostKey = Elem.Key;
			}
		}
		OpenList.Remove(LowestCostKey);

		// If Start or Target location is zero, break the loop
		if (StartLocation.IsZero() || TargetLocation.IsZero())
		{
			break;
		}

		// If target reached, start pathing
		if (bIsPlayerControlled)
		{
			if (FVector::Dist(CurrentNode->Position, TargetLocation) <= 0.0f)  // <= 0.0f to stop when the target is reached
			{
				while (CurrentNode)
				{
					Path.Insert(CurrentNode->Position, 0);
					CurrentNode = CurrentNode->Parent;
				}

				for (auto& Elem : OpenList)
					delete Elem.Value;

				return Path;
			}
		}
		else
		{
			if (FVector::Dist(CurrentNode->Position, TargetLocation) <= 100.0f)  // <= 100.0f to stop before reaching the target
			{
				while (CurrentNode)
				{
					Path.Insert(CurrentNode->Position, 0);
					CurrentNode = CurrentNode->Parent;
				}

				for (auto& Elem : OpenList)
					delete Elem.Value;

				return Path;
			}
		}
		// Possible moves
		TArray<FVector> Neighbors = {
			CurrentNode->Position + FVector(100.0f, 0, 0),		// Right
			CurrentNode->Position + FVector(-100.0f, 0, 0),		// Left	
			CurrentNode->Position + FVector(0, 100.0f, 0), 		// Up
			CurrentNode->Position + FVector(0, -100.0f, 0) };	// Down

		for (FVector NeighborPosition : Neighbors)
		{
			// Skip invalid cells
			if (!IsValidMove(NeighborPosition, Unit))
			{
				continue;
			}
			// If the neighbor is already in the closed list, skip it
			if (ClosedList.Contains(NeighborPosition)) continue;
				
			// New GCost is the cost from the start node to the neighbor
			int32 NewGCost = CurrentNode->GCost + 1;

			if (!OpenList.Contains(NeighborPosition))
			{
				FPathNode* NeighborNode = new FPathNode(NeighborPosition);
				NeighborNode->Parent = CurrentNode;
				NeighborNode->GCost = NewGCost;
				NeighborNode->HCost = FMath::Abs(TargetLocation.X - NeighborPosition.X) + FMath::Abs(TargetLocation.Y - NeighborPosition.Y);
				NeighborNode->FCost = NeighborNode->GCost + NeighborNode->HCost;

				OpenList.Add(NeighborPosition, NeighborNode);
			}
			else
			{
				FPathNode* ExistingNode = OpenList[NeighborPosition];
				if (NewGCost < ExistingNode->GCost)
				{
					ExistingNode->GCost = NewGCost;
					ExistingNode->FCost = ExistingNode->GCost + ExistingNode->HCost;
					ExistingNode->Parent = CurrentNode;
				}
			}
		}
		ClosedList.Add(CurrentNode->Position);
	}

	// Cleanup memory
	for (auto& Elem : OpenList)
		delete Elem.Value;

	return TArray<FVector>();

	// Clear the lists
	OpenList.Empty();
	ClosedList.Empty();
}

void ATurnBasedGameMode::SetObstaclePositions(const TArray<FVector>& Positions)
{
	ObstaclePositions = Positions;	 // Fills the array with obstacle positions
}

bool ATurnBasedGameMode::IsValidMove(FVector Position, AUnitBase* Unit)
{
	FVector GridPosition = FVector(FMath::RoundToInt(Position.X / 100) * 100, FMath::RoundToInt(Position.Y / 100) * 100, Position.Z);

	// Check if inside the grid
	if (GridPosition.X < 0 || GridPosition.X >= GridSize * 100 || GridPosition.Y < 0 || GridPosition.Y >= GridSize * 100)
	{
		return false;
	}

	// Check if blocked by an obstacle
	if (ObstaclePositions.Contains(GridPosition))
	{
		return false;
	}

	// Check blocking units (PlayerUnits and EnemyUnits)
	for (AUnitBase* BlockingUnit : PlayerUnits)
	{
		if (BlockingUnit && FVector::Dist(BlockingUnit->GetActorLocation(), GridPosition) <= 50.0f)
		{
			return false;
		}
	}
	for (AUnitBase* BlockingUnit : EnemyUnits)
	{
		// Ignore current unit
		if (BlockingUnit == Unit)
		{
			continue;
		}

		if (BlockingUnit && FVector::Dist(BlockingUnit->GetActorLocation(), GridPosition) <= 50.0f)
		{
			return false;
		}
	}
	return true;
}

void ATurnBasedGameMode::MoveStepByStep()
{
	AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());

	// Check if MovingUnit is valid
	if (!MovingUnit)
	{
		GetWorld()->GetTimerManager().ClearTimer(StepMoveTimer);
		return;
	}

	// Check if CurrentStepIndex is out of Path interval
	if (!Path.IsValidIndex(CurrentStepIndex))
	{
		// End of movement, try to attack
		AUnitBase* ClosestPlayerUnit = FindClosestPlayerUnit(MovingUnit);
		if (ClosestPlayerUnit && CanAttackPlayerUnit(MovingUnit, ClosestPlayerUnit))
		{
			// Attack
			int32 CurrentDamage = FMath::RandRange(MovingUnit->DamageMin, MovingUnit->DamageMax);
			ClosestPlayerUnit->ApplyDamage(CurrentDamage);

			// Highlight the cell under the target unit
			PlayerController->FindCellUnderUnit(ClosestPlayerUnit->GetActorLocation())->HighlightCell(false);
			PlayerController->AttackCells.Add(PlayerController->FindCellUnderUnit(ClosestPlayerUnit->GetActorLocation()));

			// Convert positions to notation
			FVector TargetPosition = ClosestPlayerUnit->GetActorLocation();
			FString TargetCell = ConvertPositionToNotation(TargetPosition);

			// Update Widget
			if (PlayerController)
			{
				PlayerController->UpdateAllUnitWidgets();
			}

			// Log attack
			FString UnitType = MovingUnit->GetUnitType(); // "S" or "B"
			LogAttack(TEXT("AI"), UnitType, TargetCell, CurrentDamage);

			// Counter-attack (if possible)
			if (MovingUnit->UnitType == EUnitType::Sniper)
			{
				ClosestPlayerUnit->CounterAttack(MovingUnit);
			}
			CheckEndGameCondition();
		}

		// Change into next unit
		MovingUnit = nullptr;
		CurrentEnemyUnitIndex++;

		// Check the logic
		if (CurrentAIBehaviorMode == EAIBehaviorMode::RandomLogic)
		{
			ExecuteRandomEnemyAction(); // Random Logic
		}
		else if (CurrentAIBehaviorMode == EAIBehaviorMode::StrategicLogic)
		{
			ExecuteEnemyAction();		// Strategic Logic
		}
		return;
	}
	// Get the next position from the path
	FVector NextPosition = Path[CurrentStepIndex];

	// Highlht the cell under the unit during movement
	PlayerController->FindCellUnderUnit(NextPosition)->HighlightCell(true);
	PlayerController->HighlightedCells.Add(PlayerController->FindCellUnderUnit(NextPosition));

	// Set the unit into the new position
	MovingUnit->SetActorLocation(NextPosition);
	CurrentStepIndex++;
}

void ATurnBasedGameMode::LogMove(const FString& PlayerID, const FString& UnitType, const FString& OriginCell, const FString& DestinationCell)
{
	FString MoveEntry = FString::Printf(TEXT("%s : %s  %s -> %s"), *PlayerID, *UnitType, *OriginCell, *DestinationCell);
	History.Add(MoveEntry);

	AGridPlayerController* GridPlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
	if (GridPlayerController->UnitInfoWidget)
	{
		GridPlayerController->UnitInfoWidget->UpdateHistory(History);
	}
}

void ATurnBasedGameMode::LogAttack(const FString& PlayerID, const FString& UnitType, const FString& TargetCell, int32 Damage)
{
	FString AttackEntry = FString::Printf(TEXT("%s : %s  %s %d"), *PlayerID, *UnitType, *TargetCell, Damage);
	History.Add(AttackEntry);

	AGridPlayerController* GridPlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
	if (GridPlayerController->UnitInfoWidget)
	{
		GridPlayerController->UnitInfoWidget->UpdateHistory(History);
	}
}

FString ATurnBasedGameMode::ConvertPositionToNotation(const FVector& Position)
{
	// Assuming the grid is 100x100 units per cell
	int32 RowIndex = FMath::FloorToInt(Position.X / 100); // Calculate row index
	int32 ColIndex = FMath::FloorToInt(Position.Y / 100); // Calculate column index

	// Convert ColIndex in letters (A...Y)
	TCHAR ColLetter = 'A' + ColIndex;

	// Convert RowIndex in numbers (1...25)
	FString CellNotation = FString::Printf(TEXT("%c%d"), ColLetter, RowIndex + 1);
	return CellNotation;
}

void ATurnBasedGameMode::CheckEndGameCondition()
{
	if (PlayerUnits.Num() == 0 && EnemyUnits.Num() == 0)
	{
		if (TurnIndicatorWidget) TurnIndicatorWidget->SetEndGameText(TEXT("Draw!"));
		EndGame();
	}
	else if (PlayerUnits.Num() == 0)
	{
		if (TurnIndicatorWidget) TurnIndicatorWidget->SetEndGameText(TEXT("AI Wins!"));
		EndGame();
	}
	else if (EnemyUnits.Num() == 0)
	{
		if (TurnIndicatorWidget) TurnIndicatorWidget->SetEndGameText(TEXT("Player Wins!"));
		EndGame();
	}
}

void ATurnBasedGameMode::EndGame()
{
	AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController)
	{
		PlayerController->ClearMovementRange(false);	// Clear attacks
		PlayerController->ClearMovementRange(true);		// Clear movement range if shown
		PlayerController->DisablePlayerInput();			// Disable inputs
	}
}