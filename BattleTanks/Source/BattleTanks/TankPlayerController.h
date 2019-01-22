// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"
#define OUT
/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
	void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	void AimAtCrosshairs();
	FVector HitLocation;
	bool GetSightRayHitLocation(FVector& HitLocation) const;

private:
	UPROPERTY(EditAnywhere)
	float CrosshairsXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairsYLocation = 0.33333;

	FHitResult Hit;
	float TraceRange = 1000000;
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
	bool GetLookVectorHitLocation(FVector&LookDirection, FVector &HitLocaition) const;

};
