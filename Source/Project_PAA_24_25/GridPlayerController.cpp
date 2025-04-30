#include "GridPlayerController.h"
#include "UnitBase.h"
#include "Brawler.h"
#include "Sniper.h"
#include "CellActor.h"
#include "GridLine.h"
#include "UnitInfoWidget.h"
#include "TurnIndicatorWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "TurnBasedGameMode.h"
#include "StrategyCamera.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

AGridPlayerController::AGridPlayerController()
{
	bShowMouseCursor = true;
	
	// Set widget class for UnitInfoWidget
	static ConstructorHelpers::FClassFinder<UUnitInfoWidget> WidgetClass(TEXT("/Game/BlueprintClasses/UnitInfoWidget_BPP.UnitInfoWidget_BPP_C"));
	if (WidgetClass.Class)
	{
		UnitInfoWidgetClass = WidgetClass.Class;
	}
}

void AGridPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Insert GridCells into Array
	InitializeGridCells();

	if (GetWorld())
	{
		for (TActorIterator<AStrategyCamera> It(GetWorld()); It; ++It)
		{
			StrategyCamera = *It;
			break;
		}

		if (StrategyCamera)
		{
			// Calculate the camera position based on the grid size
			const float GridSize = 100.0f; // Cell dimension
			const float HalfGridSize = (25 * GridSize) / 2;

			// Position the camera above the grid
			FVector CameraLocation = FVector(HalfGridSize, HalfGridSize, 2500.0f);	// Regulable height
			FRotator CameraRotation = FRotator(-90.0f, 0.0f, 0.0f);					// Angolazione regolabile

			StrategyCamera->SetActorLocation(CameraLocation);
			StrategyCamera->SetActorRotation(CameraRotation);

			SetViewTargetWithBlend(StrategyCamera, 0.5f);
		}
	}
}

void AGridPlayerController::InitializeGridCells()
{
	for (TActorIterator<AGridLine> GridIterator(GetWorld()); GridIterator; ++GridIterator)
	{
		AGridLine* Grid = *GridIterator;
		if (Grid)
		{
			GridCells = Grid->GetGridCells();
			return;
		}
	}
}

void AGridPlayerController::UpdateAllUnitWidgets()
{
	// If widget not found create a new one
	if (!IsValid(UnitInfoWidget))
	{
		UnitInfoWidget = CreateWidget<UUnitInfoWidget>(GetWorld(), UnitInfoWidgetClass);
		if (UnitInfoWidget)
		{
			UnitInfoWidget->AddToViewport(0);
			UnitInfoWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			return;
		}
	}

	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
	{
		return;
	}

	// Update Player Units
	for (AUnitBase* Unit : GameMode->PlayerUnits)
	{
		if (Unit && UnitInfoWidget)
		{
			// Check if UnitRole is empty and in case continue and update it from the eliminated units
			if (Unit->UnitRole.IsEmpty())
			{
				continue;
			}
			UnitInfoWidget->UpdateUnitInfo(Unit->UnitRole, Unit->Health);
		}
	}

	// Update Enemy Units
	for (AUnitBase* Unit : GameMode->EnemyUnits)
	{
		if (Unit && UnitInfoWidget)
		{
			// Check if UnitRole is empty and in case continue and update it from the eliminated units
			if (Unit->UnitRole.IsEmpty())
			{
				continue;
			}
			UnitInfoWidget->UpdateUnitInfo(Unit->UnitRole, Unit->Health);
		}
	}

	// Update Eliminated Player Units
	for (AUnitBase* Unit : GameMode->EliminatedPlayerUnits)
	{
		if (Unit && UnitInfoWidget)
		{
			if (Unit->UnitRole.IsEmpty())
			{
				continue;
			}
			UnitInfoWidget->UpdateUnitInfo(Unit->UnitRole, 0);
		}
	}

	// Update Eliminated Enemy Units
	for (AUnitBase* Unit : GameMode->EliminatedEnemyUnits)
	{
		if (Unit && UnitInfoWidget)
		{
			if (Unit->UnitRole.IsEmpty())
			{
				continue;
			}
			UnitInfoWidget->UpdateUnitInfo(Unit->UnitRole, 0);
		}
	}
}

void AGridPlayerController::HandlePlaceUnit()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			AUnitBase* ClickedUnit = Cast<AUnitBase>(HitResult.GetActor()); 
			
			// Check if the clicked unit is a player unit
			if (IsValid(ClickedUnit) && GameMode->PlayerUnits.Contains(ClickedUnit))
			{
				// Pass the selected unit to the GameMode
				GameMode->SelectPrePositionedUnit(ClickedUnit); 

				FVector UnitLocation = ClickedUnit->GetActorLocation();
				ACellActor* UnderlyingCell = FindCellUnderUnit(UnitLocation);

				if (UnderlyingCell)
				{
					// Remove highlight from the previously highlighted cell
					if (CurrentlyHighlightedCell)
					{
						CurrentlyHighlightedCell->ResetToOriginalColor();
					}

					// Highlight the new cell
					UnderlyingCell->HighlightCell(true);
					HighlightedCells.Add(UnderlyingCell);
					CurrentlyHighlightedCell = UnderlyingCell;
				}
				return;
			}

			ACellActor* ClickedCell = Cast<ACellActor>(HitResult.GetActor());
			if (IsValid(ClickedCell))
			{
				FVector ChosenLocation = ClickedCell->GetActorLocation();
				// Pass the clicked cell to the GameMode
				GameMode->HandlePlayerUnitPlacement(ChosenLocation);
			}
		}
	}
}

ACellActor* AGridPlayerController::FindCellUnderUnit(FVector UnitLocation)
{
	// Gridsnap positions
	int32 GridX = FMath::FloorToInt(UnitLocation.X / 100);
	int32 GridY = FMath::FloorToInt(UnitLocation.Y / 100);

	// Construct the cell location
	FVector CellLocation = FVector(GridX * 100.0f, GridY * 100.0f, 0.0f);

	// Find the cell in the grid
	for (ACellActor* Cell : GridCells)
	{
		if (Cell->GetActorLocation().Equals(CellLocation, 1.0f)) // Tollerence
		{
			return Cell;
		}
	}
	return nullptr;
}

void AGridPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SelectUnit", IE_Pressed, this, &AGridPlayerController::HandleSelectUnit);	// left click to select player unit
	InputComponent->BindAction("PlaceUnit", IE_Pressed, this, &AGridPlayerController::HandlePlaceUnit);		// left click to place player unit
	InputComponent->BindAction("MoveUnit", IE_Pressed, this, &AGridPlayerController::HandleMoveUnit);		// right click to move player unit
	InputComponent->BindAction("AttackUnit", IE_Pressed, this, &AGridPlayerController::HandleAttackUnit);	// right click to attack enemy unit
	InputComponent->BindAction("EndTurn", IE_Pressed, this, &AGridPlayerController::HandleEndTurn);			// "End-Turn" button
}

void AGridPlayerController::HandleSelectUnit()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		// Assure that selected actor is valid
		if (IsValid(HitResult.GetActor()))
		{
			ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
			AUnitBase* HitUnit = Cast<AUnitBase>(HitResult.GetActor());
			if (IsValid(HitUnit) && HitUnit->bIsPlayerControlled && (HitUnit->bCanMove || HitUnit->bCanAttackAfterMove) && (GameMode->CurrentTurn == ETurnState::PlayerTurn))
			{
				if (SelectedUnit && SelectedUnit != HitUnit && SelectedUnit->bHasCompletedAction)
				{
					// Check if the selected unit has already completed an action
					if (SelectedUnit->bCanMove)
					{
						return;
					}
					// If SelectedUnit != SelectedUnit then it means that the player wants to change unit and if it happens the actions for the first unit are completed
					SelectedUnit->bCanAttackAfterMove = false;
					SelectedUnit->bCanAttack = false;
				}
				SelectedUnit = HitUnit;
				ClearMovementRange(true);	// Clear movement range of previous unit
				ShowMovementRange();		// Show movement range of new unit
			}
		}
	}
}

void AGridPlayerController::ShowMovementRange()
{
	// If the selected unit is not valid, return
	if (!IsValid(SelectedUnit))
	{
		return;
	}

	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
	{
		return;
	}

	FVector StartLocation = SelectedUnit->GetActorLocation();
	int32 MaxRange = SelectedUnit->MaxMovement;

	MovementPaths.Empty();

	for (int32 x = -MaxRange; x <= MaxRange; x++)		// Limit the range X to the maximum range for that unit
	{
		for (int32 y = -MaxRange; y <= MaxRange; y++)	// Limit the range Y to the maximum range for that unit
		{
			FVector TargetLocation = StartLocation + FVector(x * 100.0f, y * 100.0f, 0.0f);

			// Skip starting cell
			if (TargetLocation == StartLocation) continue;

			// Calculate Manhattan distance
			int32 Distance = FMath::Abs(x) + FMath::Abs(y);

			// Skip if the distance is greater than the maximum range
			if (Distance > MaxRange) continue;

			// Find path
			TArray<FVector> Path = GameMode->FindPath(SelectedUnit, StartLocation, TargetLocation, true);

			if (Path.Num() > 0 && Path.Num() <= MaxRange)
			{
				MovementPaths.Add(TargetLocation, Path);

				FHitResult HitResult;
				GetWorld()->LineTraceSingleByChannel(
					HitResult,
					TargetLocation + FVector(0, 0, 100), // Point above the cell
					TargetLocation - FVector(0, 0, 100), // Point below the cell
					ECC_WorldStatic
				);

				if (HitResult.bBlockingHit)
				{
					ACellActor* Cell = Cast<ACellActor>(HitResult.GetActor());
					if (IsValid(Cell))
					{
						Cell->HighlightCell(true);	// Highlight cell
						HighlightedCells.Add(Cell); // Add cell on highlighted cells array
					}
				}
			}
		}
	}
}

void AGridPlayerController::ClearMovementRange(bool bMovementOrAttack)
{
	if (bMovementOrAttack)
	{
		// Clear movement range
		for (ACellActor* Cell : HighlightedCells)
		{
			if (IsValid(Cell))
			{
				Cell->ResetToOriginalColor();
			}
		}
		HighlightedCells.Empty();
	}
	else
	{
		// Clear attack range
		for (ACellActor* Cell : AttackCells)
		{
			if (IsValid(Cell))
			{
				Cell->ResetToOriginalColor();
			}
		}
		AttackCells.Empty();
	}
}

void AGridPlayerController::HandleMoveUnit()
{
	// Check if the selected unit is valid and can move
	if (!IsValid(SelectedUnit))
	{
		return;
	}

	if (!SelectedUnit->bCanMove)
	{
		return;
	}

	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		FVector TargetLocation = HitResult.Location;
		TargetLocation.Z = SelectedUnit->GetActorLocation().Z;
		TargetLocation.X = FMath::GridSnap(TargetLocation.X, 100.0f);
		TargetLocation.Y = FMath::GridSnap(TargetLocation.Y, 100.0f);

		// Use memorized path from ShowMovementRange
		if (MovementPaths.Contains(TargetLocation)) 
		{
			PlayerPath = MovementPaths[TargetLocation];
			if (PlayerPath.Num() <= SelectedUnit->MaxMovement)
			{
				// Step to step movement for player
				PMovingUnit = SelectedUnit;
				PCurrentStepIndex = 0;
				GetWorld()->GetTimerManager().SetTimer(PStepMoveTimer, this, &AGridPlayerController::MovePlayerStepByStep, 0.2f, true);

				// Update Widget and History after move
				UpdateAllUnitWidgets();
				StoreMove(TargetLocation);

				SelectedUnit->bCanMove = false;				// Deny further movement
				SelectedUnit->bCanAttackAfterMove = true;	// Allow attack after move
				SelectedUnit->bHasCompletedAction = true;	// Set action completed

				ClearMovementRange(true);					// Clear movement range after moving
			}
		}
	}
}

void AGridPlayerController::MovePlayerStepByStep()
{
	if (!IsValid(PMovingUnit) || PlayerPath.Num() == 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(PStepMoveTimer);
		return;
	}

	if (PCurrentStepIndex < PlayerPath.Num())
	{
		// Move the unit to the next position and highlight the cells
		FVector NextPosition = PlayerPath[PCurrentStepIndex];
		PMovingUnit->SetActorLocation(NextPosition);
		FindCellUnderUnit(NextPosition)->HighlightCell(true);
		HighlightedCells.Add(FindCellUnderUnit(NextPosition));
		PCurrentStepIndex++;
	}
	else
	{
		// End movement
		GetWorld()->GetTimerManager().ClearTimer(PStepMoveTimer);
	}
}

void AGridPlayerController::HandleAttackUnit()
{
	// Check if the selected unit is valid and can attack
	if (!IsValid(SelectedUnit))
	{
		return;
	}

	if ((!SelectedUnit->bCanAttack && !SelectedUnit->bCanAttackAfterMove))
	{
		return;
	}
	
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode && GameMode->CurrentTurn != ETurnState::PlayerTurn)
	{
		return;
	}

	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (!HitResult.GetActor())
	{
		return;
	}

	if (IsValid(HitResult.GetActor()) && HitResult.GetActor()->IsA(AUnitBase::StaticClass()))
	{
		AUnitBase* TargetUnit = Cast<AUnitBase>(HitResult.GetActor());

		if (TargetUnit && TargetUnit != SelectedUnit && !TargetUnit->bIsPlayerControlled)
		{
			int32 Distance = FMath::Abs(TargetUnit->GetActorLocation().X - SelectedUnit->GetActorLocation().X) / 100 + FMath::Abs(TargetUnit->GetActorLocation().Y - SelectedUnit->GetActorLocation().Y) / 100;

			// Check if the target is within attack range
			if (Distance <= SelectedUnit->AttackRange)
			{
				int32 CurrentDamage = FMath::RandRange(SelectedUnit->DamageMin, SelectedUnit->DamageMax);
				TargetUnit->ApplyDamage(CurrentDamage);

				// Highlight the cell where the attack occurred
				FindCellUnderUnit(TargetUnit->GetActorLocation())->HighlightCell(false);
				AttackCells.Add(FindCellUnderUnit(TargetUnit->GetActorLocation()));

				// Update the unit's state after the attack
				SelectedUnit->bCanMove = false;
				SelectedUnit->bCanAttack = false;
				SelectedUnit->bCanAttackAfterMove = false;
				SelectedUnit->bHasCompletedAction = true; // Set action completed

				// Update widget and history after attack
				UpdateAllUnitWidgets();
				StoreAttack(SelectedUnit, TargetUnit, CurrentDamage);

				// Counter-attack
				if (SelectedUnit->UnitType == EUnitType::Sniper)
				{
					TargetUnit->CounterAttack(SelectedUnit);
				}

				// Check if the game should end
				GameMode->CheckEndGameCondition();

				// Switch to next unit
				HandleNextUnit();
			}
		}
	}
}

void AGridPlayerController::HandleNextUnit()
{
	// Clear movement range of previous unit
	ClearMovementRange(true); 

	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
		return;

	for (AUnitBase* Unit : GameMode->PlayerUnits)
	{
		// Find available unit
		if (!Unit->bHasCompletedAction) 
		{
			SelectedUnit = Unit;
			ShowMovementRange();
			return;
		}
	}
}

void AGridPlayerController::HandleEndTurn()
{
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->EndTurn(); // Change turn
	}
}

void AGridPlayerController::StoreMove(FVector TargetLocation)
{
	FVector OriginPosition = SelectedUnit->GetActorLocation();
	FVector TargetPosition = TargetLocation;

	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
	{
		return;
	}

	FString PlayerID = SelectedUnit->bIsPlayerControlled ? TEXT("HP") : TEXT("AI");
	FString OriginCell = GameMode->ConvertPositionToNotation(OriginPosition);
	FString DestinationCell = GameMode->ConvertPositionToNotation(TargetPosition);

	// Log the move
	GameMode->LogMove(PlayerID, SelectedUnit->GetUnitType(), OriginCell, DestinationCell);
}

void AGridPlayerController::StoreAttack(AUnitBase* AttackingUnit, AUnitBase* TargetUnit, int32 CurrentDamage)
{
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
	{
		return;
	}

	FString PlayerID = AttackingUnit->bIsPlayerControlled ? TEXT("HP") : TEXT("AI");
	FVector TargetPosition = TargetUnit->GetActorLocation();
	FString TargetCell = GameMode->ConvertPositionToNotation(TargetPosition);

	// Log the attack
	GameMode->LogAttack(PlayerID, SelectedUnit->GetUnitType(), TargetCell, CurrentDamage);
}

void AGridPlayerController::DisablePlayerInput()
{
	if (InputComponent)
	{
		InputComponent->ClearActionBindings();	// Remove all action bindings
		SetIgnoreMoveInput(true);				// Ignore input for movement
		SetIgnoreLookInput(true);				// Ignore input for looking
	}
}