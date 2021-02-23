// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveForward.h"


bool UMoveForward::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	Pawn->SetActorLocation(Pawn->GetActorLocation() + Pawn->GetCamera()->GetForwardVector() * mMoveDistance);
	return true;
}