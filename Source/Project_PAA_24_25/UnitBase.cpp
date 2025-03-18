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

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere"));

	if (SphereMesh.Succeeded())
	{
		UnitMesh->SetStaticMesh(SphereMesh.Object);
		UnitMesh->SetWorldScale3D(FVector(0.5f));
	}
	Health = 100;
	MaxMovement = 5;
	AttackRange = 1;
	DamageMin = 10;
	DamageMax = 20;
}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s is controlled by: %s"), *GetName(), bIsPlayerControlled ? TEXT("PLAYER") : TEXT("AI"));

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

