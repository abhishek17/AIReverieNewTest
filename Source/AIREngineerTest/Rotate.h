
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "Rotate.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API URotate : public URobotInstruction
{
	GENERATED_BODY()

public:
	URotate()
	{}


	bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn) override;

	//Output getters

	//Input variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mRotationAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mRotationDirection;

protected:

	//Output variables


	//Internal functions

	//Internal variables

};

