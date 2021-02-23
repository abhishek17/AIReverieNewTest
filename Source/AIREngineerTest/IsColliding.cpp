// Fill out your copyright notice in the Description page of Project Settings.


#include "IsColliding.h"



bool UIsColliding::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	FHitResult OutHit;
	FVector Start = Pawn->GetCamera()->GetComponentLocation();

	FVector ForwardVector = Pawn->GetCamera()->GetForwardVector();
	FVector End = ((ForwardVector * mObstacleDistance) + Start);
	FCollisionQueryParams CollisionParams;

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
	{
		if (OutHit.bBlockingHit)
		{
			UE_LOG(LogTemp, Display, TEXT("You are hitting: %s"), *OutHit.GetActor()->GetName());
			return true; //We hit something
		}
	}
	return false;//Nothing in the front
}