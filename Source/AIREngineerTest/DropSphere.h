
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "Engine/StaticMeshActor.h"
#include "DropSphere.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UDropSphere : public URobotInstruction
{
	GENERATED_BODY()

public:
	UDropSphere()
	{}


	bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn) override;

	//Output getters

	//Input variables

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mSphereDistance;


protected:

	//Output variables


	//Internal functions
	void SpawnSphere(FVector Location, FRotator Rotation);

	//Internal variables

};

