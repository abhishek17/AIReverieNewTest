
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "CalculateRandomAngle.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UCalculateRandomAngle : public URobotInstruction
{
	GENERATED_BODY()

public:
	UCalculateRandomAngle()
	{}


	bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn) override;


	//Output getters
	UFUNCTION(BlueprintCallable, Category = "Instructions")
	float GetRandomAngle()
	{
		return mRandomAngle;
	}

	UFUNCTION(BlueprintCallable, Category = "Instructions")
		float GetRandomDirection()
	{
		return mRandomDirection;
	}

	//Input vars
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mMinAngle;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mMaxAngle;

protected:
	//Output vars
	float mRandomAngle;
	float mRandomDirection;

	//Internal functions
	float GetRandomNumber(float Min, float Max);
	int GetRandomNumber(int32 Min, int32 Max);

	

};

