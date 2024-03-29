// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
 
#include "TankAIController.generated.h"

UCLASS()
class TANKWARS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close the AI tank can get to the player
	UPROPERTY(EditDefaultsOnly, Category = Setup) 
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetPawn(APawn* InPawn) override;	

	UFUNCTION()
	void OnPossessedTankDeath();
};
