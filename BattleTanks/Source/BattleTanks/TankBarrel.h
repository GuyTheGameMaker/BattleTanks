// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed);

	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 20;//TODO understand what does this do.

	UPROPERTY(EditAnywhere)
		float MaxElevationInDegrees = 40;

	UPROPERTY(EditAnywhere)
		float MinElevationInDegrees = 0;
};
