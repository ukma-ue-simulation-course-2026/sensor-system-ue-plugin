#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SensorInterferenceSubsystem.generated.h"

UCLASS()
class SENSORSYSTEM_API USensorInterferenceSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable)
    float GetInterferenceAtLocation(const FVector& Location) const;
};