// Fill out your copyright notice in the Description page of Project Settings.


#include "SquadManager.h"

#include "EnvironmentQuery/EnvQueryManager.h"
#include "Tasks/AITask_RunEQS.h"
#include "Containers/Array.h"



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
	FEnvQueryRequest QueryRequest = FEnvQueryRequest(ZoneQuery, this);
	QueryRequest.Execute(EEnvQueryRunMode::SingleResult, this, &ASquadManager::ZoneQueryFinished);
	
	
}

void ASquadManager::ZoneQueryFinished(TSharedPtr<FEnvQueryResult> Result)
{
	FVector ZonePosition = Result->GetItemAsLocation(0);
	for(AAgent* agent : agents )
	{
		agent->SetTarget(ZonePosition);
		agent->SetTask(ETasks::MoveToZone);
	}
}



// Called every frame
void ASquadManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ASquadManager::EnteredFirstZone(ASearchZone* zone, AAgent* agent)
{
	if(CurrentZone == nullptr)
	{
		CurrentZone = zone;
		CurrentWorldState = EWorldState::ZoneUncleared;
	}

	if((agent->CurrentTask == ETasks::Wait || agent->CurrentTask == ETasks::MoveToZone) && (agent->CurrentZone == CurrentZone))
	{
		FEnvQueryRequest QueryRequest = FEnvQueryRequest(FirstNodeQuery, this);
		QueryRequest.Execute(EEnvQueryRunMode::SingleResult, agent, &AAgent::NodeQueryFinished);
	}
}

void ASquadManager::GoToNextZone()
{
	FVector ZonePosition = CurrentZone->GetActorLocation();
	for(AAgent* agent : agents)
	{
		agent->SetTarget(ZonePosition);
		agent->SetTask(ETasks::MoveToZone);
	}
}


void ASquadManager::RequestNewTask(AAgent* agent)
{
		
	if(CurrentZone)
	{
		if(CurrentZone->IsCleared())
		{
			//search for next zone
			
		}
		else
		{
			//keep clearing current zone
			FEnvQueryRequest QueryRequest = FEnvQueryRequest(FirstNodeQuery, this);
			QueryRequest.Execute(EEnvQueryRunMode::SingleResult, agent, &AAgent::NodeQueryFinished);
		}
	}
	else if(UnclearedZones.Num() != 0)
	{
		CurrentZone = UnclearedZones.Last();
		UnclearedZones.Pop();

		FEnvQueryRequest QueryRequest = FEnvQueryRequest(FirstNodeQuery, this);
		QueryRequest.Execute(EEnvQueryRunMode::SingleResult, agent, &AAgent::NodeQueryFinished);
		
	}
	
	
}


