#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SensorRandomSubsystem.generated.h"

UCLASS()
class SENSORSYSTEM_API USensorRandomSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MasterSeed = 12345;

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    FRandomStream& GetStream();

private:

    FRandomStream Stream;
};