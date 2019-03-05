// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	FString Name = GetName();
	//UE_LOG(LogTemp,Warning,TEXT("%s Throttle value: %f"),*Name, Throttle)

	FVector AppliedForce = GetForwardVector() * Throttle * MaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(AppliedForce, ForceLocation, FName("NAME_None"));



}

