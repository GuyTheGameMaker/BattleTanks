// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

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

	// ...
}

void UTankAimingComponent::ComponentAimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel)
	{return;}
	if (!Turret)
	{return;}

	TArray<AActor*> ignore;
	FVector ProjectileStart = Barrel->GetComponentLocation();
	FVector TossVelocity;
	bool bHaveAimSolution= UGameplayStatics::SuggestProjectileVelocity(
		this, TossVelocity, ProjectileStart,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,FCollisionResponseParams::DefaultResponseParam,ignore,false);
	
	if (bHaveAimSolution)
	{
		AimDirection=TossVelocity.GetSafeNormal();
		FRotator AimDirection2 = AimDirection.Rotation();
		UE_LOG(LogTemp, Warning, TEXT("Hitting  %s"), *AimDirection2.ToString());
	MoveBarrel(AimDirection);
	}
	else
	{

	}
	
		//FRotator AimDirection2 = AimDirection.Rotation();
		//UE_LOG(LogTemp, Warning, TEXT("NOT Hitting  %s"), *AimDirection2.ToString());

}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;

}

void UTankAimingComponent::SetTurretReference(UStaticMeshComponent * TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	//convert the vector into a rotator
	//set turrets yaw rotation to aimdirection yaw
	//set barrel pitch rotation to aimdirection pitch
	FRotator AimDirection2 = AimDirection.Rotation();
	Turret->SetWorldRotation(FRotator(0, AimDirection2.Yaw,0 ));
	FRotator wipi = Turret->GetComponentRotation();
	Barrel->SetWorldRotation(FRotator(AimDirection2.Pitch,wipi.Yaw,wipi.Roll));


	//ben take
	//auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	//auto AimAsRotator = AimDirection.Rotation();
	//auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("AimRotator:  %s"), *DeltaRotator.ToString());
}