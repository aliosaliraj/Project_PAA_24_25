// Fill out your copyright notice in the Description page of Project Settings.


#include "GridPlayerController.h"
#include "UnitBase.h"
#include "Brawler.h"
#include "Sniper.h"
#include "CellActor.h"
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
		UE_LOG(LogTemp, Warning, TEXT("UnitInfoWidgetClass initialized from C++"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find UnitInfoWidget_BPP in constructor!"));
	}
}

void AGridPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		for (TActorIterator<AStrategyCamera> It(GetWorld()); It; ++It)
		{
			StrategyCamera = *It;
			break;
		}

		if (StrategyCamera)
		{
			// Calcolo del centro della griglia (esempio con una griglia 25x25)
			const float GridSize = 100.0f; // Dimensione di una cella (modifica se necessario)
			const float HalfGridSize = (25 * GridSize) / 2;

			// Posiziona la camera sopra il centro della griglia
			FVector CameraLocation = FVector(HalfGridSize, HalfGridSize, 2500.0f); // Altezza regolabile
			FRotator CameraRotation = FRotator(-90.0f, 0.0f, 0.0f); // Angolazione regolabile

			StrategyCamera->SetActorLocation(CameraLocation);
			StrategyCamera->SetActorRotation(CameraRotation);

			SetViewTargetWithBlend(StrategyCamera, 0.5f);
		}
	}
}

void AGridPlayerController::UpdateAllUnitWidgets()
{
	// If widget not found create a new one
	if (!IsValid(UnitInfoWidget))
	{
		UE_LOG(LogTemp, Error, TEXT("UnitInfoWidget is not valid during UpdateAllUnitWidgets - Recreating"));
		UnitInfoWidget = CreateWidget<UUnitInfoWidget>(GetWorld(), UnitInfoWidgetClass);
		if (UnitInfoWidget)
		{
			UnitInfoWidget->AddToViewport(0);
			UnitInfoWidget->SetVisibility(ESlateVisibility::Visible);
			UE_LOG(LogTemp, Warning, TEXT("UnitInfoWidget recreated in update"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to recreate UnitInfoWidget"));
			return;
		}
	}

	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("TurnBasedGameMode not found"));
		return;
	}

	for (int32 Index = 0; Index < GameMode->PlayerUnits.Num(); Index++)
	{
		AUnitBase* Unit = GameMode->PlayerUnits[Index];
		if (Unit && UnitInfoWidget)
		{
			UnitInfoWidget->UpdateUnitInfo(Unit->CurrentDamage, Unit->Health, Index);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Player unit [%d] not found or invalid to update widget"), Index);
		}
	}

	for (int32 Index = 0; Index < GameMode->EnemyUnits.Num(); Index++)
	{
		AUnitBase* Unit = GameMode->EnemyUnits[Index];
		if (Unit && UnitInfoWidget)
		{
			UnitInfoWidget->UpdateUnitInfo(Unit->CurrentDamage, Unit->Health, Index + 2);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Enemy unit [%d] not found or invalid to update widget"), Index);
		}
	}
}

void AGridPlayerController::HandlePlaceUnit()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		ACellActor* ClickedCell = Cast<ACellActor>(HitResult.GetActor());
		if (IsValid(ClickedCell))
		{
			FVector ChosenLocation = ClickedCell->GetActorLocation();

			// Call HandlePlayerUnitPlacement to set up player units
			ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
			if (GameMode)
			{
				GameMode->HandlePlayerUnitPlacement(ChosenLocation);
			}
		}
	}
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
			AUnitBase* HitUnit = Cast<AUnitBase>(HitResult.GetActor());
			if (IsValid(HitUnit) && HitUnit->bIsPlayerControlled && HitUnit->bCanAttack)
			{
				SelectedUnit = HitUnit;
				ClearMovementRange();
				ShowMovementRange();
				UE_LOG(LogTemp, Warning, TEXT("Unit selected: %s"), *HitUnit->GetName());

				if (SelectedUnit && SelectedUnit != HitUnit && !SelectedUnit->bHasCompletedAction)
				{
					UE_LOG(LogTemp, Warning, TEXT("Before condition for unit:%s, bCanMove=%d, bCanAttack=%d"), *SelectedUnit->GetName(), SelectedUnit->bCanMove, SelectedUnit->bCanAttack);
					UE_LOG(LogTemp, Warning, TEXT("bHasCompletedAction=%d"), SelectedUnit->bHasCompletedAction);
					if (SelectedUnit->bCanMove || SelectedUnit->bCanAttack) // Controlliamo se almeno una azione è stata eseguita
					{
						UE_LOG(LogTemp, Warning, TEXT("You must complete at least one action before selecting another unit."));
						return;
					}
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Unit not selectable or has already completed an action"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit actor is not valid"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No blocking hit"));
	}
}

void AGridPlayerController::ShowMovementRange()
{
	if (!IsValid(SelectedUnit))
	{
		UE_LOG(LogTemp, Warning, TEXT("No unit selected"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Calculating movement range for unit"));

	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("GameMode not found"));
		return;
	}

	FVector StartLocation = SelectedUnit->GetActorLocation();
	int32 MaxRange = SelectedUnit->MaxMovement;

	MovementPaths.Empty();

	for (int32 x = -MaxRange; x <= MaxRange; x++) // Limita l'intervallo X al range massimo
	{
		for (int32 y = -MaxRange; y <= MaxRange; y++) // Limita l'intervallo Y al range massimo
		{
			FVector TargetLocation = StartLocation + FVector(x * 100.0f, y * 100.0f, 0.0f);

			// Calcola la distanza Manhattan per verificare che sia entro il range
			int32 Distance = FMath::Abs(x) + FMath::Abs(y);
			if (Distance > MaxRange)
			{
				continue; // Salta celle fuori dal range massimo
			}

			// Calcola il percorso
			TArray<FVector> Path = GameMode->FindPath(SelectedUnit, StartLocation, TargetLocation, true);

			if (Path.Num() > 0 && Path.Num() <= MaxRange)
			{
				MovementPaths.Add(TargetLocation, Path);

				FHitResult HitResult;
				GetWorld()->LineTraceSingleByChannel(
					HitResult,
					TargetLocation + FVector(0, 0, 100), // Punto sopra la cella
					TargetLocation - FVector(0, 0, 100), // Punto sotto la cella
					ECC_WorldStatic
				);

				if (HitResult.bBlockingHit)
				{
					ACellActor* Cell = Cast<ACellActor>(HitResult.GetActor());
					if (IsValid(Cell))
					{
						Cell->HighlightCell(true); // Evidenzia la cella
						HighlightedCells.Add(Cell); // Add cell on highlighted cells array
					}
				}
			}
		}
	}
}

void AGridPlayerController::ClearMovementRange()
{
	for (ACellActor* Cell : HighlightedCells)
	{
		if (IsValid(Cell))
		{
			Cell->ResetToOriginalColor();
		}
	}
	HighlightedCells.Empty();
}

void AGridPlayerController::HandleMoveUnit()
{
	if (!IsValid(SelectedUnit))
	{
		UE_LOG(LogTemp, Warning, TEXT("No unit selected"));
		return;
	}

	if (!SelectedUnit->bCanMove)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unit cannot move"));
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

		if (MovementPaths.Contains(TargetLocation)) // Usa Path memorizzato
		{
			PlayerPath = MovementPaths[TargetLocation];
			if (PlayerPath.Num() <= SelectedUnit->MaxMovement)
			{
				// Avvia il movimento passo dopo passo
				PMovingUnit = SelectedUnit;
				PCurrentStepIndex = 0;
				GetWorld()->GetTimerManager().SetTimer(PStepMoveTimer, this, &AGridPlayerController::MovePlayerStepByStep, 0.2f, true);

				// Aggiorna il widget delle informazioni dell'unità
				UE_LOG(LogTemp, Warning, TEXT("Calling UpdateAllUnitWidgets after move"));
				UpdateAllUnitWidgets();

				//ClearMovementRange();
				SelectedUnit->bCanMove = false; // Deny further movement
				SelectedUnit->bCanAttackAfterMove = true; // Allow attack after move
				SelectedUnit->bHasCompletedAction = true; // Set action completed

				UE_LOG(LogTemp, Warning, TEXT("bCanMove: %d, bHasCompletedAction: %d"), SelectedUnit->bCanMove, SelectedUnit->bHasCompletedAction);

				ClearMovementRange(); // Clear movement range after moving

				UE_LOG(LogTemp, Warning, TEXT("Unit moved, attack enabled"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No valid path found for target location"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No valid target"));
	}
}

void AGridPlayerController::MovePlayerStepByStep()
{
	if (!IsValid(PMovingUnit) || PlayerPath.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid MovingUnit or empty PlayerPath"));
		GetWorld()->GetTimerManager().ClearTimer(PStepMoveTimer);
		return;
	}

	if (PCurrentStepIndex < PlayerPath.Num())
	{
		FVector NextPosition = PlayerPath[PCurrentStepIndex];
		PMovingUnit->SetActorLocation(NextPosition);
		PCurrentStepIndex++;

		UE_LOG(LogTemp, Warning, TEXT("Moving to position: X=%f, Y=%f"), NextPosition.X, NextPosition.Y);
	}
	else
	{
		// End movement
		GetWorld()->GetTimerManager().ClearTimer(PStepMoveTimer);
		UE_LOG(LogTemp, Warning, TEXT("Movement finished or invalid unit"));
	}
}

void AGridPlayerController::HandleAttackUnit()
{
	if (!IsValid(SelectedUnit))
	{
		UE_LOG(LogTemp, Warning, TEXT("No unit selected for attack"));
		return;
	}

	if ((!SelectedUnit->bCanAttack && !SelectedUnit->bCanAttackAfterMove))
	{
		UE_LOG(LogTemp, Warning, TEXT("Unit cannot attack"));
		return;
	}
	
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode && GameMode->CurrentTurn != ETurnState::PlayerTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not player turn"));
		return;
	}

	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (!HitResult.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid hit result, no actor found"));
		return;
	}

	if (IsValid(HitResult.GetActor()) && HitResult.GetActor()->IsA(AUnitBase::StaticClass()))
	{
		AUnitBase* TargetUnit = Cast<AUnitBase>(HitResult.GetActor());

		if (TargetUnit && TargetUnit != SelectedUnit && !TargetUnit->bIsPlayerControlled)
		{
			int32 Distance = FMath::Abs(TargetUnit->GetActorLocation().X - SelectedUnit->GetActorLocation().X) / 100 + FMath::Abs(TargetUnit->GetActorLocation().Y - SelectedUnit->GetActorLocation().Y) / 100;

			if (Distance <= SelectedUnit->AttackRange)
			{
				int32 CurrentDamage = FMath::RandRange(SelectedUnit->DamageMin, SelectedUnit->DamageMax);
				TargetUnit->ApplyDamage(CurrentDamage);

				SelectedUnit->bCanAttack = false;
				SelectedUnit->bCanAttackAfterMove = false;
				SelectedUnit->bHasCompletedAction = true; // Set action completed

				UE_LOG(LogTemp, Warning, TEXT("Unit attacked and actions completed"));

				// Update the widget after attack
				UE_LOG(LogTemp, Warning, TEXT("Updating unit widgets after attack"));
				UpdateAllUnitWidgets();

				if (SelectedUnit->UnitType == EUnitType::Sniper)
				{
					TargetUnit->CounterAttack(SelectedUnit);
					UpdateAllUnitWidgets();
				}
				ClearMovementRange();

				HandleNextUnit();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Attack denied: target out of range"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Cannot attack friendly unit"));
		}

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid hit result"));
	}
}

void AGridPlayerController::HandleNextUnit()
{
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
		return;

	for (AUnitBase* Unit : GameMode->PlayerUnits)
	{
		if (!Unit->bHasCompletedAction) // Find available unit
		{
			SelectedUnit = Unit;
			ShowMovementRange();
			UE_LOG(LogTemp, Warning, TEXT("Switching to next unit: %s"), *SelectedUnit->GetName());
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
