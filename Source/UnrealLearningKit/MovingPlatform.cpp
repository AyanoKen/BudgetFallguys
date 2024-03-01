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

	switch (MovementDirection)
	{
	case 1:
		PlatformVelocity = FVector(0, MovementSpeed, 0);
		break;

	case 2:
		PlatformVelocity = FVector(0, 0, MovementSpeed);
		break;
	
	default:
		PlatformVelocity = FVector(MovementSpeed, 0, 0);
		break;
	}
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentPosition = GetActorLocation();

	CurrentPosition = CurrentPosition + PlatformVelocity * DeltaTime;
	SetActorLocation(CurrentPosition);

	float DistMoved = FVector::Dist(StartPosition, CurrentPosition);

	// if(CurrentPosition.X > StartPosition.X + MovementRange){
	// 	MovementSpeed = MovementSpeed * (-1);
	// }

	// if(CurrentPosition.X < StartPosition.X){
	// 	MovementSpeed = MovementSpeed * (-1);
	// }

	if(DistMoved > MovementRange){
		FVector CurrentDirection = PlatformVelocity.GetSafeNormal();
		StartPosition = StartPosition + CurrentDirection * MovementRange;
		SetActorLocation(StartPosition);
		PlatformVelocity = -PlatformVelocity;
	}
}

