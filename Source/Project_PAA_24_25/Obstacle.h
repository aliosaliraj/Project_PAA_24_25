// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class PROJECT_PAA_24_25_API AObstacle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ObstacleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	UMaterial* TreeMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	UMaterial* MountainMaterial;

	//Obstacle type:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstacle")
	bool bIsTree; // true = tree, false = mountain

	UFUNCTION()
	void SetMaterial(bool bTree);
};