// Fill out your copyright notice in the Description page of Project Settings.


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
	CurrentTurn = ETurnState::PlayerTurn;
	GridSize = 25;
}

void ATurnBasedGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (TurnIndicatorWidgetClass)
	{
		TurnIndicatorWidget = CreateWidget<UTurnIndicatorWidget>(GetWorld(), TurnIndicatorWidgetClass);
		if (TurnIndicatorWidget)
		{
			TurnIndicatorWidget->AddToViewport(1);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("TurnIndicatorWidget not created"));
		}
	}
	SpawnUnits();
}

void ATurnBasedGameMode::CoinFlip()
{
	bIsPlayerStarting = FMath::RandBool(); // Random starting player
	CurrentTurn = bIsPlayerStarting ? ETurnState::PlayerTurn : ETurnState::EnemyTurn;

	UE_LOG(LogTemp, Warning, TEXT("Coin Flip Result: %s starts first"), bIsPlayerStarting ? TEXT("Player") : TEXT("Enemy"));

	if (TurnIndicatorWidget)
	{
		if (bIsPlayerStarting)
		{
			TurnIndicatorWidget->SetTurnText(TEXT("Starts turn PLAYER"));
		}
		else
		{
			TurnIndicatorWidget->SetTurnText(TEXT("Starts turn AI"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TurnIndicatorWidget not found"));
	}
}

void ATurnBasedGameMode::SpawnUnits()
{
	CoinFlip();
	CurrentUnitPlacementIndex = 0;

	if (GetWorld())
	{
		// Spawn player unit
		if (PlayerSniperClass && PlayerBrawlerClass)
		{
			AUnitBase* PlayerSniper = GetWorld()->SpawnActor<AUnitBase>(PlayerSniperClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (PlayerSniper)
			{
				PlayerSniper->bIsPlayerControlled = true;
				PlayerSniper->UnitType = EUnitType::Sniper;	//Unit Type:
				PlayerSniper->UpdateMaterial();
				PlayerUnits.Add(PlayerSniper);
			}			
			
			AUnitBase* PlayerBrawler = GetWorld()->SpawnActor<AUnitBase>(PlayerBrawlerClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (PlayerBrawler)
			{
				PlayerBrawler->bIsPlayerControlled = true;
				PlayerBrawler->UnitType = EUnitType::Brawler;	//Unit Type:
				PlayerBrawler->UpdateMaterial();
				PlayerUnits.Add(PlayerBrawler);
			}
		}

		// Spawn enemy unit
		if (EnemySniperClass && EnemyBrawlerClass)
		{
			AUnitBase* EnemySniper = GetWorld()->SpawnActor<AUnitBase>(EnemySniperClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (EnemySniper)
			{
				EnemySniper->bIsPlayerControlled = false;
				EnemySniper->UnitType = EUnitType::Sniper;	//Unit Type:
				EnemySniper->UpdateMaterial();
				EnemyUnits.Add(EnemySniper);
			}

			AUnitBase* EnemyBrawler = GetWorld()->SpawnActor<AUnitBase>(EnemyBrawlerClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (EnemyBrawler)
			{
				EnemyBrawler->bIsPlayerControlled = false;
				EnemyBrawler->UnitType = EUnitType::Brawler;	//Unit Type:
				EnemyBrawler->UpdateMaterial();
				EnemyUnits.Add(EnemyBrawler);
			}
		}
		PositionUnitsAlternately();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No world found"));
	}
}

void ATurnBasedGameMode::PositionUnitsAlternately()
{
	// Se tutte le unità sono posizionate, avvia il gioco
	if (CurrentPlayerUnitIndex >= PlayerUnits.Num() && CurrentEnemyUnitIndex >= EnemyUnits.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("All units positioned. Starting game."));
		StartGame();
		return;
	}

	// Determina di chi è il turno per il posizionamento
	bool bIsPlayerTurn = (bIsPlayerStarting && (CurrentPlayerUnitIndex + CurrentEnemyUnitIndex) % 2 == 0) || (!bIsPlayerStarting && (CurrentPlayerUnitIndex + CurrentEnemyUnitIndex) % 2 != 0);

	if (bIsPlayerTurn && CurrentPlayerUnitIndex < PlayerUnits.Num())
	{
		// Aspetta l'input del giocatore per posizionare l'unità
		UE_LOG(LogTemp, Warning, TEXT("Player's turn to position unit %d."), CurrentPlayerUnitIndex);

		bIsPlayerPlacingUnits = true; // Attiva la modalità di posizionamento per il giocatore
	}
	else if (!bIsPlayerTurn && CurrentEnemyUnitIndex < EnemyUnits.Num())
	{
		// Posizionamento automatico dell'IA
		UE_LOG(LogTemp, Warning, TEXT("AI's turn to position unit %d."), CurrentEnemyUnitIndex);

		FVector EnemyPlacementLocation = CalculateEnemyPlacementLocation();
		EnemyUnits[CurrentEnemyUnitIndex]->SetActorLocation(EnemyPlacementLocation);

		UE_LOG(LogTemp, Warning, TEXT("AI positioned unit at %s"), *EnemyPlacementLocation.ToString());

		// Incrementa l'indice dell'IA
		CurrentEnemyUnitIndex++;

		// Continua al prossimo turno di posizionamento
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATurnBasedGameMode::PositionUnitsAlternately, 1.5f, false);
	}
}

FVector ATurnBasedGameMode::CalculateEnemyPlacementLocation()
{
	FVector PlacementLocation;
	bool bIsValidLocation = false;

	while (!bIsValidLocation)
	{
		// Genera una posizione casuale sulla griglia
		int32 GridX = FMath::RandRange(0, 24);
		int32 GridY = FMath::RandRange(0, 24);
		PlacementLocation = FVector(GridX * 100.0f, GridY * 100.0f, 0.0f); // Ogni cella è larga 100 unità

		// Controlla se la posizione è valida
		bIsValidLocation = IsLocationValid(PlacementLocation);
	}
	return PlacementLocation;
}

bool ATurnBasedGameMode::IsLocationValid(FVector Location)
{
    TArray<AActor*> OverlappingActors;
    // Check for obstacles
    UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Location, 50.0f, TArray<TEnumAsByte<EObjectTypeQuery>>(), AObstacle::StaticClass(), TArray<AActor*>(), OverlappingActors);

    // If obstacle -> not valid
	if (OverlappingActors.Num() > 0)
    return false;

	// Check units
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Location, 50.0f, TArray<TEnumAsByte<EObjectTypeQuery>>(), AUnitBase::StaticClass(), TArray<AActor*>(), OverlappingActors);

	return OverlappingActors.Num() == 0;
}

void ATurnBasedGameMode::HandlePlayerUnitPlacement(FVector ChosenLocation)
{
	if (bIsPlayerPlacingUnits && CurrentPlayerUnitIndex < PlayerUnits.Num())
	{
		// Posiziona l'unità selezionata
		PlayerUnits[CurrentPlayerUnitIndex]->SetActorLocation(ChosenLocation);
		UE_LOG(LogTemp, Warning, TEXT("Player placed unit %d at %s"), CurrentPlayerUnitIndex, *ChosenLocation.ToString());

		CurrentPlayerUnitIndex++;
		bIsPlayerPlacingUnits = false;

		// Continua al prossimo posizionamento
		PositionUnitsAlternately();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No unit to place or not player's turn."));
	}
}

void ATurnBasedGameMode::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game started"));
	if (CurrentTurn == ETurnState::PlayerTurn)
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
	UE_LOG(LogTemp, Warning, TEXT("Player Turn Started"));
	CurrentTurn = ETurnState::PlayerTurn;

	if (TurnIndicatorWidget)
	{
		TurnIndicatorWidget->SetTurnText(TEXT("PLAYER TURN"));
	}

	for (AUnitBase* Unit : PlayerUnits)
	{
		Unit->bCanMove = true;
		Unit->bCanAttack = true;
		Unit->bCanAttackAfterMove = false;
		Unit->bHasCompletedAction = false;
	}
	UE_LOG(LogTemp, Warning, TEXT("Player's units reset for a new turn."));
}

void ATurnBasedGameMode::StartEnemyTurn()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy Turn Started"));
	CurrentTurn = ETurnState::EnemyTurn;

	if (TurnIndicatorWidget)
	{
		TurnIndicatorWidget->SetTurnText(TEXT("AI TURN"));
	}
	CurrentEnemyUnitIndex = 0;
	ExecuteEnemyAction();
}

void ATurnBasedGameMode::ExecuteEnemyAction()
{
	if (CurrentEnemyUnitIndex >= EnemyUnits.Num()) // Se tutte le unità hanno agito
	{
		EndTurn();
		return;
	}

	AUnitBase* EnemyUnit = EnemyUnits[CurrentEnemyUnitIndex];
	if (!EnemyUnit)
	{
		CurrentEnemyUnitIndex++;
		ExecuteEnemyAction();
		return;
	}

	// find closest player unit
	AUnitBase* ClosestPlayerUnit = FindClosestPlayerUnit(EnemyUnit);

	// if found
	if (ClosestPlayerUnit)
	{
		if (CanAttackPlayerUnit(EnemyUnit, ClosestPlayerUnit))
		{
			// Attack
			int32 CurrentDamage = FMath::RandRange(EnemyUnit->DamageMin, EnemyUnit->DamageMax);
			ClosestPlayerUnit->ApplyDamage(CurrentDamage);
			UE_LOG(LogTemp, Warning, TEXT("Enemy attacked player unit at X=%f, Y=%f"), ClosestPlayerUnit->GetActorLocation().X, ClosestPlayerUnit->GetActorLocation().Y);

			// Update unit widget
			AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
			if (PlayerController)
			{
				PlayerController->UpdateAllUnitWidgets();
			}

			// Counterattack
			if (EnemyUnit->UnitType == EUnitType::Sniper)
			{
				ClosestPlayerUnit->CounterAttack(EnemyUnit);
				PlayerController->UpdateAllUnitWidgets(); // Update widget again if counterattack
			}

			CurrentEnemyUnitIndex++;
			ExecuteEnemyAction();
		}
		else
		{
			// Esegui movimento verso il bersaglio
			FVector StartLocation = EnemyUnit->GetActorLocation();
			FVector TargetLocation = ClosestPlayerUnit->GetActorLocation();

			// Allineiamo alla griglia
			StartLocation.X = FMath::GridSnap(StartLocation.X, 100.0f);
			StartLocation.Y = FMath::GridSnap(StartLocation.Y, 100.0f);
			TargetLocation.X = FMath::GridSnap(TargetLocation.X, 100.0f);
			TargetLocation.Y = FMath::GridSnap(TargetLocation.Y, 100.0f);

			Path.Empty();
			Path = FindPath(EnemyUnit, StartLocation, TargetLocation, false);

			if (Path.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Enemy moving towards player at X=%f, Y=%f"), TargetLocation.X, TargetLocation.Y);
				UE_LOG(LogTemp, Warning, TEXT("Enemy start location at X=%f, Y=%f"), StartLocation.X, StartLocation.Y);

				int32 StepsToMove = FMath::Min(EnemyUnit->MaxMovement, Path.Num());
				TArray<FVector> LimitedPath;
				for (int32 i = 1; i < StepsToMove; i++)
				{
					LimitedPath.Add(Path[i]);
				}
				// Usa il percorso limitato
				Path = LimitedPath;

				CurrentStepIndex = 0;
				MovingUnit = EnemyUnit;
				GetWorld()->GetTimerManager().SetTimer(StepMoveTimer, this, &ATurnBasedGameMode::MoveStepByStep, 0.2f, true);
				return;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("No valid path found for enemy unit!"));
				CurrentEnemyUnitIndex++;
				ExecuteEnemyAction();
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No player unit found for enemy unit!"));
		CurrentEnemyUnitIndex++;
		ExecuteEnemyAction(); // Procedi alla prossima unità
	}
}

AUnitBase* ATurnBasedGameMode::FindClosestPlayerUnit(AUnitBase* EnemyUnit)
{
	if (!EnemyUnit)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyUnit is null, cannot find closest player unit."));
		return nullptr;
	}

	AUnitBase* ClosestPlayerUnit = nullptr;
	float ClosestDistance = FLT_MAX;

	for (AUnitBase* PlayerUnit : PlayerUnits)
	{
		if (PlayerUnit) // Verifica che l'unità sia valida e attiva
		{
			float Distance = FVector::Dist(EnemyUnit->GetActorLocation(), PlayerUnit->GetActorLocation());
			if (Distance < ClosestDistance)
			{
				ClosestDistance = Distance;
				ClosestPlayerUnit = PlayerUnit;
			}
		}
	}

	if (ClosestPlayerUnit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Closest player unit found at X=%f, Y=%f"),
			ClosestPlayerUnit->GetActorLocation().X, ClosestPlayerUnit->GetActorLocation().Y);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No valid player unit found near enemy unit."));
	}

	return ClosestPlayerUnit;
}

bool ATurnBasedGameMode::CanAttackPlayerUnit(AUnitBase* EnemyUnit, AUnitBase* PlayerUnit)
{
	FVector EnemyPosition = EnemyUnit->GetActorLocation();
	FVector PlayerPosition = PlayerUnit->GetActorLocation();

	// Calcolo distanza Manhattan
	int32 Distance = FMath::Abs(PlayerPosition.X - EnemyPosition.X) / 100 + FMath::Abs(PlayerPosition.Y - EnemyPosition.Y) / 100;

	return (Distance <= EnemyUnit->AttackRange); // True if player unit is in attack range
}

void ATurnBasedGameMode::EndTurn()
{
	// Clear movement range in case is not already done
	AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController)
	{
		PlayerController->ClearMovementRange();
	}

	// Change turn state
	if (CurrentTurn == ETurnState::PlayerTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player turn completed. Switching to Enemy turn."));
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATurnBasedGameMode::StartEnemyTurn, 0.5f, false);
	}
	else if (CurrentTurn == ETurnState::EnemyTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy turn completed. Switching to Player turn."));
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
	//UE_LOG(LogTemp, Warning, TEXT("Starting pathfinding from: X=%f Y=%f"), StartLocation.X, StartLocation.Y);

	int32 MaxIterations = 1000; // Limite di sicurezza
	int32 Iterations = 0;

	while (OpenList.Num() > 0 && Iterations++ < MaxIterations)
	{
		// Trova il nodo con costo minore
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

		if (StartLocation.IsZero() || TargetLocation.IsZero())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Invalid start or target location"));
			break;
		}

		// If target reached, start pathing
		if (bIsPlayerControlled)
		{
			if (FVector::Dist(CurrentNode->Position, TargetLocation) <= 0.0f)  // <= 0.0f to stop when the target is reched
			{
				while (CurrentNode)
				{
					Path.Insert(CurrentNode->Position, 0);
					CurrentNode = CurrentNode->Parent;
				}

				for (auto& Elem : OpenList)
					delete Elem.Value;

				//UE_LOG(LogTemp, Warning, TEXT("Path found"));
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
				/*
				for (FVector Step : Path)
				{
					UE_LOG(LogTemp, Warning, TEXT(" -> X=%f Y=%f"), Step.X, Step.Y);
				}*/

				for (auto& Elem : OpenList)
					delete Elem.Value;

				//UE_LOG(LogTemp, Warning, TEXT("Path found"));
				return Path;
			}
		}
		// Possible moves
		TArray<FVector> Neighbors = {
			CurrentNode->Position + FVector(100.0f, 0, 0), 
			CurrentNode->Position + FVector(-100.0f, 0, 0), 
			CurrentNode->Position + FVector(0, 100.0f, 0), 
			CurrentNode->Position + FVector(0, -100.0f, 0)};

		for (FVector NeighborPosition : Neighbors)
		{
			if (!IsValidMove(NeighborPosition, TargetLocation, Unit))
			{
				//UE_LOG(LogTemp, Warning, TEXT("Not valid cell at X=%f Y=%f"), NeighborPosition.X, NeighborPosition.Y);
				continue;
			}

			if (ClosedList.Contains(NeighborPosition)) continue;
				
			int32 NewGCost = CurrentNode->GCost + 1;

			if (!OpenList.Contains(NeighborPosition))
			{
				FPathNode* NeighborNode = new FPathNode(NeighborPosition);
				NeighborNode->Parent = CurrentNode;
				NeighborNode->GCost = NewGCost;
				NeighborNode->HCost = FMath::Abs(TargetLocation.X - NeighborPosition.X) + FMath::Abs(TargetLocation.Y - NeighborPosition.Y);
				NeighborNode->FCost = NeighborNode->GCost + NeighborNode->HCost;

				OpenList.Add(NeighborPosition, NeighborNode);
				//UE_LOG(LogTemp, Warning, TEXT("Added new neighbor at X=%f Y=%f"), NeighborPosition.X, NeighborPosition.Y);
			}
			else
			{
				FPathNode* ExistingNode = OpenList[NeighborPosition];
				if (NewGCost < ExistingNode->GCost)
				{
					ExistingNode->GCost = NewGCost;
					ExistingNode->FCost = ExistingNode->GCost + ExistingNode->HCost;
					ExistingNode->Parent = CurrentNode;

					//UE_LOG(LogTemp, Warning, TEXT("Updated existing neighbor at X=%f Y=%f"), NeighborPosition.X, NeighborPosition.Y);
				}
			}
		}
		ClosedList.Add(CurrentNode->Position);
	}

	UE_LOG(LogTemp, Warning, TEXT("No valid path found after %d iterations"), Iterations);

	// Cleanup memoria residua
	for (auto& Elem : OpenList)
		delete Elem.Value;

	return TArray<FVector>();

	OpenList.Empty();
	ClosedList.Empty();
}

void ATurnBasedGameMode::SetObstaclePositions(const TArray<FVector>& Positions)
{
	ObstaclePositions = Positions; // Update array with obstacle positions
	UE_LOG(LogTemp, Warning, TEXT("Obstacle positions updated. Total obstacles: %d"), ObstaclePositions.Num());
}


bool ATurnBasedGameMode::IsValidMove(FVector Position, FVector TargetLocation, AUnitBase* Unit)
{
	FVector GridPosition = FVector(FMath::RoundToInt(Position.X / 100) * 100, FMath::RoundToInt(Position.Y / 100) * 100, Position.Z);
	FVector TargetGridPosition = FVector(FMath::RoundToInt(TargetLocation.X / 100) * 100, FMath::RoundToInt(TargetLocation.Y / 100) * 100, TargetLocation.Z);

	// Check if inside the grid
	if (GridPosition.X < 0 || GridPosition.X >= GridSize * 100 || GridPosition.Y < 0 || GridPosition.Y >= GridSize * 100)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Position out of bounds! X=%f Y=%f"), GridPosition.X, GridPosition.Y);
		return false;
	}

	// Check if blocked by an obstacle
	if (ObstaclePositions.Contains(GridPosition))
	{
		UE_LOG(LogTemp, Warning, TEXT("Position blocked by obstacle at X=%f Y=%f"), GridPosition.X, GridPosition.Y);
		return false;
	}

	// Check blocking units (PlayerUnits and EnemyUnits)
	for (AUnitBase* BlockingUnit : PlayerUnits)
	{
		if (BlockingUnit && FVector::Dist(BlockingUnit->GetActorLocation(), GridPosition) <= 50.0f)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Cell blocked by player unit!"));
			return false;
		}
	}

	for (AUnitBase* BlockingUnit : EnemyUnits)
	{
		// Ignora l'unità corrente
		if (BlockingUnit == Unit)
		{
			continue;
		}

		if (BlockingUnit && FVector::Dist(BlockingUnit->GetActorLocation(), GridPosition) <= 50.0f)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Cell blocked by enemy unit!"));
			return false;
		}
	}
	return true;
}

void ATurnBasedGameMode::MoveStepByStep()
{
	UE_LOG(LogTemp, Warning, TEXT("CurrentStepIndex: %d, Path.Num: %d"), CurrentStepIndex, Path.Num());

	if (!Path.IsValidIndex(CurrentStepIndex))
	{
		UE_LOG(LogTemp, Error, TEXT("Path index out of bounds! Index: %d"), CurrentStepIndex);
		GetWorld()->GetTimerManager().ClearTimer(StepMoveTimer);
		MovingUnit = nullptr;
		CurrentEnemyUnitIndex++;
		ExecuteEnemyAction();
		return;
	}

	if (!MovingUnit)
	{
		UE_LOG(LogTemp, Error, TEXT("MovingUnit is null. Cannot proceed."));
		GetWorld()->GetTimerManager().ClearTimer(StepMoveTimer);
		return;
	}

	if (CurrentStepIndex < Path.Num())
	{
		FVector NextPosition = Path[CurrentStepIndex];
		MovingUnit->SetActorLocation(NextPosition);
		CurrentStepIndex++;
		UE_LOG(LogTemp, Warning, TEXT("AI moved to: %s"), *NextPosition.ToString());
	}
	else
	{
		// Fine del percorso
		UE_LOG(LogTemp, Warning, TEXT("Movement finished"));
		GetWorld()->GetTimerManager().ClearTimer(StepMoveTimer);

		AUnitBase* ClosestPlayerUnit = FindClosestPlayerUnit(MovingUnit);
		if (ClosestPlayerUnit && CanAttackPlayerUnit(MovingUnit, ClosestPlayerUnit))
		{
			int32 CurrentDamage = FMath::RandRange(MovingUnit->DamageMin, MovingUnit->DamageMax);
			ClosestPlayerUnit->ApplyDamage(CurrentDamage);
			UE_LOG(LogTemp, Warning, TEXT("Enemy %s attacked Player Unit at %s after moving"), *MovingUnit->GetName(), *ClosestPlayerUnit->GetActorLocation().ToString());
		}

		MovingUnit = nullptr;
		CurrentEnemyUnitIndex++;
		// After the end of the movement start ExecuteEnemyAction for next enemy unit
		ExecuteEnemyAction();
	}
}