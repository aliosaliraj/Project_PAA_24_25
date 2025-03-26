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

		static ConstructorHelpers::FObjectFinder<UMaterial> SniperMaterial(TEXT("/Game/Textures/Soldier1_Mat"));
		static ConstructorHelpers::FObjectFinder<UMaterial> BrawlerMaterial(TEXT("/Game/Textures/Soldier2_Mat"));

		if (SniperMaterial.Succeeded())
		{
			SniperMat = SniperMaterial.Object;
		}

		if (BrawlerMaterial.Succeeded())
		{
			BrawlerMat = BrawlerMaterial.Object;
		}
	}
}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s is controlled by: %s"), *GetName(), bIsPlayerControlled ? TEXT("PLAYER") : TEXT("AI"));

	if (UnitType == EUnitType::Sniper && SniperMat)
	{
		UnitMesh->SetMaterial(0, SniperMat);
	}
	else if (UnitType == EUnitType::Brawler && BrawlerMat)
	{
		UnitMesh->SetMaterial(0, BrawlerMat);
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

void AUnitBase::AttackTarget(AUnitBase* Target)
{
	if (Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is attacking %s for %d damage!"), *GetName(), *Target->GetName(), CurrentDamage);
		Target->ApplyDamage(CurrentDamage);
	}
}

