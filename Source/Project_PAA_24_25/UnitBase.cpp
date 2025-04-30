#include "UnitBase.h"
#include "TurnBasedGameMode.h"
#include "GridPlayerController.h"
#include "UnitInfoWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"


AUnitBase::AUnitBase()
{
	PrimaryActorTick.bCanEverTick = true;

	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Unit Mesh"));
	RootComponent = UnitMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(TEXT("/Engine/BasicShapes/Cylinder"));

	if (CylinderMesh.Succeeded())
	{
		UnitMesh->SetStaticMesh(CylinderMesh.Object);
		UnitMesh->SetWorldScale3D(FVector(0.85f, 0.85f, 0.1f));

		static ConstructorHelpers::FObjectFinder<UMaterial> SniperPlayerMaterial(TEXT("/Game/Textures/SniperPlayerMat.SniperPlayerMat"));
		static ConstructorHelpers::FObjectFinder<UMaterial> SniperEnemyMaterial(TEXT("/Game/Textures/SniperEnemyMat.SniperEnemyMat"));
		static ConstructorHelpers::FObjectFinder<UMaterial> BrawlerPlayerMaterial(TEXT("/Game/Textures/BrawlerPlayerMat.BrawlerPlayerMat"));
		static ConstructorHelpers::FObjectFinder<UMaterial> BrawlerEnemyMaterial(TEXT("/Game/Textures/BrawlerEnemyMat.BrawlerEnemyMat"));

		if (SniperPlayerMaterial.Succeeded())
		{
			SniperPlayerMat = SniperPlayerMaterial.Object;
		}

		if (SniperEnemyMaterial.Succeeded())
		{
			SniperEnemyMat = SniperEnemyMaterial.Object;
		}

		if (BrawlerPlayerMaterial.Succeeded())
		{
			BrawlerPlayerMat = BrawlerPlayerMaterial.Object;
		}

		if (BrawlerEnemyMaterial.Succeeded())
		{
			BrawlerEnemyMat = BrawlerEnemyMaterial.Object;
		}
	}
}

void AUnitBase::BeginPlay()
{
	Super::BeginPlay();

	if (UnitType == EUnitType::Sniper)
	{
		if (bIsPlayerControlled && SniperPlayerMat)
		{
			UnitMesh->SetMaterial(0, SniperPlayerMat);
		}
		else if (!bIsPlayerControlled && SniperEnemyMat)
		{
			UnitMesh->SetMaterial(0, SniperEnemyMat);
		}
	}
	else if (UnitType == EUnitType::Brawler)
	{
		if (bIsPlayerControlled && BrawlerPlayerMat)
		{
			UnitMesh->SetMaterial(0, BrawlerPlayerMat);
		}
		else if (!bIsPlayerControlled && BrawlerEnemyMat)
		{
			UnitMesh->SetMaterial(0, BrawlerEnemyMat);
		}
	}

	// Reset all units actions
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	for (AUnitBase* Unit : GameMode->PlayerUnits)
	{
		Unit->bCanMove = true;
		Unit->bCanAttack = true;
		Unit->bCanAttackAfterMove = false;
		Unit->bHasCompletedAction = false;
		Unit->bIsPlaced = false;
	}
	for (AUnitBase* Unit : GameMode->EnemyUnits)
	{
		Unit->bHasCompletedAction = false;
	}
}

FString AUnitBase::GetUnitType() const
{
	switch (UnitType)
	{
	case EUnitType::Sniper:
		return TEXT("S");
	case EUnitType::Brawler:
		return TEXT("B");
	default:
		return TEXT("Unknown");
	}
}

void AUnitBase::ApplyDamage(int32 DamageAmount)
{
	CurrentDamage = DamageAmount;
	Health -= DamageAmount;

	if (Health <= 0)
	{
		Health = 0;
		
		ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			// Remove unit from appropriate array
			if (bIsPlayerControlled)
			{
				GameMode->PlayerUnits.Remove(this);
				GameMode->EliminatedPlayerUnits.Add(this);
			}
			else
			{
				GameMode->EnemyUnits.Remove(this);
				GameMode->EliminatedEnemyUnits.Add(this);
				GameMode->CurrentEnemyUnitIndex--;
			}
		}
		SetLifeSpan(0.1f);					// Destroy the unit after a short delay
		GameMode->CheckEndGameCondition();	// Check if the game should end
	}
}

void AUnitBase::CounterAttack(AUnitBase* Attacker)
{
	// Only for sniper:
	if (UnitType == EUnitType::Sniper || FVector::Dist(this->GetActorLocation(), Attacker->GetActorLocation()) <= 100.0f)
	{
		int32 CounterDamage = FMath::RandRange(1, 3);
		Attacker->ApplyDamage(CounterDamage);

		FString PlayerID = this->bIsPlayerControlled ? TEXT("HP") : TEXT("AI");

		// Update Widget and History after counter-attack
		AGridPlayerController* PlayerController = Cast<AGridPlayerController>(GetWorld()->GetFirstPlayerController());
		if (!PlayerController)
		{
			return;
		}
		PlayerController->UpdateAllUnitWidgets();

		// Highlight the cell where the counter-attack occurred
		PlayerController->FindCellUnderUnit(this->GetActorLocation())->HighlightCell(false);
		PlayerController->AttackCells.Add(PlayerController->FindCellUnderUnit(this->GetActorLocation()));

		ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
		if (!GameMode)
		{
			return;
		}
		FString TargetCell = GameMode->ConvertPositionToNotation(Attacker->GetActorLocation());
		
		// Log the counter-attack
		if (Attacker->bIsPlayerControlled) PlayerController->StoreAttack(this, Attacker, CounterDamage);
		else GameMode->LogAttack(PlayerID, this->GetUnitType(), TargetCell, CounterDamage);
	}
}

void AUnitBase::UpdateMaterial()
{
	if (UnitType == EUnitType::Sniper)
	{
		if (bIsPlayerControlled && SniperPlayerMat)
		{
			UnitMesh->SetMaterial(0, SniperPlayerMat);
		}
		else if (!bIsPlayerControlled && SniperEnemyMat)
		{
			UnitMesh->SetMaterial(0, SniperEnemyMat);
		}
	}
	else if (UnitType == EUnitType::Brawler)
	{
		if (bIsPlayerControlled && BrawlerPlayerMat)
		{
			UnitMesh->SetMaterial(0, BrawlerPlayerMat);
		}
		else if (!bIsPlayerControlled && BrawlerEnemyMat)
		{
			UnitMesh->SetMaterial(0, BrawlerEnemyMat);
		}
	}
}