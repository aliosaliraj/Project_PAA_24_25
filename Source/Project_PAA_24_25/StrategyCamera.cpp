// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyCamera.h"

AStrategyCamera::AStrategyCamera()
{
	CustomCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CustomCameraComponent"));
	CustomCameraComponent->SetupAttachment(RootComponent);

	CustomCameraComponent->FieldOfView = 50.0f;

	CustomCameraComponent->AspectRatio = 1.3333f;
}

void AStrategyCamera::BeginPlay()
{
	Super::BeginPlay();
}