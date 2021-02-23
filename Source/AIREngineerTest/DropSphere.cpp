// Fill out your copyright notice in the Description page of Project Settings.


#include "DropSphere.h"


bool UDropSphere::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	FVector SphereLocation = Pawn->GetCamera()->GetComponentLocation() + mSphereDistance * Pawn->GetCamera()->GetForwardVector();
	SpawnSphere(SphereLocation, Pawn->GetCamera()->GetComponentRotation());
	return true;
}


void UDropSphere:: SpawnSphere(FVector Location, FRotator Rotation)
{
	//FActorSpawnParameters SpawnInfo;

	AStaticMeshActor* obj = (AStaticMeshActor*)GetWorld()->SpawnActor(AStaticMeshActor::StaticClass(), &Location, &Rotation);

	//AStaticMeshActor* obj = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), Location, Rotation, SpawnInfo);
	obj->SetMobility(EComponentMobility::Movable);
	//UStaticMeshComponent* MyMeshComponent = NewObject<UStaticMeshComponent>(obj, UStaticMeshComponent::StaticClass(), TEXT("Sphere"));

	UStaticMesh* MeshAsset = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("StaticMesh'/Game/SphereMesh.SphereMesh'")));
	UMaterial* MaterialAsset = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/Game/SphereMat.SphereMat'")));

	obj->GetStaticMeshComponent()->SetStaticMesh(MeshAsset);
	obj->GetStaticMeshComponent()->SetMaterial(0, MaterialAsset);
	//obj->GetStaticMeshComponent()->SetWorldLocation(Location);
	//MyMeshComponent->SetIsReplicated(true);
	//obj->GetStaticMeshComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);

	//MyMeshComponent->RegisterComponent();
	//obj->AddOwnedComponent(MyMeshComponent);
	//obj->SetRootComponent(MyMeshComponent);
	obj->Tags.Add(FName("Sphere"));
	//obj->SetActorEnableCollision(true);
	//obj->collisio

}
