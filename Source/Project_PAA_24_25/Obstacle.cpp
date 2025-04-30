#include "Obstacle.h"

AObstacle::AObstacle()
{
	PrimaryActorTick.bCanEverTick = false;

	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstacle Mesh"));
	RootComponent = ObstacleMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObstacleMeshAsset(TEXT("/Engine/BasicShapes/Cylinder"));

	if (ObstacleMeshAsset.Succeeded())
	{
		ObstacleMesh->SetStaticMesh(ObstacleMeshAsset.Object);
		ObstacleMesh->SetWorldScale3D(FVector(0.85f, 0.85f, 0.1f));
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

void AObstacle::SetMaterial(bool bTree)
{
	bIsTree = bTree;

	if (bIsTree && TreeMaterial)
	{
		ObstacleMesh->SetMaterial(0, TreeMaterial);
	}
	else if (!bIsTree && MountainMaterial)
	{
		ObstacleMesh->SetMaterial(0, MountainMaterial);
	}
}