#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class PROJECT_PAA_24_25_API AObstacle : public AActor
{
	GENERATED_BODY()

public:
	AObstacle();

public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ObstacleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	UMaterial* TreeMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	UMaterial* MountainMaterial;

	//Obstacle type:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstacle")
	bool bIsTree;															// Boolean variable that if true sets the obstacle material as a tree, otherwhise as a mountain

	UFUNCTION()
	void SetMaterial(bool bTree);
};