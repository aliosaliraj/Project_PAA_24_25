// Fill out your copyright notice in the Description page of Project Settings.


#include "CellActor.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ACellActor::ACellActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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
	CellMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);  //per evidenziare le celle
	CellMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);		//per ignorare collisioni
}

// Called when the game starts or when spawned
void ACellActor::BeginPlay()
{
	Super::BeginPlay();

	int32 X = FMath::RoundToInt(GetActorLocation().X) / 100;
	int32 Y = FMath::RoundToInt(GetActorLocation().Y) / 100;

	FLinearColor LightBrown = FLinearColor(0.4f, 0.26f, 0.13f);  // Marrone chiaro
	FLinearColor DarkBrown = FLinearColor(0.3f, 0.2f, 0.1f);     // Marrone scuro

	OriginalColor = ((X + Y) % 2 == 0) ? LightBrown : DarkBrown;

	ResetToOriginalColor();
}

// Called every frame
void ACellActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACellActor::SetCellColor(FLinearColor NewColor)
{
	UMaterialInstanceDynamic* DynamicMaterial = CellMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynamicMaterial)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Material Applied, setting color..."))
		DynamicMaterial->SetVectorParameterValue(FName("BaseColor"), FLinearColor(NewColor));
	}
}

void ACellActor::HighlightCell(bool bHighlight)
{
	SetCellColor(bHighlight ? FColor::Green : OriginalColor);
}

void ACellActor::ResetToOriginalColor()
{
	SetCellColor(OriginalColor);
}