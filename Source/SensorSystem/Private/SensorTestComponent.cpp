// Fill out your copyright notice in the Description page of Project Settings.


#include "SensorTestComponent.h"
#include "Engine/Engine.h"

// Sets default values
ASensorTestComponent::ASensorTestComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float ASensorTestComponent::SensorPing(float InputValue)
{
    UE_LOG(LogTemp, Warning, TEXT("SensorPing called with: %f"), InputValue);

    return InputValue * 2.0f;
}

// Called when the game starts or when spawned
void ASensorTestComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("SensorTestComponent initialized"));
	
}

// Called every frame
void ASensorTestComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

