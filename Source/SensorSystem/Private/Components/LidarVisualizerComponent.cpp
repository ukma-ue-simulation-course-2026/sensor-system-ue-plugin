#include "Components/LidarVisualizerComponent.h"
#include "Components/LidarComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"

ULidarVisualizerComponent::ULidarVisualizerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void ULidarVisualizerComponent::BeginPlay()
{
    Super::BeginPlay();
    // UE_LOG(LogTemp, Warning, TEXT("VISUALIZER: Begins existing."));
    // Cache the reference if we don't have it yet
    LidarTarget = GetOwner()->FindComponentByClass<ULidarComponent>();
    if (!LidarTarget)
    {
        UE_LOG(LogTemp, Warning, TEXT("VISUALIZER: Didn't find the LIDAR."));
    }
    LidarTarget->SetContinuousScan(true); // Force enable for testing
}

void ULidarVisualizerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!LidarTarget || !LidarTarget->HasNewData())
    {
        return;
    }

    // Get the latest scan frame
    TArray<FLidarDataPoint> ScanFrame = LidarTarget->GetLatestData();

    // Get the base transform vectors depending on which fix you chose in the last step
    // If you converted Lidar to a SceneComponent, use LidarTarget->GetComponentLocation(), etc.
    FVector StartLocation = GetOwner()->GetActorLocation();
    FVector Forward = GetOwner()->GetActorForwardVector();
    FVector Up = GetOwner()->GetActorUpVector();

    
    for (const FLidarDataPoint& Point : ScanFrame)
    {
        // Only draw actual surfaces, skip misses
        if (!Point.isValidHit) continue;

        // Project the polar data back into a 3D world direction vector
        FVector RayDir = Forward.RotateAngleAxis(Point.Angle, Up);
        FVector WorldHitPos = StartLocation + (RayDir * Point.Distance);

        // Draw the persistent point for exactly one frame lifetime
        DrawDebugPoint(
            GetWorld(),
            WorldHitPos,
            PointSize,
            HitColor,
            false,          // bPersistentLines
            DeltaTime,      // LifeTime matches frame duration to prevent flickering or ghosting
            0               // DepthPriority
        );
    }
}