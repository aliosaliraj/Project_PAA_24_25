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
}
