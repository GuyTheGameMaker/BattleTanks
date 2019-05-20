// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include"TankTrack.h"

void UTankMovementComponent::InitialiseTracks(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet)
{
	if (!RightTrackToSet || !LeftTrackToSet) { return; }
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}

void UTankMovementComponent::IntentToMove(float Throw)
{
	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(Throw);

}