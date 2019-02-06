// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -2, 2);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond *GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float ClampedElevation= FMath::Clamp<float>(RawNewElevation,MinElevationInDegrees, MaxElevationInDegrees );
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
	UE_LOG(LogTemp, Warning, TEXT("elevating by %f"), ClampedElevation)

}