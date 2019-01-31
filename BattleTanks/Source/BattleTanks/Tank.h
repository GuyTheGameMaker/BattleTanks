// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UStaticMeshComponent* TurretToSet);

	UPROPERTY(EditAnywhere)
		float LaunchSpeed = 100000;

protected:
	
UTankAimingComponent* TankAimingComponent = nullptr;


private:
	// Sets default values for this pawn's properties
	UStaticMeshComponent* Barrel;
	UStaticMeshComponent* Turret;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
