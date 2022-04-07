// Fill out your copyright notice in the Description page of Project Settings.


#include "SquadManager.h"

#include "Tasks/AITask_RunEQS.h"


// Sets default values
ASquadManager::ASquadManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASquadManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquadManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector ASquadManager::ChooseFirstNode()
{


	
	return {};
}

FVector ASquadManager::ChooseSubsequentNode()
{

	
	return {};
}

 