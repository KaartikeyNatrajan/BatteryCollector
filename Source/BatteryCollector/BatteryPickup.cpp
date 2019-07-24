// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"


// Sets default values for this actor's properties
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);

}

void ABatteryPickup::WasCollected_Implementation()
{
	// use the base pickup function
	Super::WasCollected_Implementation();

	// destroy the pickup
	Destroy();
}