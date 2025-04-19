// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitInfoWidget.h"
#include "GameFramework/Actor.h"
#include "UnitBase.generated.h"

class UUnitInfoWidget;

UENUM(BlueprintType)
enum class EUnitType : uint8
{
    Sniper UMETA(DisplayName = "Sniper"),
    Brawler UMETA(DisplayName = "Brawler")
};

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
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
    EUnitType UnitType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Control")
    bool bIsPlayerControlled;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Turn")
    bool HasCompletedAction;

    UFUNCTION(BlueprintCallable)
    void ApplyDamage(int32 DamageAmount);

    UFUNCTION(BlueprintCallable)
    void CounterAttack(AUnitBase* Attacker);

    UFUNCTION(BlueprintCallable)
    void UpdateMaterial();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UStaticMeshComponent* UnitMesh;

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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
    UMaterial* SniperPlayerMat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
    UMaterial* SniperEnemyMat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
    UMaterial* BrawlerPlayerMat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
    UMaterial* BrawlerEnemyMat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUnitInfoWidget> UnitInfoWidgetClass;

    UPROPERTY()
    UUnitInfoWidget* UnitInfoWidget;
};