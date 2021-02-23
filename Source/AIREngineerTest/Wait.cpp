// Fill out your copyright notice in the Description page of Project Settings.


#include "Wait.h"


bool UWait::BeginPlayObject_Implementation()
{
	mTimer = 0.0f;
	return true;
}

bool UWait::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	if (mTimer <= mTimeToWait)
	{
		mTimer += mDeltaTime;
		return false;
	}
	else
	{
		mTimer = 0.0f;
		return true;
	}

}