
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "Wait.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UWait : public URobotInstruction
{
	GENERATED_BODY()

public:
	UWait()
	{}


	bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn) override;

	bool BeginPlayObject();
	virtual bool BeginPlayObject_Implementation() override;

	//Input variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mTimeToWait;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mDeltaTime;

protected:

	//Output variables


	//Internal functions

	//Internal variables
	float mTimer;

};

