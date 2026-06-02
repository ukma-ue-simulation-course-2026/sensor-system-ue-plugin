#include "Subsystems/SensorRandomSubsystem.h"

void USensorRandomSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    Stream.Initialize(MasterSeed);
}

FRandomStream& USensorRandomSubsystem::GetStream()
{
    return Stream;
}