// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchZone.h"
#include "SightNode.h"
#include "../Agent/SquadManager.h"

// Sets default values
ASearchZone::ASearchZone()
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ASearchZone::SearchNodeFound() const
{
	if(IsCleared())
	{
		squadManager->GoToNextZone();
	}
}

// Called when the game starts or when spawned
void ASearchZone::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ASearchZone::IsCleared() const
{
	return NodeCount <= 0;
}

// Called every frame
void ASearchZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}





