// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitBase.h"
#include "UnitInfoWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AUnitBase::AUnitBase()
{
	PrimaryActorTick.bCanEverTick = true;

	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Unit Mesh"));
	RootComponent = UnitMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(TEXT("/Engine/BasicShapes/Cylinder"));

	if (CylinderMesh.Succeeded())
	{
		UnitMesh->SetStaticMesh(CylinderMesh.Object);
		UnitMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.1f));

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

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s is controlled by: %s"), *GetName(), bIsPlayerControlled ? TEXT("PLAYER") : TEXT("AI"));

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

// Called every frame
void AUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUnitBase::ApplyDamage(int32 DamageAmount)
{
	Health -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("%s took %d damage. Health now: %d"), *GetName(), DamageAmount, Health);

	if (Health <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has been destroyed."), *GetName());
		Destroy();
	}
}

void AUnitBase::CounterAttack(AUnitBase* Attacker)
{
	if (!Attacker)
	{
		UE_LOG(LogTemp, Warning, TEXT("Sniper attacking unit not valid"));
	}

	// Only for sniper:
	if (UnitType == EUnitType::Sniper || FVector::Dist(GetActorLocation(), Attacker->GetActorLocation()) <= 100.0f)
	{
		int32 CounterDamage = FMath::RandRange(1, 3);
		Attacker->ApplyDamage(CounterDamage);

		UE_LOG(LogTemp, Warning, TEXT("%s counter-attacks %s causing %d danni!"), *GetName(), *Attacker->GetName(), CounterDamage);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Conditions not valid for counter-attack"));
	}
}

/*
void AUnitBase::AttackTarget(AUnitBase* Target)
{
	if (Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is attacking %s for %d damage!"), *GetName(), *Target->GetName(), CurrentDamage);
		Target->ApplyDamage(CurrentDamage);
	}
}*/

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