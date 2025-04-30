#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CellActor.generated.h"

UCLASS()
class PROJECT_PAA_24_25_API ACellActor : public AActor
{
	GENERATED_BODY()

public:
	ACellActor();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* CellMesh;

	UFUNCTION(BlueprintCallable)
	void HighlightCell(bool bHighlight);

	UFUNCTION(BlueprintCallable)
	void SetCellColor(FLinearColor NewColor);

	void ResetToOriginalColor();

private:
	FLinearColor OriginalColor;
};