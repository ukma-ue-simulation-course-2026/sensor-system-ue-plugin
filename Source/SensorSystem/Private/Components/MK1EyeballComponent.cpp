// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MK1EyeballComponent.h"
#include "EngineUtils.h"

static TAutoConsoleVariable<bool> CVarFrustumDebugDraw(
        TEXT("Sensors.VisibilityDebugShow"),
        false,
        TEXT("Enable/Disable a line that shows object visibility"),
        ECVF_Default
);

UMK1EyeballComponent::UMK1EyeballComponent() : 
        //values are hardcoded so they are common for everybody
        Frustum(90.0f, 16.f/9.f, 10, 1'000'00)
{
}

void UMK1EyeballComponent::DrawDebugInfo()
{
        Frustum.DrawFrustum(
                GetOwner()->GetWorld(),
                GetOwner()->GetActorLocation(), 
                GetOwner()->GetActorForwardVector(),
                FColor::Red,
                5.0f);
}

bool FFrustum::IsActorInsideFrustum(
        const AActor* Actor,
        const FVector& Location,
        const FVector& Direction)
{
        if (!Actor) return false;

        const FVector Pos = Actor->GetActorLocation();
        const FVector ToPoint = Pos - Location;

        const FVector Forward = Direction.GetSafeNormal();

        // distance check (depth range)
        const float Depth = FVector::DotProduct(ToPoint, Forward);
        if (Depth < NearPlane || Depth > FarPlane)
                return false;

        // basis
        FVector Right = FVector::CrossProduct(FVector::UpVector, Forward).GetSafeNormal();
        if (Right.IsNearlyZero())
                Right = FVector::CrossProduct(FVector::ForwardVector, Forward).GetSafeNormal();

        const FVector Up = FVector::CrossProduct(Forward, Right);

        const float HFOVRad = FMath::DegreesToRadians(HorizontalFOVDeg);
        const float HalfWidth = Depth * FMath::Tan(HFOVRad * 0.5f);
        const float HalfHeight = HalfWidth / AspectRatio;

        const float X = FVector::DotProduct(ToPoint, Right);
        const float Y = FVector::DotProduct(ToPoint, Up);

        return FMath::Abs(X) <= HalfWidth && FMath::Abs(Y) <= HalfHeight;
}

//currently not used
FConvexVolume FFrustum::BuildFrustum(
        const FVector& Origin,
        const FVector& Direction)
{
        const FVector Forward = Direction.GetSafeNormal();

        // Pick a stable up vector (important!)
        FVector Up = FVector::UpVector;
        if (FMath::Abs(FVector::DotProduct(Forward, Up)) > 0.99f)
        {
                Up = FVector::RightVector;
        }

        const FMatrix ViewMatrix = FLookAtMatrix(Origin, Origin + Forward, Up);

        const float HalfHFOV = FMath::DegreesToRadians(HorizontalFOVDeg * 0.5f);

        const float NearWidth = NearPlane * FMath::Tan(HalfHFOV);
        const float NearHeight = NearWidth / AspectRatio;

        const FMatrix ProjMatrix =
                FReversedZPerspectiveMatrix(
                        HalfHFOV * 2.0f,
                        HalfHFOV * 2.0f / AspectRatio,
                        1.0f,
                        NearPlane,
                        FarPlane
                );

        const FMatrix ViewProjMatrix = ViewMatrix * ProjMatrix;

        FConvexVolume Frustum;
        GetViewFrustumBounds(Frustum, ViewProjMatrix, false);

        return Frustum;
}

bool HasLineOfSightBetweenActors(
        UWorld* World,
        AActor* ActorA,
        AActor* ActorB,
        ECollisionChannel TraceChannel = ECC_Visibility)
{
        if (!World || !ActorA || !ActorB)
        {
                return false;
        }

        FVector Start = ActorA->GetActorLocation();
        FVector End = ActorB->GetActorLocation();

        FHitResult Hit;

        FCollisionQueryParams Params;
        Params.AddIgnoredActor(ActorA);
        Params.AddIgnoredActor(ActorB);
        Params.bTraceComplex = false;

        bool bHit = World->LineTraceSingleByChannel(
                Hit,
                Start,
                End,
                TraceChannel,
                Params
        );

        // If we hit something AND it's NOT ActorB -> blocked
        if (bHit)
        {
                return false;
        }

        return true;
}

TArray<AActor*> FFrustum::GetActorsInFrustum(UWorld* World, const FVector& Location, const FVector& Direction)
{
        FConvexVolume Frustum = BuildFrustum(Location, Direction);

        TArray<AActor*> Result;

        for (TActorIterator<AActor> It(World); It; ++It)
        {
                AActor* Actor = *It;
                if (!IsValid(Actor))
                        continue;

                if (!Actor->ActorHasTag(TEXT("Target")))
                {
                        continue;
                }

                const FBox Bounds = Actor->GetComponentsBoundingBox(true);

                //Proper frustm check actualy covers bigger valume - this is a bug that has to be investigated
                //if (Frustum.IntersectBox(Bounds.GetCenter(), Bounds.GetExtent()))
                if (IsActorInsideFrustum(
                        Actor,
                        Location,
                        Direction))
                {
                        Result.Add(Actor);
                }
        }

        return Result;
}

bool UMK1EyeballComponent::IsSomeoneInFrustum()
{
        TArray<AActor*> OutActors;        
        OutActors = Frustum.GetActorsInFrustum(
                GetOwner()->GetWorld(),
                GetOwner()->GetActorLocation(),
                GetOwner()->GetActorForwardVector()
        );

        return !OutActors.IsEmpty();
}

TArray<AActor*> UMK1EyeballComponent::GetTargetsInFrustum()
{
        TArray<AActor*> InFrustumActors = Frustum.GetActorsInFrustum(
                GetOwner()->GetWorld(),
                GetOwner()->GetActorLocation(),
                GetOwner()->GetActorForwardVector());

        TArray<AActor*> ActuallyVisibleActors;
        for (auto Actor : InFrustumActors)
        {
                if (HasLineOfSightBetweenActors(GetOwner()->GetWorld(), GetOwner(), Actor))
                {
                        ActuallyVisibleActors.Add(Actor);

                        if (CVarFrustumDebugDraw.GetValueOnGameThread())
                        {
                                DrawDebugLine(
                                        GetOwner()->GetWorld(),
                                        GetOwner()->GetActorLocation(),
                                        Actor->GetActorLocation(),
                                        FColor::Red,
                                        false,
                                        1.0f,
                                        0,
                                        2.0f
                                );
                        }
                }
        }
    
        return ActuallyVisibleActors;
}

FFrustum::FFrustum(float HorizontalFOVDeg, float AspectRatio, float NearPlane, float FarPlane) : 
        HorizontalFOVDeg(HorizontalFOVDeg),
        AspectRatio(AspectRatio),
        NearPlane(NearPlane),
        FarPlane(FarPlane)
{
}

void FFrustum::DrawFrustum(
        UWorld* World,
        const FVector& Location,
        const FVector& Direction,
        const FColor& Color,
        float Duration)
{
        if (!World) return;

        const FVector Forward = Direction.GetSafeNormal();

        // Build stable basis
        FVector Right = FVector::CrossProduct(FVector::UpVector, Forward).GetSafeNormal();
        if (Right.IsNearlyZero())
        {
                Right = FVector::CrossProduct(FVector::ForwardVector, Forward).GetSafeNormal();
        }

        const FVector Up = FVector::CrossProduct(Forward, Right);

        const float HFOVRad = FMath::DegreesToRadians(HorizontalFOVDeg);
        const float HalfWidthNear = NearPlane * FMath::Tan(HFOVRad * 0.5f);
        const float HalfWidthFar = FarPlane * FMath::Tan(HFOVRad * 0.5f);

        const float HalfHeightNear = HalfWidthNear / AspectRatio;
        const float HalfHeightFar = HalfWidthFar / AspectRatio;

        const FVector NearCenter = Location + Forward * NearPlane;
        const FVector FarCenter = Location + Forward * FarPlane;


        // Near plane corners
        const FVector NearTL = NearCenter + Up * HalfHeightNear - Right * HalfWidthNear;
        const FVector NearTR = NearCenter + Up * HalfHeightNear + Right * HalfWidthNear;
        const FVector NearBL = NearCenter - Up * HalfHeightNear - Right * HalfWidthNear;
        const FVector NearBR = NearCenter - Up * HalfHeightNear + Right * HalfWidthNear;

        // Far plane corners
        const FVector FarTL = FarCenter + Up * HalfHeightFar - Right * HalfWidthFar;
        const FVector FarTR = FarCenter + Up * HalfHeightFar + Right * HalfWidthFar;
        const FVector FarBL = FarCenter - Up * HalfHeightFar - Right * HalfWidthFar;
        const FVector FarBR = FarCenter - Up * HalfHeightFar + Right * HalfWidthFar;

        float Thickness = 10.0f;

        // Draw near plane
        DrawDebugLine(World, NearTL, NearTR, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, NearTR, NearBR, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, NearBR, NearBL, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, NearBL, NearTL, Color, false, Duration, 0, Thickness);

        // Draw far plane
        DrawDebugLine(World, FarTL, FarTR, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, FarTR, FarBR, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, FarBR, FarBL, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, FarBL, FarTL, Color, false, Duration, 0, Thickness);

        // Connect near ↔ far
        DrawDebugLine(World, NearTL, FarTL, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, NearTR, FarTR, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, NearBL, FarBL, Color, false, Duration, 0, Thickness);
        DrawDebugLine(World, NearBR, FarBR, Color, false, Duration, 0, Thickness);
}
