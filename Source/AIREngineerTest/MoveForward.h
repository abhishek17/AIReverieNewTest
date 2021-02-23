// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "MoveForward.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UMoveForward : public URobotInstruction
{
	GENERATED_BODY()

public:
	UMoveForward()
	{}

	
		bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn) override;

	//Output getters

	//Input variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mMoveDistance;

protected:

	//Output variables


	//Internal functions

	//Internal variables
	
};
