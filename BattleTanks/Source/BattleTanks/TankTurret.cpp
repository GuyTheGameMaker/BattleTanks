// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::RotateTurret(float RelativeRot)
{
	RelativeRot = FMath::Clamp<float>(RelativeRot, -1, 1);
	float Rotation = RelativeRot * MaxRotationInSeconds *GetWorld()->DeltaTimeSeconds;
	float RawRotation = Rotation + RelativeRotation.Yaw;
	SetRelativeRotation(FRotator(0, RawRotation, 0));

}
