// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankTurret.h"
#include"TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::ComponentAimAt(FVector HitLocation, float TossSpeed)
{
	if (!Barrel)	{return;}
	if (!Turret)	{return;}

	TArray<AActor*> ignore;

	ignore.Emplace (GetOwner());
	FVector ProjectileStart = Barrel->GetSocketLocation(FName("MortarSpawn"));
	FVector TossVelocity;
	bool bHaveAimSolution= UGameplayStatics::SuggestProjectileVelocity(
		this, TossVelocity, ProjectileStart,
		HitLocation,
		TossSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		ignore,false);
	if (bHaveAimSolution)
	{
		AimDirection=TossVelocity.GetSafeNormal();
		FRotator AimDirection2 = AimDirection.Rotation();
	MoveBarrel(AimDirection);
	}
	else
	{
		float time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f Failed to find hitlocation"),time)
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{	Barrel = BarrelToSet;  }

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{	Turret = TurretToSet; }

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	//AimAsRotator IS USED BY BOTH
	auto AimAsRotator = AimDirection.Rotation();
	
	//ELEVATING THE BRREL
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto BarrelDeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(BarrelDeltaRotator.Pitch);


	//ROTATING THE TURRET
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto TurretDeltaRotator = AimAsRotator - TurretRotator;

	Turret->RotateTurret(TurretDeltaRotator.Yaw);


//	UE_LOG(LogTemp, Warning, TEXT("AimRotator:  %s"), *DeltaRotator.ToString());
}