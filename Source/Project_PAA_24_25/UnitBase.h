// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitInfoWidget.h"
#include "GameFramework/Actor.h"
#include "UnitBase.generated.h"

class UUnitInfoWidget;

UCLASS()
class PROJECT_PAA_24_25_API AUnitBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnitBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UStaticMeshComponent* UnitMesh;

	// Stats Base
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 MaxMovement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 AttackRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 DamageMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 DamageMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 CurrentDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Control")
    bool bIsPlayerControlled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UUnitInfoWidget> UnitInfoWidgetClass;

    UPROPERTY()
    UUnitInfoWidget* UnitInfoWidget;

    UFUNCTION(BlueprintCallable)
    void ApplyDamage(int32 DamageAmount);

	UFUNCTION(BlueprintCallable)
	void AttackTarget(AUnitBase* Target);
};
