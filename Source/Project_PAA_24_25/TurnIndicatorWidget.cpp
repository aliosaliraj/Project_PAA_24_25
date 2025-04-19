// Fill out your copyright notice in the Description page of Project Settings.

#include "TurnIndicatorWidget.h"
#include "Components/TextBlock.h"
#include "GridPlayerController.h"

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