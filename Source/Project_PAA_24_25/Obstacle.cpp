// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstacle Mesh"));
	RootComponent = ObstacleMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObstacleMeshAsset(TEXT("/Engine/BasicShapes/Cylinder"));

	if (ObstacleMeshAsset.Succeeded())
	{
		ObstacleMesh->SetStaticMesh(ObstacleMeshAsset.Object);
		ObstacleMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.1f));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find Obstacle Mesh"));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> TreeMaterialAsset(TEXT("/Game/Textures/TreeMaterial.TreeMaterial"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MountainMaterialAsset(TEXT("/Game/Textures/MountainMaterial.MountainMaterial"));

	if (TreeMaterialAsset.Succeeded())
	{
		TreeMaterial = TreeMaterialAsset.Object;
	}

	if (MountainMaterialAsset.Succeeded())
	{
		MountainMaterial = MountainMaterialAsset.Object;
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

void AObstacle::SetMaterial(bool bTree)
{
	bIsTree = bTree;

	if (bIsTree && TreeMaterial)
	{
		ObstacleMesh->SetMaterial(0, TreeMaterial);
		UE_LOG(LogTemp, Error, TEXT("TreeMaterial set"));
	}
	else if (!bIsTree && MountainMaterial)
	{
		ObstacleMesh->SetMaterial(0, MountainMaterial);
		UE_LOG(LogTemp, Error, TEXT("MountainMaterial succeded"));
	}
}