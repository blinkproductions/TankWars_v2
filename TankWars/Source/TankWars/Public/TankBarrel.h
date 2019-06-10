// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKWARS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.f; // sensible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40.f; // sensible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0.f; // sensible default
};
