// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculateRandomAngle.h"


bool UCalculateRandomAngle::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	int32 Direction = GetRandomNumber(0, 1);
	Direction == 1 ? mRandomDirection = 1.0f : -1.0f;
	mRandomAngle = GetRandomNumber(mMinAngle, mMaxAngle);

	return true;
}

//Function to generate a random float
float UCalculateRandomAngle::GetRandomNumber(float Min, float Max)
{
	int32 seed = (int32)(FDateTime::Now().GetTicks() % INT_MAX);
	return FMath::FRandRange(Min, Max);
}

//Function to generate a random integer
int UCalculateRandomAngle::GetRandomNumber(int32 Min, int32 Max)
{
	int32 seed = (int32)(FDateTime::Now().GetTicks() % INT_MAX);
	return FMath::RandRange(Min, Max);
}