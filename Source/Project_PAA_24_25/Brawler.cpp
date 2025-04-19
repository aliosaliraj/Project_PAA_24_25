// Fill out your copyright notice in the Description page of Project Settings.


#include "Brawler.h"
#include "UnitInfoWidget.h"

ABrawler::ABrawler()
{
	Health = 40;
	MaxMovement = 7; // one more to consent correct movement
	AttackRange = 1;
	DamageMin = 1;
	DamageMax = 6;
	/*
	static ConstructorHelpers::FClassFinder<UUnitInfoWidget> WidgetClass(TEXT("/Game/BlueprintClasses/UnitInfoWidget_BPP.UnitInfoWidget_BPP_C"));
	if (WidgetClass.Succeeded())
	{
		UnitInfoWidgetClass = WidgetClass.Class;
	}
	else UE_LOG(LogTemp, Warning, TEXT("Failed to find UnitInfoWidget_BPP class for brawler."));*/
}
