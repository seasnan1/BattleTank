// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "AIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT(" AI can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" AI found player tank: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO moves towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//TODO Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const	
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) 
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);

}