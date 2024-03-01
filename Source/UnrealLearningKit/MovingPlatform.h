// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
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

	UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(0, 0, 0);

	FVector StartPosition;

	UPROPERTY(EditAnywhere)
	float MovementRange = 1000.0;

	UPROPERTY(EditAnywhere)
	int32 MovementSpeed = 1;

	UPROPERTY(EditAnywhere)
	int32 MovementDirection = 0;

	FVector PlatformVelocity = FVector(MovementSpeed, 0, 0);

};
