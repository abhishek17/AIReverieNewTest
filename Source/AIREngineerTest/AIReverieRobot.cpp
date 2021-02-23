// Fill out your copyright notice in the Description page of Project Settings.


#include "AIReverieRobot.h"



AAIReverieRobot::AAIReverieRobot()
{
	//Create components
	mMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	mCamera = CreateDefaultSubobject<UCameraComponent>("Camera");

	//Set up component heirarchy 
	RootComponent = mMesh;
	mCamera->SetupAttachment(mMesh);

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIReverieRobot::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void AAIReverieRobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAIReverieRobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

