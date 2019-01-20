// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
		
	{
	FString Name = GetControlledTank()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("PLAYER HAS POSSESSED THE TANK %s"),*Name) 
	}
	
	else 
	{UE_LOG(LogTemp, Warning, TEXT("FAILED TO POSSESS THE TANK")) }

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
