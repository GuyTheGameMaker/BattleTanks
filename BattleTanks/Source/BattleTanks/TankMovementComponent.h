// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
class UTankTrack;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void InitialiseTracks(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet);

	UFUNCTION(BlueprintCallable)
	void IntentToMove(float Throw);
	UTankTrack* RightTrack = nullptr;
	UTankTrack* LeftTrack = nullptr;

protected:
	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent = nullptr;
};
