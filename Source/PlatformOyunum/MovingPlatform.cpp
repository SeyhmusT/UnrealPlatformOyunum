// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
     Super::BeginPlay();

    startLocation = GetActorLocation();


}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	movePlatform(DeltaTime);
	rotatePlatform(DeltaTime);
    

}


void AMovingPlatform::movePlatform(float DeltaTime)
{
        if(shouldPlatformReturn())
		{
		FVector MoveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDistance*MoveDirection;
		SetActorLocation(startLocation);
        platformVelocity = -platformVelocity;
		}
		else
		{
        FVector currentLocation = GetActorLocation(); 		
		currentLocation = currentLocation + (platformVelocity * DeltaTime);		
		SetActorLocation(currentLocation);
		}
}

void AMovingPlatform::rotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(rotationVelocity * DeltaTime);

}

bool AMovingPlatform::shouldPlatformReturn() const
{
	
	return GetDistanceMoved() > moveDistance;

}

float AMovingPlatform::GetDistanceMoved() const
{
	float distance = FVector::Dist(startLocation, GetActorLocation());
	return distance;
}


