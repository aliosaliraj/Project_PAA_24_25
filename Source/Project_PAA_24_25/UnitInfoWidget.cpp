// Fill out your copyright notice in the Description page of Project Settings.
#include "UnitInfoWidget.h"
#include "GridPlayerController.h"
#include "TurnBasedGameMode.h"
#include "UnitBase.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"

void UUnitInfoWidget::UpdateUnitInfo(int32 UnitDamage, int32 UnitHealth, int32 UnitIndex)
{
    InvalidateLayoutAndVolatility();

    switch (UnitIndex)
    {
    case 0: // Player Sniper
        if (PSniperName) PSniperName->SetText(FText::FromString("Player Sniper"));
        
		if (UnitHealth <= 0) PSniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Eliminated")))); // If unit eliminated, show "Eliminated" instead of health
        else PSniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));

        if (PSniperDamage) PSniperDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage)));
        break;

    case 1: // Player Brawler
        if (PBrawlerName) PBrawlerName->SetText(FText::FromString("Player Brawler"));

		if (UnitHealth <= 0) PBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Eliminated")))); // If unit eliminated, show "Eliminated" instead of health
        else  PBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));

        if (PBrawlerDamage) PBrawlerDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage)));
        break;

    case 2: // Enemy Sniper
        if (ESniperName) ESniperName->SetText(FText::FromString("AI Sniper"));

		if (UnitHealth <= 0) ESniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Eliminated")))); // If unit eliminated, show "Eliminated" instead of health
		else ESniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));

        if (ESniperDamage) ESniperDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage))); 
        break;

    case 3: // Enemy Brawler
        if (EBrawlerName) EBrawlerName->SetText(FText::FromString("AI Brawler"));

		if (UnitHealth <= 0) EBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Eliminated")))); // If unit eliminated, show "Eliminated" instead of health
		else EBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));

        if (EBrawlerDamage) EBrawlerDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage)));
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Invalid UnitIndex: %d"), UnitIndex);
        break;
    }
}