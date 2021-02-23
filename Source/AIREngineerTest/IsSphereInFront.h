#pragma once


#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "Engine/StaticMeshActor.h"
#include "IsSphereInFront.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UIsSphereInFront : public URobotInstruction
{
	GENERATED_BODY()

public:
	UIsSphereInFront()
	{}


	bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn) override;


	//Output getters
	UFUNCTION(BlueprintCallable, Category = "Instructions")
	AActor* GetSphereInFront()
	{
		return mSphereAhead;
	}

	//Input variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		float mObstacleDistance;

protected:

	//Output variables
	AActor* mSphereAhead;

	//Internal functions

	//Internal variables

};