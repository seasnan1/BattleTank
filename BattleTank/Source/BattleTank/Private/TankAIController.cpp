// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "AIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank)
	{
		//TODO moves towards player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius in cm

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//TODO Fire if ready
		ControlledTank->Fire();
		//Limit fire rate
	}
}

