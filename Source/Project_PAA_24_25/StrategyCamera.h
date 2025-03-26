// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "StrategyCamera.generated.h"


UCLASS()
class PROJECT_PAA_24_25_API AStrategyCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	AStrategyCamera();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CustomCameraComponent;

	virtual void BeginPlay() override;
};
