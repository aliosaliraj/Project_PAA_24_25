// Fill out your copyright notice in the Description page of Project Settings.


#include "GridPlayerController.h"
#include "UnitBase.h"
#include "Brawler.h"
#include "Sniper.h"
#include "CellActor.h"
#include "UnitInfoWidget.h"
#include "TurnBasedGameMode.h"
#include "StrategyCamera.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

AGridPlayerController::AGridPlayerController()
{
	bShowMouseCursor = true;
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
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Camera non trovata"));
		}

		if (UnitInfoWidgetClass)
		{
			UnitInfoWidget = CreateWidget<UUnitInfoWidget>(GetWorld(), UnitInfoWidgetClass);
			if (UnitInfoWidget)
			{
				UnitInfoWidget->AddToViewport();
				UnitInfoWidget->SetVisibility(ESlateVisibility::Hidden);
			}
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

			// Chiama il metodo nel GameMode per gestire il posizionamento
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

	InputComponent->BindAction("SelectUnit", IE_Pressed, this, &AGridPlayerController::HandleSelectUnit);
	InputComponent->BindAction("MoveUnit", IE_Pressed, this, &AGridPlayerController::HandleMoveUnit);
	InputComponent->BindAction("AttackUnit", IE_Pressed, this, &AGridPlayerController::HandleAttackUnit);
	InputComponent->BindAction("PlaceUnit", IE_Pressed, this, &AGridPlayerController::HandlePlaceUnit);
}

void AGridPlayerController::HandleSelectUnit()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *HitResult.GetActor()->GetName());
		UE_LOG(LogTemp, Warning, TEXT("Collision channel: %d"), HitResult.Component->GetCollisionObjectType());

		// Assicurati che l'attore intercettato sia valido
		if (HitResult.GetActor())
		{
			AUnitBase* HitUnit = Cast<AUnitBase>(HitResult.GetActor());
			if (IsValid(HitUnit) && HitUnit->bIsPlayerControlled)
			{
				// Controlla se l'unità selezionata è la stessa su cui stiamo cliccando
				if (SelectedUnit == HitUnit)
				{
					// Alterna visibilità del range di movimento
					if (bIsMovementRangeVisible)
					{
						ClearMovementRange(); // Nasconde il range
						bIsMovementRangeVisible = false;
						UE_LOG(LogTemp, Warning, TEXT("Movement range hidden for unit: %s"), *HitUnit->GetName());
					}
					else
					{
						ShowMovementRange(); // Mostra il range
						bIsMovementRangeVisible = true;
						UE_LOG(LogTemp, Warning, TEXT("Movement range displayed for unit: %s"), *HitUnit->GetName());
					}
				}
				else
				{
					// Cambia unità selezionata
					SelectedUnit = HitUnit;
					ClearMovementRange(); // Nasconde il range della precedente unità
					ShowMovementRange(); // Mostra il range per la nuova unità
					bIsMovementRangeVisible = true;
					UE_LOG(LogTemp, Warning, TEXT("Unit changed: %s"), *HitUnit->GetName());
				}

				// Aggiorna il widget delle informazioni dell'unità
				if (SelectedUnit->UnitInfoWidget)
				{
					SelectedUnit->UnitInfoWidget->RemoveFromParent();
					SelectedUnit->UnitInfoWidget = nullptr;
				}

				if (SelectedUnit->UnitInfoWidgetClass)
				{
					UE_LOG(LogTemp, Warning, TEXT("Widget class is valid: %s"), *HitUnit->UnitInfoWidgetClass->GetName());
					SelectedUnit->UnitInfoWidget = CreateWidget<UUnitInfoWidget>(this, SelectedUnit->UnitInfoWidgetClass);
					if (SelectedUnit->UnitInfoWidget)
					{
						SelectedUnit->UnitInfoWidget->SetUnitInfo(SelectedUnit->GetName(), SelectedUnit->CurrentDamage, SelectedUnit->Health);
						SelectedUnit->UnitInfoWidget->AddToViewport();
					}
				}

				if (IsValid(SelectedUnit) && SelectedUnit->UnitInfoWidget)
				{
					SelectedUnit->UnitInfoWidget->SetVisibility(ESlateVisibility::Visible);
					ShowUnitInfo();
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No unit selected for widget"));
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Cannot select AI unit or invalid actor"));
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
	if (IsValid(SelectedUnit))
	{
		UE_LOG(LogTemp, Warning, TEXT("Showing movement range for: %s"), *SelectedUnit->GetName());

		ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
		if (!GameMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("GameMode not found"));
			return;
		}

		TArray<FVector> AccessibleCells;
		FVector StartLocation = SelectedUnit->GetActorLocation();

		for (int32 x = 0; x < 25; x++)
		{
			for (int32 y = 0; y < 25; y++)
			{
				FVector TargetLocation(x * 100.0f, y * 100.0f, StartLocation.Z); // Dimensione cella: 100

				// Usa FindPath per determinare se la cella è raggiungibile
				TArray<FVector> Path = GameMode->FindPath(SelectedUnit, StartLocation, TargetLocation, true);
				if (Path.Num() > 0 && Path.Num() <= SelectedUnit->MaxMovement)
				{
					AccessibleCells.Add(TargetLocation);
					UE_LOG(LogTemp, Warning, TEXT("Accessible cell: X=%f, Y=%f"), TargetLocation.X, TargetLocation.Y);
				}

			}
		}

		for (const FVector& Location : AccessibleCells)
		{
			FHitResult HitResult;
			GetWorld()->LineTraceSingleByChannel(HitResult, Location + FVector(0, 0, 100), Location - FVector(0, 0, 100), ECC_WorldStatic);

			if (HitResult.bBlockingHit)
			{
				ACellActor* Cell = Cast<ACellActor>(HitResult.GetActor());
				if (IsValid(Cell))
				{
					Cell->HighlightCell(true); // Funzione esistente per evidenziare la cella
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No unit selected"));
	}
}

void AGridPlayerController::ClearMovementRange()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACellActor::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		ACellActor* Cell = Cast<ACellActor>(Actor);
		if (IsValid(Cell))
		{
			Cell->ResetToOriginalColor();
		}
	}
}

void AGridPlayerController::HandleMoveUnit()
{
	if (IsValid(SelectedUnit))
	{
		if (!SelectedUnit->bIsPlayerControlled)
		{
			UE_LOG(LogTemp, Warning, TEXT("Cannot move AI unit"));
			return;
		}

		FHitResult HitResult;
		GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

		if (HitResult.bBlockingHit)
		{
			ACellActor* Cell = Cast<ACellActor>(HitResult.GetActor());
			if (IsValid(Cell))
			{
				FVector PStartLocation = SelectedUnit->GetActorLocation();
				FVector PTargetLocation = HitResult.Location;
				PTargetLocation.Z = SelectedUnit->GetActorLocation().Z;

				PTargetLocation.X = FMath::RoundToFloat(PTargetLocation.X / 100) * 100;
				PTargetLocation.Y = FMath::RoundToFloat(PTargetLocation.Y / 100) * 100;

				UE_LOG(LogTemp, Warning, TEXT("Moving into: X=%f Y=%f"), PTargetLocation.X, PTargetLocation.Y);

				// Allineiamo alla griglia
				PStartLocation.X = FMath::GridSnap(PStartLocation.X, 100.0f);
				PStartLocation.Y = FMath::GridSnap(PStartLocation.Y, 100.0f);
				PTargetLocation.X = FMath::GridSnap(PTargetLocation.X, 100.0f);
				PTargetLocation.Y = FMath::GridSnap(PTargetLocation.Y, 100.0f);

				UE_LOG(LogTemp, Warning, TEXT("Player StartLocation: X=%f Y=%f"), PStartLocation.X, PStartLocation.Y);
				UE_LOG(LogTemp, Warning, TEXT("Player TargetLocation: X=%f Y=%f"), PTargetLocation.X, PTargetLocation.Y);

				ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
				if (GameMode)
				{
					bool bIsPlayerControlled = true;
					PlayerPath.Empty();
					PlayerPath = GameMode->FindPath(SelectedUnit, PStartLocation, PTargetLocation, bIsPlayerControlled);
					PMovingUnit = SelectedUnit;

					if (PlayerPath.Num() > 0)
					{
						// Start StepByStep movement
						PCurrentStepIndex = 0;
						GetWorld()->GetTimerManager().SetTimer(PStepMoveTimer, this, &AGridPlayerController::MovePlayerStepByStep, 0.2f, true);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("No valid path found for Player"));
						GameMode->EndTurn();
					}
					GameMode->EndTurn();

					ClearMovementRange();
					//SelectedUnit = nullptr;
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No world"));
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No valid target"));
		}
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

		UE_LOG(LogTemp, Warning, TEXT("Moving to position: X=%f, Y=%f, Z=%f"), NextPosition.X, NextPosition.Y, NextPosition.Z);

		PMovingUnit->SetActorLocation(NextPosition);
		PCurrentStepIndex++;

		// Controlla se il movimento è completato
		if (PCurrentStepIndex >= PlayerPath.Num())
		{
			UE_LOG(LogTemp, Warning, TEXT("Movement completed"));
			GetWorld()->GetTimerManager().ClearTimer(PStepMoveTimer);
		}
	}
	else
	{
		// Termina il movimento
		UE_LOG(LogTemp, Warning, TEXT("Movement finished or invalid unit"));
		GetWorld()->GetTimerManager().ClearTimer(PStepMoveTimer);
	}
}

void AGridPlayerController::HandleAttackUnit()
{
	if (IsValid(SelectedUnit))
	{
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
			if (!IsValid(TargetUnit))
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to cast actor to AUnitBase"));
				return;
			}

			if (IsValid(TargetUnit) && TargetUnit != SelectedUnit && !TargetUnit->bIsPlayerControlled)
			{
				int32 DistanceX = FMath::Abs(TargetUnit->GetActorLocation().X - SelectedUnit->GetActorLocation().X) / 100;
				int32 DistanceY = FMath::Abs(TargetUnit->GetActorLocation().Y - SelectedUnit->GetActorLocation().Y) / 100;

				if (DistanceX + DistanceY <= SelectedUnit->AttackRange)
				{
					int32 CurrentDamage = FMath::RandRange(SelectedUnit->DamageMin, SelectedUnit->DamageMax);
					TargetUnit->ApplyDamage(CurrentDamage);

					if (SelectedUnit->UnitInfoWidget)
					{
						SelectedUnit->UnitInfoWidget->SetUnitInfo(SelectedUnit->GetName(), CurrentDamage, SelectedUnit->Health);
					}

					UE_LOG(LogTemp, Warning, TEXT("Attacking %s for %d damage"), *TargetUnit->GetName(), CurrentDamage);

					if (SelectedUnit->UnitType == EUnitType::Sniper)
					{
						TargetUnit->CounterAttack(SelectedUnit);
					}

					ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
					if (GameMode)
					{
						CurrentGameMode->EndTurn();
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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No unit selected"));
	}
}

void AGridPlayerController::ShowUnitInfo()
{
	if (UnitInfoWidgetClass)
	{
		if (!UnitInfoWidget)
		{
			UnitInfoWidget = CreateWidget<UUnitInfoWidget>(this, UnitInfoWidgetClass);
		}

		if (UnitInfoWidget)
		{
			//UnitInfoWidget->SetUnitInfo(TEXT("Unit Name"), 100, 100);
			UnitInfoWidget->AddToViewport();
		}
	}
}