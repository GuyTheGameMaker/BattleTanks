// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	LogPossesion();
	GetPlayer();
}

ATank* ATankAIController::GetPossessedAITank()
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::GetPlayer()
{
	FString PlayerName=GetWorld()->GetFirstPlayerController()->GetName();

	{
		AITank = GetPossessedAITank();
		if (AITank)
		{
		FString Name = AITank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI TANK %s FOUND PLAYER TANK: %s"), *Name, *PlayerName)
		}
 }
}

void ATankAIController::LogPossesion()
{
	AITank = GetPossessedAITank();
	if (!AITank)
	{
		FString Name = GetOwner()->GetName();
		UE_LOG(LogTemp, Error, TEXT("NO TANK IN POSSESSION UNDER %s"), *Name)
	}
	else
	{
		FString Name = AITank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("POSSESSING TANK: %s"), *Name)
	}
}
