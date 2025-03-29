// Fill out your copyright notice in the Description page of Project Settings.


#include "Brawler.h"
#include "UnitInfoWidget.h"

ABrawler::ABrawler()
{
	Health = 40;
	MaxMovement = 6;
	AttackRange = 1;
	DamageMin = 1;
	DamageMax = 6;

	static ConstructorHelpers::FClassFinder<UUnitInfoWidget> WidgetClass(TEXT("/Game/BlueprintClasses/UnitInfoWidget_BP.UnitInfoWidget_BP_C"));
	if (WidgetClass.Succeeded())
	{
		UnitInfoWidgetClass = WidgetClass.Class;
	}
	else UE_LOG(LogTemp, Warning, TEXT("Failed to find UnitInfoWidget_BP class for brawler."));
}
