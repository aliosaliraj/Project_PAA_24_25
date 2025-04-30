#include "StrategyCamera.h"

AStrategyCamera::AStrategyCamera()
{
	CustomCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CustomCameraComponent"));
	CustomCameraComponent->SetupAttachment(RootComponent);

	CustomCameraComponent->FieldOfView = 50.0f;

	CustomCameraComponent->AspectRatio = 1.3333f;
}