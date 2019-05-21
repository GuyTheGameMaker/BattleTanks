// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include"TankTrack.h"

void UTankMovementComponent::InitialiseTracks(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet)
{
	if (!RightTrackToSet || !LeftTrackToSet) { return; }
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}
//please work
void UTankMovementComponent::IntentToMove(float Throw)
{
	UE_LOG(LogTemp,Warning, TEXT("!!!Moving Forward!!!"))
	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(Throw);

}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("!!!Moving Sideways!!!"))
	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(-Throw);
}