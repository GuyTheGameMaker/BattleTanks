// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankTrack.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
<<<<<<< Updated upstream
=======
//class UTankTrack;
>>>>>>> Stashed changes
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable)
		void IntentMoveForward(float Throw);

<<<<<<< Updated upstream
		UFUNCTION(BlueprintCallable)
			void InitialiseTracks(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

		UTankTrack* LeftTrack = nullptr;
		UTankTrack* RightTrack = nullptr;


	
=======
	UFUNCTION(BlueprintCallable)
	void IntentToMove(float Throw);

	UFUNCTION(BlueprintCallable)
		void IntendMoveRight(float Throw);

	UTankTrack* RightTrack = nullptr;
	UTankTrack* LeftTrack = nullptr;

	//protected:
	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent = nullptr;


>>>>>>> Stashed changes
};
