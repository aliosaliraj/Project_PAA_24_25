// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedGameMode.h"
#include "GridPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UnitBase.h"
#include "Sniper.h"
#include "Brawler.h"
//#include "Obstacle.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"


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
	StartPlayerTurn();
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
	
	for (AActor* Actor : FoundActors)
	{
		if (IsValid(Actor))
		{
			AUnitBase* EnemyUnit = Cast<AUnitBase>(Actor);
			if (EnemyUnit && !EnemyUnit->bIsPlayerControlled)
			{
				UE_LOG(LogTemp, Warning, TEXT("AI moving unit: %s"), *EnemyUnit->GetName());

				int32 DeltaX = FMath::RandRange(-EnemyUnit->MaxMovement, EnemyUnit->MaxMovement);
				int32 DeltaY = FMath::RandRange(-EnemyUnit->MaxMovement, EnemyUnit->MaxMovement);

				if (FMath::Abs(DeltaX) + FMath::Abs(DeltaY) <= EnemyUnit->MaxMovement)
				{
					FVector TargetLocation = EnemyUnit->GetActorLocation() + FVector(DeltaX * 100, DeltaY * 100, 0);

					if (TargetLocation.X >= 0 && TargetLocation.X < 2500 && TargetLocation.Y >= 0 && TargetLocation.Y < 2500)
					{
						EnemyUnit->SetActorLocation(TargetLocation);
						UE_LOG(LogTemp, Warning, TEXT("AI moved unit to %s"), *TargetLocation.ToString());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Invalid target location"));
					}
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Enemy unit invalid or player-controlled"));
			}
		}
		else 
		{			
			UE_LOG(LogTemp, Warning, TEXT("Invalid AI unit or actor"));
		}
	}
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ATurnBasedGameMode::StartPlayerTurn);
}

void ATurnBasedGameMode::EndTurn()
{
	if (CurrentTurn == ETurnState::PlayerTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ending player turn"));
		GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ATurnBasedGameMode::StartEnemyTurn);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ending enemy turn"));
		GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ATurnBasedGameMode::StartPlayerTurn);
	}
}

void ATurnBasedGameMode::SpawnUnits()
{
	if (GetWorld())
	{
		if (PlayerUnitClass)
		{
			FVector PlayerLocation = FVector(100, 100, 50);
			AUnitBase* PlayerUnit = GetWorld()->SpawnActor<AUnitBase>(PlayerUnitClass, PlayerLocation, FRotator::ZeroRotator);
			if (PlayerUnit)
			{
				PlayerUnit->bIsPlayerControlled = true;
				UE_LOG(LogTemp, Warning, TEXT("Player unit spawned at %s"), *PlayerLocation.ToString());
				UE_LOG(LogTemp, Warning, TEXT("Player unit is controlled by: %s"), PlayerUnit->bIsPlayerControlled ? TEXT("Player") : TEXT("AI"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to spawn player unit"));
			}
		}

		if (EnemyUnitClass)
		{
			FVector EnemyLocation = FVector(500, 500, 50);
			AUnitBase* EnemyUnit = GetWorld()->SpawnActor<AUnitBase>(EnemyUnitClass, EnemyLocation, FRotator::ZeroRotator);
			if (EnemyUnit)
			{
				EnemyUnit->bIsPlayerControlled = false;
				UE_LOG(LogTemp, Warning, TEXT("Enemy unit spawned at %s"), *EnemyLocation.ToString());
				UE_LOG(LogTemp, Warning, TEXT("Enemy unit is controlled by: %s"), EnemyUnit->bIsPlayerControlled ? TEXT("Player") : TEXT("AI"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to spawn enemy unit"));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No world found"));
	}
}