#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LidarVisualizerComponent.generated.h"

class ULidarComponent;

UCLASS(ClassGroup=(Sensors), meta=(BlueprintSpawnableComponent))
class ULidarVisualizerComponent : public UActorComponent
{
    GENERATED_BODY()

public:	
    ULidarVisualizerComponent();

    virtual void BeginPlay();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, Category = "Lidar Debug")
    float PointSize = 8.f;

    UPROPERTY(EditAnywhere, Category = "Lidar Debug")
    FColor HitColor = FColor::Green;

private:
    UPROPERTY()
    ULidarComponent* LidarTarget = nullptr;
};