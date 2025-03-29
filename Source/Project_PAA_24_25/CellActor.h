// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CellActor.generated.h"

UCLASS()
class PROJECT_PAA_24_25_API ACellActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACellActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* CellMesh;

	UFUNCTION(BlueprintCallable)
	void HighlightCell(bool bHighlight);

	UFUNCTION(BlueprintCallable)
	void SetCellColor(FColor NewColor);

	void ResetToOriginalColor();

private:
	FColor OriginalColor;
};