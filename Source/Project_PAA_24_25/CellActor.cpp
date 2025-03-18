// Fill out your copyright notice in the Description page of Project Settings.


#include "CellActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ACellActor::ACellActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cell Mesh"));
	RootComponent = CellMesh;

	OriginalColor = FColor::Black;

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

	CellMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CellMesh->SetCollisionObjectType(ECC_Pawn);
	CellMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

// Called when the game starts or when spawned
void ACellActor::BeginPlay()
{
	Super::BeginPlay();

	int32 X = FMath::RoundToInt(GetActorLocation().X) / 100;
	int32 Y = FMath::RoundToInt(GetActorLocation().Y) / 100;
	OriginalColor = ((X + Y) % 2 == 0) ? FColor::Black : FColor::White;
	ResetToOriginalColor();
}

// Called every frame
void ACellActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACellActor::SetCellColor(FColor NewColor)
{
	UMaterialInstanceDynamic* DynamicMaterial = CellMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynamicMaterial)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Material Applied, setting color..."))
		DynamicMaterial->SetVectorParameterValue(FName("BaseColor"), FLinearColor(NewColor));
	}
	if (IsValid(CellMesh))
	{
		CellMesh->SetVectorParameterValueOnMaterials("Base Color", FVector(NewColor));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CellMesh1 is not valid"));
	}
}

void ACellActor::HighlightCell(bool bHighlight)
{
	SetCellColor(bHighlight ? FColor::Green : OriginalColor);
	if (IsValid(CellMesh))
	{
		FLinearColor NewColor = bHighlight ? FLinearColor::Green : FLinearColor::White;
		CellMesh->SetVectorParameterValueOnMaterials("Base Color", FVector(NewColor));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("CellMesh2 is not valid"));
	}
}

void ACellActor::ResetToOriginalColor()
{
	SetCellColor(OriginalColor);
	if (IsValid(CellMesh))
	{
		CellMesh->SetVectorParameterValueOnMaterials("Base Color", FVector(OriginalColor));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CellMesh3 is not valid"));
	}
}
