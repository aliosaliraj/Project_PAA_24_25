// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedGameMode.h"
#include "GridPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UnitBase.h"
#include "Sniper.h"
#include "Brawler.h"
#include "Obstacle.h"
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



ATurnBasedGameMode::ATurnBasedGameMode()
{
	PlayerControllerClass = AGridPlayerController::StaticClass();
	CurrentTurn = ETurnState::PlayerTurn;
	GridSize = 25;
}

void ATurnBasedGameMode::BeginPlay()
{
	Super::BeginPlay();

	SpawnUnits();
}

void ATurnBasedGameMode::CoinFlip()
{
	bIsPlayerStarting = FMath::RandBool(); // Randomizza chi inizia
	CurrentTurn = bIsPlayerStarting ? ETurnState::PlayerTurn : ETurnState::EnemyTurn;

	UE_LOG(LogTemp, Warning, TEXT("Coin Flip Result: %s starts first"), bIsPlayerStarting ? TEXT("Player") : TEXT("Enemy"));
}

void ATurnBasedGameMode::SpawnUnits()
{
	CoinFlip();
	CurrentUnitPlacementIndex = 0;

	if (GetWorld())
	{
		// Spawn player unit
		if (PlayerUnitClass)
		{
			AUnitBase* Sniper = GetWorld()->SpawnActor<AUnitBase>(PlayerUnitClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (Sniper)
			{
				Sniper->bIsPlayerControlled = true;
				Sniper->UnitType = EUnitType::Sniper;	//Unit Type:
				Sniper->UpdateMaterial();
				PlayerUnits.Add(Sniper);
			}			
			
			AUnitBase* Brawler = GetWorld()->SpawnActor<AUnitBase>(PlayerUnitClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (Brawler)
			{
				Brawler->bIsPlayerControlled = true;
				Brawler->UnitType = EUnitType::Brawler;	//Unit Type:
				Brawler->UpdateMaterial();
				PlayerUnits.Add(Brawler);
			}
		}

		// Spawn enemy unit
		if (EnemyUnitClass)
		{
			AUnitBase* Sniper = GetWorld()->SpawnActor<AUnitBase>(EnemyUnitClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (Sniper)
			{
				Sniper->bIsPlayerControlled = false;
				Sniper->UnitType = EUnitType::Sniper;	//Unit Type:
				Sniper->UpdateMaterial();
				EnemyUnits.Add(Sniper);
			}

			AUnitBase* Brawler = GetWorld()->SpawnActor<AUnitBase>(EnemyUnitClass, FVector(0, 0, 0), FRotator::ZeroRotator);
			if (Brawler)
			{
				Brawler->bIsPlayerControlled = false;
				Brawler->UnitType = EUnitType::Brawler;	//Unit Type:
				Brawler->UpdateMaterial();
				EnemyUnits.Add(Brawler);
			}
		}

		PositionUnitsAlternately();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No world found"));
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
		bIsValidLocation = IsLocationFreeFromObstacles(PlacementLocation);
	}

	return PlacementLocation;
}

bool ATurnBasedGameMode::IsLocationFreeFromObstacles(FVector Location)
{
    TArray<AActor*> OverlappingActors;
    // Usa SphereOverlapActors per controllare ostacoli nella posizione
    UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Location, 50.0f, TArray<TEnumAsByte<EObjectTypeQuery>>(), AObstacle::StaticClass(), TArray<AActor*>(), OverlappingActors);

    // Se ci sono ostacoli nella posizione, la posizione non è valida
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
	bool bIsPlayerTurn = (bIsPlayerStarting && (CurrentPlayerUnitIndex + CurrentEnemyUnitIndex) % 2 == 0) ||
		(!bIsPlayerStarting && (CurrentPlayerUnitIndex + CurrentEnemyUnitIndex) % 2 != 0);

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
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATurnBasedGameMode::PositionUnitsAlternately, 1.0f, false);
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
}

void ATurnBasedGameMode::StartEnemyTurn()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy Turn Started"));
	CurrentTurn = ETurnState::EnemyTurn;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AUnitBase::StaticClass(), FoundActors);

	AUnitBase* ClosestEnemyUnit = nullptr;
	AUnitBase* PlayerUnit = nullptr;
	float ClosestDistance = FLT_MAX;

	// Trova l'unità del giocatore
	for (AActor* Actor : FoundActors)
	{
		if (IsValid(Actor))
		{
			if (AUnitBase* Unit = Cast<AUnitBase>(Actor))
			{
				if (Unit->bIsPlayerControlled)
				{
					PlayerUnit = Unit; // Assegna l'unità del giocatore
					break; // Esci dal ciclo quando trovi l'unità del giocatore
				}
			}
		}
	}

	if (!PlayerUnit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player unit not found!"));
		EndTurn();
		return;
	}

	for (AActor* Actor : FoundActors)
	{
		if (IsValid(Actor))
		{
			AUnitBase* EnemyUnit = Cast<AUnitBase>(Actor);

			if (EnemyUnit)
			{
				if (!EnemyUnit->bIsPlayerControlled)
				{
					float Distance = FVector::Dist(EnemyUnit->GetActorLocation(), PlayerUnit->GetActorLocation());

					//UE_LOG(LogTemp, Warning, TEXT("Checking AI unit at location %s - Distance: %f"), *EnemyUnit->GetActorLocation().ToString(), Distance);

					if (Distance < ClosestDistance)
					{
						ClosestEnemyUnit = EnemyUnit;
						ClosestDistance = Distance;
					}
				}
				else
				{
					//UE_LOG(LogTemp, Warning, TEXT("Skipping player unit at location %s"), *EnemyUnit->GetActorLocation().ToString());
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Invalid AI unit or actor"));
		}
	}

	if (ClosestEnemyUnit)
	{
		FVector StartLocation = ClosestEnemyUnit->GetActorLocation();
		FVector TargetLocation = PlayerUnit->GetActorLocation();
		bool bIsPlayerControlled = false;

		// Allineiamo alla griglia
		StartLocation.X = FMath::GridSnap(StartLocation.X, 100.0f);
		StartLocation.Y = FMath::GridSnap(StartLocation.Y, 100.0f);
		TargetLocation.X = FMath::GridSnap(TargetLocation.X, 100.0f);
		TargetLocation.Y = FMath::GridSnap(TargetLocation.Y, 100.0f);

		//UE_LOG(LogTemp, Warning, TEXT("AI StartLocation: X=%f Y=%f"), StartLocation.X, StartLocation.Y);
		//UE_LOG(LogTemp, Warning, TEXT("AI TargetLocation: X=%f Y=%f"), TargetLocation.X, TargetLocation.Y);

		Path = FindPath(ClosestEnemyUnit, StartLocation, TargetLocation, bIsPlayerControlled);
		MovingUnit = ClosestEnemyUnit;

		if (Path.Num() > 0)
		{
			// Inizia il movimento passo dopo passo
			CurrentStepIndex = 0;
			GetWorld()->GetTimerManager().SetTimer(StepMoveTimer, this, &ATurnBasedGameMode::MoveStepByStep, 0.2f, true);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No valid path found for AI"));
			EndTurn();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No enemy unit found"));
		EndTurn();
	}
}

void ATurnBasedGameMode::EndTurn()
{
	if (CurrentTurn == ETurnState::PlayerTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ending player turn"));
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATurnBasedGameMode::StartEnemyTurn, 1.0f, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ending enemy turn"));
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATurnBasedGameMode::StartPlayerTurn, 1.0f, false);
	}
}

bool ATurnBasedGameMode::IsValidMove(FVector Position, FVector TargetLocation, AUnitBase* Unit)
{
	FVector GridPosition = FVector(FMath::RoundToInt(Position.X / 100) * 100, FMath::RoundToInt(Position.Y / 100) * 100, Position.Z);
	FVector TargetGridPosition = FVector(FMath::RoundToInt(TargetLocation.X / 100) * 100, FMath::RoundToInt(TargetLocation.Y / 100) * 100, TargetLocation.Z);
	const float PositionTolerance = 5.0f;

	// Controlla ostacoli sulla mappa
	TArray<AActor*> OverlappingActors;
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GridPosition, 10.0f, TArray<TEnumAsByte<EObjectTypeQuery>>(), AObstacle::StaticClass(), TArray<AActor*>(), OverlappingActors);

	if (OverlappingActors.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Obstacle detected at X=%f Y=%f"), GridPosition.X, GridPosition.Y);
		return false;
	}


	//Controlla unità bloccanti
	TArray<AActor*> OverlappingUnits;
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GridPosition, 10.0f, TArray<TEnumAsByte<EObjectTypeQuery>>(), AUnitBase::StaticClass(), TArray<AActor*>(), OverlappingUnits);

	for (AActor* Actor : OverlappingUnits)
	{
		AUnitBase* BlockingUnit = Cast<AUnitBase>(Actor);

		if (BlockingUnit)
		{
			// Se l'unità sulla cella è un'unità nemica, blocca il movimento
			if (BlockingUnit->bIsPlayerControlled != Unit->bIsPlayerControlled)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cell blocked by enemy unit!"));
				return false;
			}

			// Se c'è una unità sulla cella nemica e non è il target, blocca il movimento
			if (FVector::Dist(GridPosition, TargetGridPosition) < 0.1f)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cell blocked by unit!"));
				return false;
			}
		}
	}

	// Verifica che l'unità nemica non sia nel range di movimento
	float MaxDistance = Unit->MaxMovement * 100;
	if (FVector::Dist(Position, Unit->GetActorLocation()) > MaxDistance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Out of movement range: Max = %f, Actual = %f"), MaxDistance, FVector::Dist(Position, Unit->GetActorLocation()));
		return false;
	}
	return true;
}

TArray<FVector> ATurnBasedGameMode::FindPath(AUnitBase* Unit, FVector StartLocation, FVector TargetLocation, bool bIsPlayerControlled)
{
	Path.Empty();

	TMap<FVector, FPathNode*> OpenList;
	TSet<FVector> ClosedList;

	FPathNode* StartNode = new FPathNode(StartLocation);
	StartNode->HCost = FMath::Abs(TargetLocation.X - StartLocation.X) + FMath::Abs(TargetLocation.Y - StartLocation.Y);		//valore assoluto tra inizio e target
	StartNode->GCost = 0;
	StartNode->FCost = StartNode->GCost + StartNode->HCost;

	OpenList.Add(StartLocation, StartNode);
	UE_LOG(LogTemp, Warning, TEXT("Starting pathfinding from: X=%f Y=%f"), StartLocation.X, StartLocation.Y);

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

		//UE_LOG(LogTemp, Warning, TEXT("Current node: X=%.2f Y=%.2f FCost=%.2f"), CurrentNode->Position.X, CurrentNode->Position.Y, CurrentNode->FCost);

		// Se abbiamo raggiunto la destinazione → ricostruiamo il percorso
		if (bIsPlayerControlled)
		{
			if (FVector::Dist(CurrentNode->Position, TargetLocation) <= KINDA_SMALL_NUMBER)
			{
				while (CurrentNode)
				{
					Path.Insert(CurrentNode->Position, 0);
					CurrentNode = CurrentNode->Parent;
				}
				/*UE_LOG(LogTemp, Warning, TEXT("Path found:"));

				for (FVector Step : Path)
				{
					UE_LOG(LogTemp, Warning, TEXT(" -> X=%f Y=%f"), Step.X, Step.Y);
				}

				Cleanup*/
				for (auto& Elem : OpenList)
					delete Elem.Value;

				return Path;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Error in calculating player distance"));
			}
		}
		else
		{
			if (FVector::Dist(CurrentNode->Position, TargetLocation) <= 100.0f)
			{
				UE_LOG(LogTemp, Warning, TEXT("Stopping before reaching target at X=%.2f Y=%.2f"), CurrentNode->Position.X, CurrentNode->Position.Y);

				while (CurrentNode)
				{
					Path.Insert(CurrentNode->Position, 0);
					CurrentNode = CurrentNode->Parent;
				}

				//UE_LOG(LogTemp, Warning, TEXT("Path found:"));
				/*
				for (FVector Step : Path)
				{
					UE_LOG(LogTemp, Warning, TEXT(" -> X=%f Y=%f"), Step.X, Step.Y);
				}
				*/
				// Cleanup
				for (auto& Elem : OpenList)
					delete Elem.Value;

				return Path;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Error in calculating AI distance"));
			}
		}
		// Posible moves
		TArray<FVector> Neighbors = { CurrentNode->Position + FVector(100, 0, 0), CurrentNode->Position + FVector(-100, 0, 0), CurrentNode->Position + FVector(0, 100, 0), CurrentNode->Position + FVector(0, -100, 0) };

		for (FVector NeighborPosition : Neighbors)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Checking neighbor at: X=%f Y=%f"), NeighborPosition.X, NeighborPosition.Y);

			if (!IsValidMove(NeighborPosition, TargetLocation, Unit))
				continue;

			if (ClosedList.Contains(NeighborPosition))
				continue;

			int32 NewGCost = CurrentNode->GCost + 1;
			/*
			if (NewGCost > Unit->MaxMovement)
			{
				continue; // Continue if GCost exceeds MaxMovement
			}*/

			if (!OpenList.Contains(NeighborPosition))
			{
				FPathNode* NeighborNode = new FPathNode(NeighborPosition);
				NeighborNode->Parent = CurrentNode;
				NeighborNode->GCost = NewGCost;
				NeighborNode->HCost = (FMath::Abs(TargetLocation.X - NeighborPosition.X) + FMath::Abs(TargetLocation.Y - NeighborPosition.Y)) / 100;
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

void ATurnBasedGameMode::MoveStepByStep()
{
	if (CurrentStepIndex < Path.Num() && MovingUnit)
	{
		FVector NextPosition = Path[CurrentStepIndex];

		if (IsValidMove(NextPosition, Path.Last(), MovingUnit))
		{
			// Muove l'unità alla prossima posizione
			MovingUnit->SetActorLocation(NextPosition);
			//UE_LOG(LogTemp, Warning, TEXT("AI moved to: %s"), *NextPosition.ToString());

			CurrentStepIndex++;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Invalid move, stopping movement"));
			GetWorld()->GetTimerManager().ClearTimer(StepMoveTimer);
			EndTurn();
		}
	}
	else
	{
		// Fine del percorso
		UE_LOG(LogTemp, Warning, TEXT("Movement finished"));
		GetWorld()->GetTimerManager().ClearTimer(StepMoveTimer);
		EndTurn();
	}
}