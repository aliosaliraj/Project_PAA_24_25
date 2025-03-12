// Fill out your copyright notice in the Description page of Project Settings.


#include "GridPlayerController.h"
#include "UnitBase.h"
#include "CellActor.h"
#include "TurnBasedGameMode.h"
#include "Engine/World.h"
//#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

AGridPlayerController::AGridPlayerController()
{
	bShowMouseCursor = true;
}

void AGridPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AGridPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SelectUnit", IE_Pressed, this, &AGridPlayerController::HandleSelectUnit);
	InputComponent->BindAction("MoveUnit", IE_Pressed, this, &AGridPlayerController::HandleMoveUnit);
}

void AGridPlayerController::HandleSelectUnit()
{
	
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode && GameMode->CurrentTurn != ETurnState::PlayerTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not player turn"));
		return;
	}

	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		AUnitBase* HitUnit = Cast<AUnitBase>(HitResult.GetActor());
		if (IsValid(HitUnit))
		{
			ClearMovementRange();
			SelectedUnit = HitUnit;
			UE_LOG(LogTemp, Warning, TEXT("Selected unit: %s"), *HitUnit->GetName());
			ShowMovementRange();
		}
		else
		{
				UE_LOG(LogTemp, Warning, TEXT("Cannot select AI unit"));
		}
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
						UE_LOG(LogTemp, Warning, TEXT("Raycast hit: %s"), CellHit.GetActor() ? *CellHit.GetActor()->GetName() : TEXT("Invalid Actor"));

						ACellActor* Cell = Cast<ACellActor>(CellHit.GetActor());
						if (IsValid(Cell))
						{
							Cell->HighlightCell(true);
						}
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Raycast Missed"));
					}
				}
			}
		}
	}
}

void AGridPlayerController::ClearMovementRange()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACellActor::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		ACellActor* Cell = Cast<ACellActor>(Actor);
		if (Cell)
		{
			Cell->ResetToOriginalColor();
		}
	}
}

void AGridPlayerController::HandleMoveUnit()
{
	if (IsValid(SelectedUnit))
	{
		ATurnBasedGameMode* CurrentGameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
		if (CurrentGameMode && CurrentGameMode->CurrentTurn != ETurnState::PlayerTurn)
		{
			UE_LOG(LogTemp, Warning, TEXT("Not player turn"));
			return;
		}

		if (SelectedUnit)
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
				if (Cell)
				{
					FVector TargetLocation = HitResult.Location;
					TargetLocation.Z = SelectedUnit->GetActorLocation().Z;

					int32 DistanceX = FMath::Abs(TargetLocation.X - SelectedUnit->GetActorLocation().X) / 100;
					int32 DistanceY = FMath::Abs(TargetLocation.Y - SelectedUnit->GetActorLocation().Y) / 100;

					if (TargetLocation.X < 0 || TargetLocation.X >= 2500 || TargetLocation.Y < 0 || TargetLocation.Y >= 2500)
					{
						UE_LOG(LogTemp, Warning, TEXT("Movement denied: out of grid"));
						return;
					}

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
		}
	}
}