// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::InitialiseTracks(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntentMoveForward(float Throw)
{
<<<<<<< Updated upstream
	UE_LOG(LogTemp, Warning, TEXT("intent to move forward at: %f"), Throw);

=======
	UE_LOG(LogTemp,Warning, TEXT("!!!Moving Forward!!!"))
	RightTrack->SetThrottle(Throw);
>>>>>>> Stashed changes
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);



}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("!!!Moving Sideways!!!"))
	RightTrack->SetThrottle(-Throw);
	LeftTrack->SetThrottle(Throw);
}