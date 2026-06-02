#pragma once

#include "CoreMinimal.h"
#include "Components/SensorComponentBase.h"
#include "GyroscopeComponent.generated.h"

UCLASS(ClassGroup=(Sensors), meta=(BlueprintSpawnableComponent))
class SENSORSYSTEM_API UGyroscopeComponent : public USensorComponentBase
{
    GENERATED_BODY()

public:

    UGyroscopeComponent();

    UFUNCTION(BlueprintCallable)
    void SetMesh(UStaticMeshComponent* InMesh);

    UFUNCTION(BlueprintCallable)
    FVector GetAngularVelocity();    

protected:

    virtual void BeginPlay() override;

private:

    UPROPERTY()
    UStaticMeshComponent* Mesh = nullptr;

    UPROPERTY()
    FVector Bias = FVector::ZeroVector;

    float NoiseStrength = 2.f;
};