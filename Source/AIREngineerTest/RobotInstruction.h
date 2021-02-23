// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include"AIReverieRobot.h"
#include "RobotInstruction.generated.h"

/*  */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API URobotInstruction : public UObject
{
	GENERATED_BODY()

public:
	URobotInstruction()
	{}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Instructions")
	bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Instructions")
	bool BeginPlayObject();
	virtual bool BeginPlayObject_Implementation();
};
