// Fill out your copyright notice in the Description page of Project Settings.


#include "SightNode.h"
#include "SearchZone.h"

// Sets default values
ASightNode::ASightNode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
}

// Called when the game starts or when spawned
void ASightNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASightNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ASightNode::Found()
{
	if(!NodeFound)
	{
		NodeFound = true;
		Parent->SearchNodeFound();
		return true;
	}
	
	return false;
}

