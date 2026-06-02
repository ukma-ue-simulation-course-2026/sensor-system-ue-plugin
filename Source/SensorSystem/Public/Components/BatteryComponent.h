#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BatteryComponent.generated.h"

UCLASS(ClassGroup=(Sensors), meta=(BlueprintSpawnableComponent))
class SENSORSYSTEM_API UBatteryComponent : public UActorComponent
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Battery = 100.f;

    UFUNCTION(BlueprintCallable)
    bool Consume(float Amount);
};