// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTurret.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{

	bool bIsReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTime);
	if (Barrel && bIsReloaded)
	{
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			BlueprintProjectile,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			//,FActorSpawnParameters()
			);
		LastFireTime = FPlatformTime::Seconds();
		Projectile->FireProjectile(ProjectileVelocity);
	}
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->ComponentAimAt(HitLocation,TossSpeed );
}