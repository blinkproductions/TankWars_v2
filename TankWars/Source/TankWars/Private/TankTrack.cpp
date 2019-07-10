// Fill out your copyright notice in the Description page of Project Settings.
#include "TankTrack.h"
#include "Public/SprungWheel.h"
#include "Public/SpawnPoint.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children) 
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SprunWheel = Cast<ASprungWheel>(SpawnedChild);
		if (!SprunWheel) continue;
		
		ResultArray.Add(SprunWheel);
	}
	return ResultArray;
}

void UTankTrack::SetThrottle(float Throttle) 
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1.0f, 1.0f);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num(); // divided by the number of wheels we have

	for (ASprungWheel* Wheel : Wheels) 
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}