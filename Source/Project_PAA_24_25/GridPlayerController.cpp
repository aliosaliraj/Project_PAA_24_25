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

void AGridPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SelectUnit", IE_Pressed, this, &AGridPlayerController::HandleSelectUnit);
	InputComponent->BindAction("MoveUnit", IE_Pressed, this, &AGridPlayerController::HandleMoveUnit);
	InputComponent->BindAction("AttackUnit", IE_Pressed, this, &AGridPlayerController::HandleAttackUnit);
}

void AGridPlayerController::HandleSelectUnit()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *HitResult.GetActor()->GetName());
			UE_LOG(LogTemp, Warning, TEXT("Collision channel: %d"), HitResult.Component->GetCollisionObjectType());
		}

		AUnitBase* HitUnit = Cast<AUnitBase>(HitResult.GetActor());
		if (IsValid(HitUnit) && HitUnit->bIsPlayerControlled)
		{
			SelectedUnit = HitUnit;
			ClearMovementRange();
			UE_LOG(LogTemp, Warning, TEXT("Selected unit: %s"), *HitUnit->GetName());
			ShowMovementRange();

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
				UE_LOG(LogTemp, Warning, TEXT("Cannot select AI unit"));
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

		for (int32 x = -SelectedUnit->MaxMovement; x <= SelectedUnit->MaxMovement; x++)
		{
			for (int32 y = -SelectedUnit->MaxMovement; y <= SelectedUnit->MaxMovement; y++)
			{
				if (FMath::Abs(x) + FMath::Abs(y) <= SelectedUnit->MaxMovement)
				{
					FVector Location = SelectedUnit->GetActorLocation() + FVector(x * 100, y * 100, 0);

					FHitResult CellHit;
					GetWorld()->LineTraceSingleByChannel(CellHit, Location + FVector(0, 0, 100), Location - FVector(0, 0, 100), ECC_WorldStatic);

					if (CellHit.bBlockingHit)
					{
						ACellActor* Cell = Cast<ACellActor>(CellHit.GetActor());
						if (Cell)
						{
							Cell->HighlightCell(true);
						}
					}
					else 
					{
						UE_LOG(LogTemp, Warning, TEXT("Raycast hit something else"));
					}
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
				FVector TargetLocation = HitResult.Location;
				TargetLocation.Z = SelectedUnit->GetActorLocation().Z;

				TargetLocation.X = FMath::RoundToFloat(TargetLocation.X / 100) * 100;
				TargetLocation.Y = FMath::RoundToFloat(TargetLocation.Y / 100) * 100;

				int32 DistanceX = FMath::Abs(TargetLocation.X - SelectedUnit->GetActorLocation().X) / 100;
				int32 DistanceY = FMath::Abs(TargetLocation.Y - SelectedUnit->GetActorLocation().Y) / 100;

				UE_LOG(LogTemp, Warning, TEXT("Trying to move to: X=%f Y=%f"), TargetLocation.X, TargetLocation.Y);
				UE_LOG(LogTemp, Warning, TEXT("Distance calculated: X=%d Y=%d"), DistanceX, DistanceY);

				if (DistanceX + DistanceY <= SelectedUnit->MaxMovement)
				{
					SelectedUnit->SetActorLocation(TargetLocation);
					SelectedUnit = nullptr;
					ClearMovementRange();

					if (GetWorld()->GetAuthGameMode())
					{
						ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
						if (GameMode) GameMode->EndTurn();

						UE_LOG(LogTemp, Warning, TEXT("Turn ended"));
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Movement denied: out of range"));
				}
			}
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("No valid target"));
		}
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