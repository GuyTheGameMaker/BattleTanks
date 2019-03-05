// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AITank = Cast<ATank>(GetPawn());
	PlayerTank= Cast<ATank> (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank&&AITank)
	{
		AITank->AimAt(PlayerTank->GetActorLocation());

		AITank->Fire();
	}



}

