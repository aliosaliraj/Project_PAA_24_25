#include "TurnIndicatorWidget.h"
#include "TurnBasedGameMode.h"
#include "Components/TextBlock.h"
#include "GridPlayerController.h"

void UTurnIndicatorWidget::NativeConstruct()
{
	Super::NativeConstruct();

    GameMode = Cast<ATurnBasedGameMode>(GetWorld()->GetAuthGameMode());

    if (TurnText)
    {
        TurnText->SetVisibility(ESlateVisibility::Hidden);
    }

	if (EndTurnButton)
	{
		EndTurnButton->SetIsEnabled(true);
        bIsCoinFlipPhase = false;
		EndTurnButton->OnClicked.AddDynamic(this, &UTurnIndicatorWidget::OnEndTurnButtonPressed);
	}

    if (EndTurnTextBlock)
    {
        EndTurnTextBlock->SetText(FText::FromString(TEXT("Coin Flip")));
    }

    if (EndGameTextBlock)
    {
        EndGameTextBlock->SetVisibility(ESlateVisibility::Visible);
    }

    if (RandomButton)
    {
        RandomButton->OnClicked.AddDynamic(this, &UTurnIndicatorWidget::OnRandomButtonClicked);
    }

    if (StrategicButton)
    {
        StrategicButton->OnClicked.AddDynamic(this, &UTurnIndicatorWidget::OnStrategicButtonClicked);
    }
}

ESlateVisibility UTurnIndicatorWidget::GetEndTurnButtonVisibility()
{
	if (bIsAIBehaviorPhase) return ESlateVisibility::Hidden;

    if (bIsCoinFlipPhase) return ESlateVisibility::Visible;

	if (GameMode->CurrentTurn == ETurnState::EnemyTurn) return ESlateVisibility::Hidden;

	// Check if all player units have completed their actions
	for (AUnitBase* Unit : GameMode->PlayerUnits)
	{
        if (!Unit->bHasCompletedAction)
        {
			return ESlateVisibility::Hidden;    // If any unit has not completed its action, hide the button
        }
	}
	return ESlateVisibility::Visible;           // If all units have completed their actions, show the button
}

void UTurnIndicatorWidget::OnEndTurnButtonPressed()
{
    if (bIsCoinFlipPhase)
    {
		// When game starts, the player has to click the button to start the coin flip
        GameMode->CoinFlip();

        // Allows the button to change its text into "End Turn" if true
		bIsCoinFlipPhase = false;                                               

        if (EndTurnTextBlock)
        {
			EndTurnTextBlock->SetText(FText::FromString(TEXT("End Turn")));		// Change button text into "End Turn"
        }
    }
    else
    {
        GameMode->EndTurn();                                                    // When the player clicks the button for the first time it will change its logic into the "End Turn" button
    }
}

void UTurnIndicatorWidget::OnRandomButtonClicked()
{
	// Set the AI behavior phase to false and start the coin flip phase
	bIsAIBehaviorPhase = false;
    bIsCoinFlipPhase = true;

    if (EndGameTextBlock)
    {
		EndGameTextBlock->SetVisibility(ESlateVisibility::Hidden);  // hide EndGametextBlock until the game ends
    }

    if (TurnText)
    {
		TurnText->SetVisibility(ESlateVisibility::Visible);		    // now can show the TurnText
    }

	// Set the AI behavior mode to random logic
    GameMode->SetAIBehaviorMode(EAIBehaviorMode::RandomLogic);

    // remove widgets
    RandomButton->RemoveFromParent();
	StrategicButton->RemoveFromParent();
}

void UTurnIndicatorWidget::OnStrategicButtonClicked()
{
	// Set the AI behavior phase to false and start the coin flip phase
	bIsAIBehaviorPhase = false;
    bIsCoinFlipPhase = true;

    if (EndGameTextBlock)
    {
        EndGameTextBlock->SetVisibility(ESlateVisibility::Hidden);  // hide EndGametextBlock until the game ends
    }

    if (TurnText)
    {
		TurnText->SetVisibility(ESlateVisibility::Visible);         // now can show the TurnText
    }

	// Set the AI behavior mode to strategic logic
    GameMode->SetAIBehaviorMode(EAIBehaviorMode::StrategicLogic);

    // remove widgets
    StrategicButton->RemoveFromParent();
	RandomButton->RemoveFromParent();
}

void UTurnIndicatorWidget::SetTurnText(const FString& NewText)
{
	if (TurnText) TurnText->SetText(FText::FromString(NewText));
}

void UTurnIndicatorWidget::SetEndGameText(const FString& EndMessage)
{
    if (EndGameTextBlock)
    {
        EndGameTextBlock->SetText(FText::FromString(EndMessage));
        EndGameTextBlock->SetVisibility(ESlateVisibility::Visible); // Mostra il widget
    }
}