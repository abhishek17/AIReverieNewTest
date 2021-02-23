// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotate.h"



bool URotate::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	FRotator NewRotation = FRotator(0.0f, mRotationDirection * mRotationAngle, 0.0f);
	FQuat QuatRotation = FQuat(NewRotation);
	Pawn->GetCamera()->AddLocalRotation(QuatRotation, false, 0, ETeleportType::None);
	return true;
}