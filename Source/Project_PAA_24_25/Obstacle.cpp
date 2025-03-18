// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
	RootComponent = ObstacleMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObstacleMeshAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	if (ObstacleMeshAsset.Succeeded())
	{
		ObstacleMesh->SetStaticMesh(ObstacleMeshAsset.Object);
	}

	ObstacleMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ObstacleMesh->SetCollisionObjectType(ECC_WorldStatic);
	ObstacleMesh->SetCollisionResponseToAllChannels(ECR_Block);

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

