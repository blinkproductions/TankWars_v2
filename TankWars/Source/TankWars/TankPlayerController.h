// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
* Responsible for helping the player aim.
*/

UCLASS()
class TANKWARS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	

	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

protected:
	UFUNCTION(BlueprintCallable, Category = Setup)
	ATank * GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
