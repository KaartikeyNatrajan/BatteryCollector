// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Return the mesh for the pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; };

	// Return whether or not the pickup is active
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	// Allow changing the state of the pickup
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

	// runs when the pickup gets collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();

	virtual void WasCollected_Implementation();

protected:
	// holds current state of the pickup. True if active
	bool bIsActive;

private:
	// static mesh to represent the pickup in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
	
};
