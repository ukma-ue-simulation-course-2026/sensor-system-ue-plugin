#pragma once

#include "CoreMinimal.h"
#include "Components/SensorComponentBase.h"
#include "LidarComponent.generated.h"

USTRUCT(BlueprintType)
struct FLidarDataPoint
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Lidar")
    float Angle = 0.f;

    UPROPERTY(BlueprintReadOnly, Category="Lidar")
    float Distance = 0.f;

    UPROPERTY(BlueprintReadOnly, Category="Lidar")
    bool isValidHit = false;
};

UCLASS(ClassGroup=(Sensors), meta=(BlueprintSpawnableComponent))
class SENSORSYSTEM_API ULidarComponent : public USensorComponentBase
{
    GENERATED_BODY()

public:

    ULidarComponent();

    virtual void BeginPlay();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // +- x centimeters
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lidar")
    float NoiseStrength = 5.f;

    // in centimeters
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lidar")
    float MaxRange = 5000.f;

    // revolutions per second
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lidar")
    float RPS = 10.f;

    // points per revolution
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lidar")
    int32 PPR = 360;

    UFUNCTION(BlueprintCallable, Category="Lidar")
    void ScanOnce();

    UFUNCTION(BlueprintCallable, Category="Lidar")
    void SetContinuousScan(bool enabled);

    UFUNCTION(BlueprintCallable, Category="Lidar")
    bool HasNewData() const;

    UFUNCTION(BlueprintCallable, Category="Lidar")
    TArray<FLidarDataPoint> GetLatestData();

private:

    TArray<FLidarDataPoint> LatestData;
    bool hasNewData = false;
    bool bContinuousScan = false;
    float TimeSinceLastScan = 0.f;
};