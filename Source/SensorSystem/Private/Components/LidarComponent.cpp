#include "LidarComponent.h"
#include "Subsystems/SensorInterferenceSubsystem.h"
#include "Engine/World.h"

ULidarComponent::ULidarComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PowerPerUse = 1.0f;
}

void ULidarComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bContinuousScan)
    {
        return;
    }

    TimeSinceLastScan += DeltaTime;
    
    float ScanPeriod = 1.f / FMath::Max(0.0001f, RPS);

    if (TimeSinceLastScan >= ScanPeriod)
    {
        ScanOnce();
        TimeSinceLastScan = FMath::Fmod(TimeSinceLastScan, ScanPeriod);
    }
}

void ULidarComponent::SetContinuousScan(bool bEnable)
{
    bContinuousScan = bEnable;
    if (bContinuousScan)
    {
        TimeSinceLastScan = 0.f;
    }
}

bool ULidarComponent::HasNewData() const
{
    return bHasNewData;
}

TArray<FLidarDataPoint> ULidarComponent::GetLatestData()
{
    bHasNewData = false;
    return LatestData;
}

void ULidarComponent::ScanOnce()
{
    if (!ConsumePower())
    {
        return;
    }

    LatestData.Empty(PPR);
    bHasNewData = true;

    float Interference = InterferenceSubsystem
        ? InterferenceSubsystem->GetInterferenceAtLocation(GetOwner()->GetActorLocation())
        : 0.f;

    FVector StartLocation = GetComponentLocation();
    FVector Forward = GetForwardVector();
    FVector Up = GetUpVector();

    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(GetOwner());

    float AngleStep = 360.f / FMath::Max(1, PPR);

    for (int32 i = 0; i < PPR; i++)
    {
        float CurrentAngle = AngleStep * i;
        FVector RayDir = Forward.RotateAngleAxis(CurrentAngle, Up);
        FVector EndLocation = StartLocation + (RayDir * MaxRange);

        FHitResult Hit;
        bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECC_Visibility, QueryParams);

        FLidarDataPoint Point;
        Point.Angle = CurrentAngle;
        Point.isValidHit = bHit;

        if (bHit)
        {
            float TrueDistance = Hit.Distance; 
            float Noise = LocalStream.FRandRange(-NoiseStrength, NoiseStrength);
            float TotalError = Noise * (1.f + Interference);
            
            Point.Distance = FMath::Clamp(TrueDistance + TotalError, 0.f, MaxRange);
        }
        else
        {
            Point.Distance = MaxRange;
        }

        LatestData.Add(Point);
    }
}