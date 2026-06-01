// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SensorTestComponent.generated.h"

UCLASS(ClassGroup=(Sensors), meta=(BlueprintSpawnableComponent))
class SENSORSYSTEM_API ASensorTestComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASensorTestComponent();
	
	UFUNCTION(BlueprintCallable, Category="SensorSystem|Debug")
    static float SensorPing(float InputValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
