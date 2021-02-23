
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.h"
#include "ViewCapture.h"
#include "GameFramework/Actor.h"
#include "DocumentSphere.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API UDocumentSphere : public URobotInstruction
{
	GENERATED_BODY()

public:
	UDocumentSphere();


	bool ExecuteInstruction(AAIReverieRobot* Pawn);
	virtual bool ExecuteInstruction_Implementation(AAIReverieRobot* Pawn) override;

	bool BeginPlayObject();
	virtual bool BeginPlayObject_Implementation() override;

	//Output getters

	//Input variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		AActor *mSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Instructions")
		int32 mSnapshotResolution;

		
protected:

	//Output variables


	//Internal functions
	void CaptureData(AAIReverieRobot *Pawn);
	bool CaptureSnapshot(int32 Resolution, FString Directory, FString Filename, AAIReverieRobot* Pawn);
	void DestroySphere();
	void GetActorsInViewport(TArray<FString>& CurrentlyRenderedActors, FString& CombinedString);
	bool SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText);
	bool CreateDataDirectory(FString SaveDirectory);
	void EnsureCaptureActorReference();

	//Internal variables
	FString	mGameSavedDataDir;
	int mDataCaptureIndex;
	TArray<FString> mActorsInViewport;
	FString mActorsInViewportCombinedString;
	AViewCapture* mSnapshotActor;

};

