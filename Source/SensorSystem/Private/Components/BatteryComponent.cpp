#include "Components/BatteryComponent.h"

bool UBatteryComponent::Consume(float Amount)
{
    if (Battery < Amount)
        return false;

    Battery -= Amount;
    return true;
}