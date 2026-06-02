#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BatteryComponent.h"
#include "SensorComponentBase.generated.h"

class USensorRandomSubsystem;
class USensorInterferenceSubsystem;

UCLASS(Abstract, Blueprintable, ClassGroup=(Sensors))
class SENSORSYSTEM_API USensorComponentBase : public UActorComponent
{
    GENERATED_BODY()

public:

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void SetBatteryComponent(UBatteryComponent* InBattery);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sensor")
    float PowerPerUse = 1.f;

protected:

    UPROPERTY()
    UBatteryComponent* Battery = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SensorSeedOffset = 0;

    FRandomStream LocalStream;

    USensorRandomSubsystem* RandomSubsystem = nullptr;
    USensorInterferenceSubsystem* InterferenceSubsystem = nullptr;

    bool ConsumePower();
};