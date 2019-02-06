// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::RotateTurret(float RelativeRot)
{
	float Rotation = RelativeRot * MaxRotationInSeconds*GetWorld()->DeltaTimeSeconds;
	float RawRotation = Rotation + RelativeRotation.Yaw;
	SetRelativeRotation(FRotator(0, RawRotation, 0));
	UE_LOG(LogTemp, Warning, TEXT("Rotating by %f"), RawRotation)
}
