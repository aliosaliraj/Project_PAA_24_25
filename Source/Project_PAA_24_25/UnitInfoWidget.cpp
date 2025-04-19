// Fill out your copyright notice in the Description page of Project Settings.
#include "UnitInfoWidget.h"
#include "GridPlayerController.h"
#include "UnitBase.h"
#include "Components/TextBlock.h"

void UUnitInfoWidget::UpdateUnitInfo(const FString& UnitName, int32 UnitDamage, int32 UnitHealth, int32 UnitIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Updating Widget: UnitIndex=%d, Name=%s, Damage=%d, Health=%d"), UnitIndex, *UnitName, UnitDamage, UnitHealth);

    InvalidateLayoutAndVolatility();

    switch (UnitIndex)
    {
    case 0: // Player Sniper
        if (PSniperName) 
        {
            PSniperName->SetText(FText::FromString(UnitName));
            SynchronizeProperties();
        }
            
        if (PSniperHealth) 
        {
            PSniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
			SynchronizeProperties();
		}
        if (PSniperDamage)
        {
            PSniperDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage)));
			SynchronizeProperties();
		}
        break;

    case 1: // Player Brawler
        if (PBrawlerName)
        {
            PBrawlerName->SetText(FText::FromString(UnitName));
            SynchronizeProperties();
		}
        if (PBrawlerHealth) 
        {
            PBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
			SynchronizeProperties();
		}
        if (PBrawlerDamage) 
        {
            PBrawlerDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage)));
			SynchronizeProperties();
		}
        break;

    case 2: // Enemy Sniper
        if (ESniperName) 
        {
            ESniperName->SetText(FText::FromString(UnitName));
			SynchronizeProperties();
		}
        if (ESniperHealth) 
        {
            ESniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
			SynchronizeProperties();
		}
        if (ESniperDamage) 
        {
            ESniperDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage)));
			SynchronizeProperties();
		}
        break;
    case 3: // Enemy Brawler
        if (EBrawlerName) 
        {
            EBrawlerName->SetText(FText::FromString(UnitName));
			SynchronizeProperties();
		}
        if (EBrawlerHealth)
        {
            EBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
            SynchronizeProperties();
        }
        if (EBrawlerDamage) 
        {
            EBrawlerDamage->SetText(FText::FromString(FString::Printf(TEXT("Damage: %d"), UnitDamage)));
			SynchronizeProperties();
		}
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Invalid UnitIndex: %d"), UnitIndex);
        break;
    }
}