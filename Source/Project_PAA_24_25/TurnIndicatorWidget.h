#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
class ATurnBasedGameMode;
#include "TurnIndicatorWidget.generated.h"



UCLASS()
class PROJECT_PAA_24_25_API UTurnIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UTurnIndicatorWidget> TurnIndicatorWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TurnText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* EndTurnButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* EndTurnTextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* EndGameTextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* RandomButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* StrategicButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	bool bIsCoinFlipPhase = false;						// Indicates if is the Coin Flip phase

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	bool bIsAIBehaviorPhase = true;						// Indicates if is the AI Behavior phase

	UFUNCTION(BlueprintCallable, Category = "UI")
	ESlateVisibility GetEndTurnButtonVisibility();		// Returns the visibility of the End Turn button

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnEndTurnButtonPressed();						// Called when the End Turn button is pressed

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnRandomButtonClicked();						// Called when the Random button is clicked

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnStrategicButtonClicked();					// Called when the Strategic button is clicked

	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetTurnText(const FString& NewText);			// Sets the turn text

	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetEndGameText(const FString& NewText);		// Sets the end game text

private:
	ATurnBasedGameMode* GameMode;
};