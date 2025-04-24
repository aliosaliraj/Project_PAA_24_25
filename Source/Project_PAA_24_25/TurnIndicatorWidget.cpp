// Fill out your copyright notice in the Description page of Project Settings.

#include "TurnIndicatorWidget.h"
#include "TurnBasedGameMode.h"
#include "Components/TextBlock.h"
#include "GridPlayerController.h"

void UTurnIndicatorWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (EndTurnButton)
	{
		EndTurnButton->SetIsEnabled(true);
		EndTurnButton->OnClicked.AddDynamic(this, &UTurnIndicatorWidget::OnEndTurnButtonPressed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EndTurnButton is not set in the widget blueprint!"));
	}
}

ESlateVisibility UTurnIndicatorWidget::GetEndTurnButtonVisibility()
{
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode->CurrentTurn == ETurnState::EnemyTurn) return ESlateVisibility::Hidden;

	// Controlla se tutte le unità hanno completato le loro azioni
	for (AUnitBase* Unit : GameMode->PlayerUnits)
	{
		if (!Unit->bHasCompletedAction)
		{
			return ESlateVisibility::Hidden; // Il bottone non deve essere visibile finché ci sono unità disponibili
		}
	}
	return ESlateVisibility::Visible; // Tutte le unità hanno agito, il bottone può essere mostrato
}

void UTurnIndicatorWidget::OnEndTurnButtonPressed()
{
	ATurnBasedGameMode* GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->EndTurn(); // Passa il turno SOLO quando il player clicca il bottone
		UE_LOG(LogTemp, Warning, TEXT("Player clicked End Turn, switching turn."));
	}
}

void UTurnIndicatorWidget::SetTurnText(const FString& NewText)
{
	InvalidateLayoutAndVolatility();

	if (TurnText)
	{
		TurnText->SetText(FText::FromString(NewText));
		UE_LOG(LogTemp, Warning, TEXT("Turn Text updated"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Turn Text not binded"));
	}
}