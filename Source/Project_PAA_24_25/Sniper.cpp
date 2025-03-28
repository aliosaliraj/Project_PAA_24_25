// Fill out your copyright notice in the Description page of Project Settings.


#include "Sniper.h"
#include "UnitInfoWidget.h"

ASniper::ASniper()
{
	Health = 20;
	MaxMovement = 3;
	AttackRange = 10;
	DamageMin = 4;
	DamageMax = 8;

	static ConstructorHelpers::FClassFinder<UUnitInfoWidget> WidgetClass(TEXT("/Game/BlueprintClasses/UnitInfoWidget_BP.UnitInfoWidget_BP_C"));
	if (WidgetClass.Succeeded())
	{
		UnitInfoWidgetClass = WidgetClass.Class;
	}
	else UE_LOG(LogTemp, Warning, TEXT("Failed to find UnitInfoWidget_BP class for sniper."));
}