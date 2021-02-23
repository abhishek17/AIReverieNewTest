// Fill out your copyright notice in the Description page of Project Settings.


#include "IsSphereInFront.h"



bool UIsSphereInFront::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	FVector Start = Pawn->GetCamera()->GetComponentLocation();

	FVector ForwardVector = Pawn->GetCamera()->GetForwardVector();
	FVector End = ((ForwardVector * mObstacleDistance) + Start);
	//FCollisionQueryParams CollisionParams;


	FHitResult HitResult;
	// World->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Pawn);
	FCollisionObjectQueryParams ObjectQueryParams(FCollisionObjectQueryParams::AllObjects);
	FCollisionQueryParams QueryParams = FCollisionQueryParams::DefaultQueryParam;
	//QueryParams.AddIgnoredActor(PlayerPawn);

	if (GetWorld()->LineTraceSingleByObjectType(HitResult, Start, End, ObjectQueryParams, QueryParams))
	{
		UE_LOG(LogTemp, Display, TEXT("You are hitting a sphere: %s"), *HitResult.GetActor()->GetName())
		static const FName SphereTag = TEXT("Sphere");
		if (HitResult.GetActor()->ActorHasTag(SphereTag))
		{
			mSphereAhead = HitResult.GetActor();
			return true; //We hit a sphere
		}
	}

	return false;//Nothing in the front
}