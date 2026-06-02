#include "Components/SensorComponentBase.h"
#include "Subsystems/SensorRandomSubsystem.h"
#include "Subsystems/SensorInterferenceSubsystem.h"

void USensorComponentBase::BeginPlay()
{
    Super::BeginPlay();

    RandomSubsystem = GetWorld()->GetSubsystem<USensorRandomSubsystem>();
    InterferenceSubsystem = GetWorld()->GetSubsystem<USensorInterferenceSubsystem>();

    if (RandomSubsystem)
    {
        LocalStream.Initialize(RandomSubsystem->MasterSeed + SensorSeedOffset);
    }
}

void USensorComponentBase::SetBatteryComponent(UBatteryComponent* InBattery)
{
    Battery = InBattery;
}

bool USensorComponentBase::ConsumePower()
{
    if (!Battery) return false;
    return Battery->Consume(PowerPerUse);
}
