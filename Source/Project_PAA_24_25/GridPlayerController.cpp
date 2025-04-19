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

		if (!UnitInfoWidgetClass)
		{
			UE_LOG(LogTemp, Error, TEXT("UnitInfoWidgetClass is not set in Controller gameplay"));
			return;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("UnitInfoWidgetClass is set to: %s"), *UnitInfoWidgetClass->GetName());
		}

		UnitInfoWidget = CreateWidget<UUnitInfoWidget>(GetWorld(), UnitInfoWidgetClass);
		if (UnitInfoWidget)
		{
			UnitInfoWidget->AddToViewport();
			UnitInfoWidget->SetVisibility(ESlateVisibility::Visible);

			//RegisterUnitInfoWidget(UnitInfoWidget);

			UpdateAllUnitWidgets();
			UE_LOG(LogTemp, Warning, TEXT("UnitInfoWidget successfully created and added to viewport"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create UnitInfoWidget"));
		}

		if (!IsValid(UnitInfoWidget))
		{
			UE_LOG(LogTemp, Error, TEXT("UnitInfoWidget is not valid after BeginPlay initialization"));
		}
		
		if (TurnIndicatorWidgetClass)
		{
			UE_LOG(LogTemp, Warning, TEXT("TurnIndicatorWidgetClass is set to: %s"), *TurnIndicatorWidgetClass->GetName());

			TurnIndicatorWidget = CreateWidget<UTurnIndicatorWidget>(GetWorld(), TurnIndicatorWidgetClass);
			if (TurnIndicatorWidget)
			{
				TurnIndicatorWidget->AddToViewport();
				TurnIndicatorWidget->SetTurnText(TEXT("STARTING COIN FLIP"));
				/*
				// Register widget in GameMode
				ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
				if (GameMode)
				{
					GameMode->RegisterTurnIndicatorWidget(TurnIndicatorWidget);
				}*/
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("TurnIndicatorWidgetClass is not set"));
		}
	}
}

void AGridPlayerController::RegisterUnitInfoWidget(UUnitInfoWidget* Widget)
{
	UnitInfoWidget = Widget;
}

void AGridPlayerController::UpdateAllUnitWidgets()
{
	// I fwidget not found create a new one
	if (!IsValid(UnitInfoWidget))
	{
		UE_LOG(LogTemp, Error, TEXT("UnitInfoWidget is not valid during UpdateAllUnitWidgets - Recreating"));
		UnitInfoWidget = CreateWidget<UUnitInfoWidget>(GetWorld(), UnitInfoWidgetClass);
		if (UnitInfoWidget)
		{
			UnitInfoWidget->AddToViewport();
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
			UnitInfoWidget->UpdateUnitInfo(Unit->GetName(), Unit->CurrentDamage, Unit->Health, Index);
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
			UnitInfoWidget->UpdateUnitInfo(Unit->GetName(), Unit->CurrentDamage, Unit->Health, Index + 2);
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
			if (IsValid(HitUnit) && HitUnit->bIsPlayerControlled && !HitUnit->HasCompletedAction)
			{
				// Check if selected unit is already selected
				if (SelectedUnit == HitUnit)
				{
					// Alternate between showing and hiding movement range
					if (bIsMovementRangeVisible)
					{
						ClearMovementRange(); // Hide range
						bIsMovementRangeVisible = false;
						UE_LOG(LogTemp, Warning, TEXT("Movement range hidden for unit: %s"), *HitUnit->GetName());
					}
					else
					{
						ShowMovementRange(); // Show range
						bIsMovementRangeVisible = true;
						UE_LOG(LogTemp, Warning, TEXT("Movement range displayed for unit: %s"), *HitUnit->GetName());
					}
				}
				else
				{
					// Change selected unit
					SelectedUnit = HitUnit;
					ClearMovementRange(); // Hide previous range
					ShowMovementRange(); // Show new range
					bIsMovementRangeVisible = false;
					UE_LOG(LogTemp, Warning, TEXT("Unit changed: %s"), *HitUnit->GetName());
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
				//UpdateAllUnitWidgets();
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGridPlayerController::UpdateAllUnitWidgets, 0.9f, false);

				ClearMovementRange();
				SelectedUnit->HasCompletedAction = true;

				ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
				if (GameMode)
				{
					GameMode->NextPlayerUnit();
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Target location out of range"));
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

	ATurnBasedGameMode* CurrentGameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (CurrentGameMode && CurrentGameMode->CurrentTurn != ETurnState::PlayerTurn)
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

		if (IsValid(TargetUnit) && TargetUnit != SelectedUnit && !TargetUnit->bIsPlayerControlled)
		{
			int32 Distance = FMath::Abs(TargetUnit->GetActorLocation().X - SelectedUnit->GetActorLocation().X) / 100 + FMath::Abs(TargetUnit->GetActorLocation().Y - SelectedUnit->GetActorLocation().Y) / 100;

			if (Distance <= SelectedUnit->AttackRange)
			{
				int32 CurrentDamage = FMath::RandRange(SelectedUnit->DamageMin, SelectedUnit->DamageMax);
				TargetUnit->ApplyDamage(CurrentDamage);
				SelectedUnit->HasCompletedAction = true;

				// Update the widget after attack
				UE_LOG(LogTemp, Warning, TEXT("Updating unit widgets after attack"));
				//UpdateAllUnitWidgets();
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGridPlayerController::UpdateAllUnitWidgets, 0.9f, false);

				//UE_LOG(LogTemp, Warning, TEXT("Attacking %s for %d damage"), *TargetUnit->GetName(), CurrentDamage);

				if (SelectedUnit->UnitType == EUnitType::Sniper)
				{
					TargetUnit->CounterAttack(SelectedUnit);
				}
				ClearMovementRange();

				ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
				if (GameMode)
				{
					GameMode->NextPlayerUnit();
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Game mode not found"))
				}
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