// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Returns WhereToSpawn subObject
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	// Find a random point in the box component
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

protected:
	// The pickup to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	// no UPROPERTY here becuase FTimers cant have them
	FTimerHandle SpawnTimer;

	// minimum spawn delay
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	// maximum spawn delay
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

private:
	// Box component to specify where pickups should be spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	
	// handle spawning a new pickup
	void SpawnPickup();

	// the current spawn delay
	float SpawnDelay;
};
