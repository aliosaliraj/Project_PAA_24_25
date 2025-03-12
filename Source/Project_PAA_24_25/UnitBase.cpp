// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitBase.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AUnitBase::AUnitBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Unit Mesh"));
	RootComponent = UnitMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere"));

	if (SphereMesh.Succeeded())
	{
		UnitMesh->SetStaticMesh(SphereMesh.Object);
		UnitMesh->SetWorldScale3D(FVector(0.5f));
	}

}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (bIsPlayerControlled)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlled by PLAYER"), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlled by AI"), *GetName());
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
	if (Health <= 0)
	{
		Destroy();
	}
}

