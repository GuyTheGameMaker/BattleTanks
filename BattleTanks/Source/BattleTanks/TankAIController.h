// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	ATank* GetPossessedAITank();
	ATank* PlayerTank;
	void GetPlayer();
	ATank* AITank;
	void LogPossesion();
	ATank* CastPlayerTank();
	void Tick(float DeltaTime) override;

};
