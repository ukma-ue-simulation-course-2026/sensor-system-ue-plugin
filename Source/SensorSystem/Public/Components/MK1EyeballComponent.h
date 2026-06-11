// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SensorComponentBase.h"
#include "MK1EyeballComponent.generated.h"

struct FFrustum
{
	FFrustum() = default;

	FFrustum(float HorizontalFOVDeg,
		float AspectRatio,
		float NearPlane,
		float FarPlane);

	void DrawFrustum(
		UWorld* World,
		const FVector& Location,
		const FVector& Direction,
		const FColor& Color,
		float Duration = 0.f);

	TArray<AActor*> GetActorsInFrustum(
		UWorld* World,
		const FVector& Location,
		const FVector& Direction);

private:
	FConvexVolume BuildFrustum(
		const FVector& Origin,
		const FVector& Direction);

	bool IsActorInsideFrustum(
		const AActor* Actor,
		const FVector& Location,
		const FVector& Direction);

	float HorizontalFOVDeg;
	float AspectRatio;
	float NearPlane;
	float FarPlane;
};

/**
 * 
 */
UCLASS(ClassGroup = (Sensors), meta = (BlueprintSpawnableComponent))
class SENSORSYSTEM_API UMK1EyeballComponent : public USensorComponentBase
{
	GENERATED_BODY()
	
public:
	UMK1EyeballComponent();

	UFUNCTION(BlueprintCallable)
	void DrawDebugInfo();

	UFUNCTION(BlueprintCallable)
	bool IsSomeoneInFrustum();

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetTargetsInFrustum();

private:
	FFrustum Frustum;
};
