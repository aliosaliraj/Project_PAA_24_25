#include "CellActor.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"

ACellActor::ACellActor()
{
	PrimaryActorTick.bCanEverTick = false;

	CellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cell Mesh"));
	RootComponent = CellMesh;

	OriginalColor = FLinearColor(0.4f, 0.26f, 0.13f);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube"));

	if (CubeMesh.Succeeded())
	{
		CellMesh->SetStaticMesh(CubeMesh.Object);
		CellMesh->SetWorldScale3D(FVector(1.0f, 1.0f, 0.1f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Game/M_Cell"));

	if (Material.Succeeded())
	{
		CellMesh->SetMaterial(0, Material.Object);
	}

	CellMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CellMesh->SetCollisionObjectType(ECC_WorldStatic);
	CellMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	CellMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
}

void ACellActor::BeginPlay()
{
	Super::BeginPlay();

	int32 X = FMath::RoundToInt(GetActorLocation().X) / 100;
	int32 Y = FMath::RoundToInt(GetActorLocation().Y) / 100;

	FLinearColor LightBrown = FLinearColor(0.4f, 0.26f, 0.13f);  // Light brown
	FLinearColor DarkBrown = FLinearColor(0.3f, 0.2f, 0.1f);     // Dark brown

	OriginalColor = ((X + Y) % 2 == 0) ? LightBrown : DarkBrown;

	ResetToOriginalColor();
}

void ACellActor::SetCellColor(FLinearColor NewColor)
{
	UMaterialInstanceDynamic* DynamicMaterial = CellMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynamicMaterial)
	{
		DynamicMaterial->SetVectorParameterValue(FName("BaseColor"), FLinearColor(NewColor));
	}
}

void ACellActor::HighlightCell(bool bHighlight)
{
	// Set the cell color based on the highlight state (true for move, false for attack)
	SetCellColor(bHighlight ? FColor::Green : FColor::Red);
}

void ACellActor::ResetToOriginalColor()
{
	SetCellColor(OriginalColor);
}