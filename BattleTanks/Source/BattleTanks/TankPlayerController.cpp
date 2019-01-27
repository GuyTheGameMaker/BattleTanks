// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
		

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshairs();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshairs()
{
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("NO TANK"))
		return;
	}
	FVector HitLocation; //OUT parameter. GetSightRayHitLocation() is going to rewrite this.
	if  (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"),*(HitLocation.ToString()))
	}
	
	GetControlledTank()->AimAt(HitLocation);
	//get world location if linetrace through crosshairs
	//if it hits terrain
	//aim at that location
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//1.make a vector from turret to crosshair:
	//Get Viewpoint rotation and location.
	//an additional vector from crosshair to whatever its pointing at:
	//the rotation used is the viewport rotation.
	//linetrace using both vectors to and check whether its hitting terrain.
	//if it hits the terrain, update HitLocation with the location of the hit.
	//and return true.
	//else return false.


	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize
		(ViewportSizeX,
		ViewportSizeY);

	auto ScreenLocation = FVector2D(
		ViewportSizeX * CrosshairsXLocation,
		ViewportSizeY * CrosshairsYLocation);



	FVector LookDirection; 
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		if (GetLookVectorHitLocation(LookDirection, HitLocation))
		{	UE_LOG(LogTemp, Warning, TEXT("world Location : %s"), *HitLocation.ToString()) }
	
		}

	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector CameraWorldLocation;  //TO BE DISCARDED LATER
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	OUT FHitResult Hit;
	TArray <FHitResult> Hits;

	FVector LineTraceStart = PlayerCameraManager->GetCameraLocation();
	FVector LineTraceEnd = LineTraceStart + (LookDirection*TraceRange);
	
	//	FVector TankRotation = GetControlledTank()->GetActorRotation().Vector();
//	FVector LineTraceEnd = TankRotation * TraceRange;

	if (GetWorld()->LineTraceSingleByChannel(
		Hit,
		LineTraceStart,
		LineTraceEnd,
		ECollisionChannel(ECC_Visibility),
		FCollisionQueryParams(NAME_None,false,this) 
		))
	{
		HitLocation = Hit.Location; 
		return true;
	}
	HitLocation = FVector(0);
	return false;



}

//UE_LOG(LogTemp,Warning,TEXT(""))