// Fill out your copyright notice in the Description page of Project Settings.


#include "SquadManager.h"

#include "EnvironmentQuery/EnvQueryManager.h"
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

	//FirstNodeQuery->CollectQueryParams()
	//UAITask_RunEQS(agent, FirstNodeQuery);

	//this is the one I think //FEnvQueryRequest

	//FEnvQueryRequest should probably be move outside
	//might not even need this function a should just move this into the main HTN loop
	//or combine the 2 node functions into just one that returns the relevant query
	//
	//FEnvQueryRequest FirstNodeQ = FEnvQueryRequest(FirstNodeQuery, this);
	//FirstNodeQ.Execute(EEnvQueryRunMode::SingleResult, this, &AMyAIController::MoveToQueryResult);

	// if (result->IsSuccsessful()) {
	// 	MoveToLocation(result->GetItemAsLocation(0));
	// }
	
	
	return {};
}

FVector ASquadManager::ChooseSubsequentNode()
{

	
	return {};
}

 