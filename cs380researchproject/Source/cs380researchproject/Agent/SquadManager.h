// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Agent.h"
#include "../Zone/SearchZone.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "Math/Vector.h"
#include "SquadManager.generated.h"

UENUM(BlueprintType)
enum class EWorldState : uint8
{
	NotInZone UMETA(DisplayName = "NotInZone"),
	ZoneUncleared UMETA(DisplayName = "Zone Not Cleared"),
	ObstacleFound UMETA(DisplayName = "Obstacle Found"),
	ZoneBlocked UMETA(DisplayName = "Next Zone Blocked"),
	AllZonesCleared UMETA(DisplayName = "All Zones Cleared")
};




// USTRUCT(BlueprintType)
// struct FWorldStateProperties
// {
// 	GENERATED_BODY()
// 	bool ZoneClear;
// 	TArray<AActor> Obstacles; 
// };


UCLASS()
class CS380RESEARCHPROJECT_API ASquadManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASquadManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ZoneQueryFinished(TSharedPtr<FEnvQueryResult> Result);

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	EWorldState CurrentWorldState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEnvQuery* ZoneQuery;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEnvQuery* FirstNodeQuery;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEnvQuery* SecondNodeQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AAgent*> agents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ASearchZone* CurrentZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> AssignedNodes;



	UFUNCTION(BlueprintCallable)
	void EnteredFirstZone(ASearchZone* zone, AAgent* agent);
	
	UFUNCTION(BlueprintCallable)
	FVector ChooseFirstNode();

	UFUNCTION(BlueprintCallable)
	FVector ChooseSubsequentNode();

	//void MoveToQueryResult(TSharedPtr<FEnvQueryResult> result);
	
};

//start
//move all agents to zone

//assign search nodes to agents
//might be able to use just one eqs for this

//search task will repeat until a new task is assigned
//if no more possible nodes switch to idle

//on obstruction assign new tasks to agents to clear it
//on clear check if zone has more nodes to search
//reassign search tasks to all agents

//on zone clear move to next zone
//assign tasks to clear way to next zone


//void AssignNode()
//void AssignTask();
//struct assigned tasks(task, priority)
//array assignedTasks








//start
//if agents are not in zone move them all to accessible zone

//once in zone set as the active area
//choose first node in zone
//first node should prefer being more being more to the side and as far away as possible


//can choose an eqs query in editor UEnvQuery* MyQuery;
//should return a vector instead of the node itself to avoid ai_move_to weirdness
//should prefer nodes in same general area(unreal trace should be good enough)
//currently targeted nodes should be kept in a list

//choose more nodes until all agents have a target
//subsequent search nodes should prioritize distance away from all other currently targeted nodes
//should prefer nodes in same general area(unreal trace should be good enough)


//when encountering obstacles
//obstacles should have a priority

//critical priority will immediately stop search for current node to clear obstacle
//(mainly if the obstacle prevent access to the node)
//if needed will call for other agents- priority will also determine if they should abandon current task

//high priority will add to list of active obstacles and will wait until current task is complete
//medium priority will wait until all other obstacle are clear
//low priority will wait until all other tasks are done(probably when a zone is cleared and a new zone is needed)















//1 clear all possible nodes in current zone
//2 remove obstacles
//3 move to uncleared zone
//4 repeat

//zones
//nodes
//exploration node
//action node

//tasks
//1. nav to node
//2. nav to obstacle
//2. clear obstacle


//choosing a node to nav to
//1. 1st node try to choose closest node to squad and state what direction relative to agent
//2. subsequent nodes pick closest node that is not close to nodes that is in a different dir to previous
//try to prefer nodes not directly in front of the current agent



