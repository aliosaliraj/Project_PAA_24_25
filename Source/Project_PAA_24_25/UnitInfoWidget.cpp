// Fill out your copyright notice in the Description page of Project Settings.
#include "UnitInfoWidget.h"
#include "UnitBase.h"
#include "Components/TextBlock.h"


void UUnitInfoWidget::SetUnitInfo(FString Name, int32 Damage, int32 Health)
{
	if (UnitNameText) UnitNameText->SetText(FText::FromString(Name));
	if (UnitDamageText) UnitDamageText->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), Damage)));
	if (UnitHealthText) UnitHealthText->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), Health)));
}

