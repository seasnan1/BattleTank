// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrack || !RightTrack)
	{
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	}
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//prevent double speed due to double inputs
}

//void UTankMovementComponent::IntendMoveBackward(float Throw)
//{
	//LeftTrack->SetThrottle(-Throw);
	//RightTrack->SetThrottle(-Throw);
//}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

//void UTankMovementComponent::IntendTurnLeft(float Throw)
//{
	//LeftTrack->SetThrottle(-Throw);
	//RightTrack->SetThrottle(Throw);
//}

