// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchZone.h"
#include "SightNode.h"

// Sets default values
ASearchZone::ASearchZone()
{
	const int widthCount = (width/spacing);
	const int heightCount = (height/spacing);
	
	SearchNodesCount = widthCount * heightCount;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ASearchZone::SearchNodeFound()
{
	searchNodesFound += 1;

	if(searchNodesFound >= SearchNodesCount)
	{
		//report to squad manager that the zone is clear
		
	}
	
}

// Called when the game starts or when spawned
void ASearchZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASearchZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

