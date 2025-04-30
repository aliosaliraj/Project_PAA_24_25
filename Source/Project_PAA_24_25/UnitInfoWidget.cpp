#include "UnitInfoWidget.h"
#include "GridPlayerController.h"
#include "TurnBasedGameMode.h"
#include "UnitBase.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"

void UUnitInfoWidget::UpdateUnitInfo(const FString& UnitRole, int32 UnitHealth)
{
    if (UnitRole == TEXT("Player Sniper"))
    {
        if (PSniperName) PSniperName->SetText(FText::FromString("Player Sniper"));
        if (UnitHealth <= 0)
        {
            PSniperHealth->SetText(FText::FromString(TEXT("Eliminated")));
        }
        else
        {
            PSniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
        }
    }
    else if (UnitRole == TEXT("Player Brawler"))
    {
        if (PBrawlerName) PBrawlerName->SetText(FText::FromString("Player Brawler"));
        if (UnitHealth <= 0)
        {
            PBrawlerHealth->SetText(FText::FromString(TEXT("Eliminated")));
        }
        else
        {
            PBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
        }
    }
    else if (UnitRole == TEXT("Enemy Sniper"))
    {
        if (ESniperName) ESniperName->SetText(FText::FromString("AI Sniper"));
        if (UnitHealth <= 0)
        {
            ESniperHealth->SetText(FText::FromString(TEXT("Eliminated")));
        }
        else
        {
            ESniperHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
        }
    }
    else if (UnitRole == TEXT("Enemy Brawler"))
    {
        if (EBrawlerName) EBrawlerName->SetText(FText::FromString("AI Brawler"));
        if (UnitHealth <= 0)
        {
            EBrawlerHealth->SetText(FText::FromString(TEXT("Eliminated")));
        }
        else
        {
            EBrawlerHealth->SetText(FText::FromString(FString::Printf(TEXT("Health: %d"), UnitHealth)));
        }
    }
}

void UUnitInfoWidget::UpdateHistory(const TArray<FString>& History)
{
    if (HistoryScrollBox)
    {
        HistoryScrollBox->ClearChildren();

        for (const FString& Action : History)
        {
            UTextBlock* HistoryText = NewObject<UTextBlock>(HistoryScrollBox);
            HistoryText->SetText(FText::FromString(Action));                        // Set text for action
            HistoryScrollBox->AddChild(HistoryText);                                // Add to ScrollBox
        }
    }
}
