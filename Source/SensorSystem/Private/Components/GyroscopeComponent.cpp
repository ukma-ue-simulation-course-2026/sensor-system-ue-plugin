#include "Components/GyroscopeComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Subsystems/SensorInterferenceSubsystem.h"

UGyroscopeComponent::UGyroscopeComponent()
{
    PowerPerUse = 0.2f;
}

void UGyroscopeComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UGyroscopeComponent::SetMesh(UStaticMeshComponent* InMesh)
{
    Mesh = InMesh;
}

FVector UGyroscopeComponent::GetAngularVelocity()
{
    if (!Mesh)
        return FVector::ZeroVector;

    if (!ConsumePower())
        return FVector::ZeroVector;

    FVector TrueValue = Mesh->GetPhysicsAngularVelocityInDegrees();

    // 3. interference
    float Interference = InterferenceSubsystem
        ? InterferenceSubsystem->GetInterferenceAtLocation(GetOwner()->GetActorLocation())
        : 0.f;

    // 4. deterministic noise
    FVector Noise = FVector(
        LocalStream.FRandRange(-1.f, 1.f),
        LocalStream.FRandRange(-1.f, 1.f),
        LocalStream.FRandRange(-1.f, 1.f)
    ) * NoiseStrength;

    // 5. drift
    Bias += FVector(Interference * 0.01f);

    // 6. final signal
    FVector Result =
        (TrueValue + Noise+ Bias) * (1.f + Interference);

    return Result;
}