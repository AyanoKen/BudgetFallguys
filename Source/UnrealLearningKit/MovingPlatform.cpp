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
	
	StartPosition = GetActorLocation();
	CurrentPosition = StartPosition;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentPosition.X += MovementSpeed;

	if(CurrentPosition.X > StartPosition.X + MovementRange){
		MovementSpeed = MovementSpeed * (-1);
	}

	if(CurrentPosition.X < StartPosition.X){
		MovementSpeed = MovementSpeed * (-1);
	}

	SetActorLocation(CurrentPosition);

}

