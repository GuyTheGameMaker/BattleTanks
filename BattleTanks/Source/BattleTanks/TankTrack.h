// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)
	float MaxDrivingForce = 600000; //Max Driving force in newtons, assuming tank weighs 60 tons.
};
