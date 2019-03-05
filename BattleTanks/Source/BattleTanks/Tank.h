// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();
	
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UPROPERTY(EditDefaultsOnly)
		float TossSpeed = 100000;

	UPROPERTY(EditDefaultsOnly)
		float ProjectileVelocity = 4000;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> BlueprintProjectile;

	UTankBarrel* Barrel = nullptr;

	UPROPERTY (EditDefaultsOnly)
		float ReloadTime = 3;

	float LastFireTime = 0;

protected:
UTankAimingComponent* TankAimingComponent = nullptr;


private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
