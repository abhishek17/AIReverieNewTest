#pragma once

#include "CoreMinimal.h"
#include "ViewCapture.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "AIReverieRobot.generated.h"

/*
This class serves as the base class for setting up pawns that go around an environment
to capture scene data. The class has two main components: a static mesh, and
a camera. The camera component is used as the point of view and to click snapshots
*/
UCLASS(Blueprintable)
class AIRENGINEERTEST_API AAIReverieRobot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAIReverieRobot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Root comp")
		UStaticMeshComponent* mMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* mCamera;

	//View capture actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Snapshot")
		AViewCapture* mSnapshotActor;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input; Overriding it and keeping it empty so that inputs can`t move this robot pawn.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Ensure existance of the capture actor
	void EnsureCaptureActorReference();
	
	//Output getters
	UFUNCTION(BlueprintCallable, Category = "Instructions")
		AViewCapture* GetViewCapture()
	{
		EnsureCaptureActorReference();
		return mSnapshotActor;
	}

	UFUNCTION(BlueprintCallable, Category = "Instructions")
		UCameraComponent* GetCamera()
	{
		return mCamera;
	}
};
