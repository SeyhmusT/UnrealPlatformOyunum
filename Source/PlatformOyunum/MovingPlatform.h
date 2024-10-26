// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PLATFORMOYUNUM_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	private:

    UPROPERTY(EditAnywhere, Category = "Moving")
	FVector platformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Moving")
	float moveDistance = 100;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator rotationVelocity;

	
	FVector startLocation;

    void movePlatform(float DeltaTime);
	void rotatePlatform(float DeltaTime);
	bool shouldPlatformReturn() const;
	float GetDistanceMoved() const;



};
