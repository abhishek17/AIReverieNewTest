// Fill out your copyright notice in the Description page of Project Settings.


#include "DocumentSphere.h"
#include "Engine/World.h"



UDocumentSphere::UDocumentSphere()
{
	//Create Saved\Data directory
	FString GameSavedDir = FPaths::ProjectSavedDir();
	mGameSavedDataDir = GameSavedDir + "\\Data";
	CreateDataDirectory(mGameSavedDataDir);
}

bool UDocumentSphere::ExecuteInstruction_Implementation(AAIReverieRobot* Pawn)
{
	CaptureData(Pawn);
	return true;
}


void UDocumentSphere::EnsureCaptureActorReference()
{
	//If not found in the scene, instantiate a new actor
	if (mSnapshotActor == nullptr)
	{
		//Instantiate view capture actor
		FVector Location(0.0f, 0.0f, 89.f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;

		mSnapshotActor = GetWorld()->SpawnActor<AViewCapture>(AViewCapture::StaticClass(), Location, Rotation, SpawnInfo);
	}
}

//This function is responsible for capturing data, including a snapshot and a text file
void UDocumentSphere::CaptureData(AAIReverieRobot* Pawn)
{
	//Increment data capture index
	mDataCaptureIndex++;

	//Click snapshots and save data
	FString DataCaptureBaseName = "image_";
	DataCaptureBaseName += FString::FromInt(mDataCaptureIndex);

	//Capture snapshot
	FString ImageCapturename = DataCaptureBaseName + ".png";
	CaptureSnapshot(mSnapshotResolution, mGameSavedDataDir, ImageCapturename, Pawn);

	//Save Actors
	GetActorsInViewport(mActorsInViewport, mActorsInViewportCombinedString);
	FString TextFileName = DataCaptureBaseName + "_actors.txt";
	SaveStringTextToFile(mGameSavedDataDir, TextFileName, mActorsInViewportCombinedString);
}

bool UDocumentSphere::BeginPlayObject_Implementation()
{
	//Reset the data capture index
	mDataCaptureIndex = 0;
	return true;
}


//This function goes through the scene proxies for all the actors in the scene to compare with the view frustum. After that all the overlapping actors are stored in an array
void UDocumentSphere::GetActorsInViewport(TArray<FString>& CurrentlyRenderedActors, FString& CombinedString)
{
	//reset data arrays
	CurrentlyRenderedActors.Empty();
	CombinedString.Empty();

	//Get the view frustum and see if any primitive collides with it. This helps find out what has not been clipped in rendering
	ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();

	FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
		LocalPlayer->ViewportClient->Viewport,
		GetWorld()->Scene,
		LocalPlayer->ViewportClient->EngineShowFlags)
		.SetRealtimeUpdate(true));

	FVector ViewLocation;
	FRotator ViewRotation;
	FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, /*out*/ ViewLocation, /*out*/ ViewRotation, LocalPlayer->ViewportClient->Viewport);

	bool IsFirstActor = true;
	for (TObjectIterator<UPrimitiveComponent> ScenePrimitsItr; ScenePrimitsItr; ++ScenePrimitsItr)
	{
		// Using the Object iterator so we have to skip objects not in the 
		// relevant world
		if (ScenePrimitsItr->GetWorld() == GetWorld())
		{
			FPrimitiveSceneProxy* Proxy = ScenePrimitsItr->SceneProxy;
			if (Proxy)
			{
				bool bIsShown =
					SceneView->ViewFrustum.IntersectSphere(Proxy->GetBounds().Origin, Proxy->GetBounds().SphereRadius) ||
					SceneView->ViewFrustum.IntersectBox(Proxy->GetBounds().Origin, Proxy->GetBounds().BoxExtent);
				if (bIsShown)
				{
					//If collided, see if the actor that owns this primitive has not been stored
					AActor* OwnerActor = ScenePrimitsItr->GetOwner();
					if (OwnerActor != nullptr)
					{
						if (!CurrentlyRenderedActors.Contains(OwnerActor->GetName()))
						{
							CurrentlyRenderedActors.Add(OwnerActor->GetName());
							if (IsFirstActor)
							{
								CombinedString = OwnerActor->GetName();
								IsFirstActor = false;
							}
							else
							{
								CombinedString += " ";
								CombinedString += OwnerActor->GetName();
							}
						}
					}
				}
			}
		}
	}
}

//This function saves the string containing actors to a file
bool UDocumentSphere::SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText)
{

	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();

	// Directory Exists?
	if (!platformFile.DirectoryExists(*SaveDirectory))
	{
		platformFile.CreateDirectory(*SaveDirectory);
	}
	//still could not make directory?
	if (!platformFile.DirectoryExists(*SaveDirectory))
	{
		//Could not make the specified directory
		return false;
		//~~~~~~~~~~~~~~~~~~~~~~
	}

	//get complete file path
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	return FFileHelper::SaveStringToFile(SaveText, *SaveDirectory);
}

//This function creates the Data folder under the Saved directory, if it does not exist
bool UDocumentSphere::CreateDataDirectory(FString SaveDirectory)
{
	//Create data folder in saved
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	// Directory Exists?
	if (!platformFile.DirectoryExists(*SaveDirectory))
	{
		platformFile.CreateDirectory(*SaveDirectory);
	}
	//still could not make directory?
	if (!platformFile.DirectoryExists(*SaveDirectory))
	{
		//Could not make the specified directory
		return false;
		//~~~~~~~~~~~~~~~~~~~~~~
	}
	return true;
}





void UDocumentSphere::DestroySphere()
{
	if (mSphere != nullptr)
	{
		mSphere->Destroy();
	}
}

//Function to help with capturing snapshots as png files
bool UDocumentSphere::CaptureSnapshot(int32 Resolution, FString Directory, FString Filename, AAIReverieRobot* Pawn)
{
	EnsureCaptureActorReference();
	if (Pawn == nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("No Pawn available"));
		return false;
	}
	//Capture and save the image
	bool SuccessCapture = mSnapshotActor->CapturePlayersView(Resolution, Directory, Filename, Pawn->GetActorLocation(), Pawn->GetActorRotation(), Pawn->GetCamera()->FieldOfView);
	if (SuccessCapture)
	{
		//Call the spawn sphere function, which will be implemented in the blueprints by a child class of snapshot robot
		DestroySphere();
		return true;
	}
	else
	{
		return false;
	}
}


