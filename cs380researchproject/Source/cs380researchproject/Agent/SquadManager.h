// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SquadAgent.h"
#include "../Zone/SearchZone.h"
#include "SquadManager.generated.h"

UENUM(BlueprintType)
enum WorldState
{
	ZoneUncleared UMETA(DisplayName = "Zone Not Cleared"),
	ObstacleFound UMETA(DisplayName = "Obstacle Found"),
	ZoneBlocked UMETA(DisplayName = "Next Zone Blocked"),
	AllZonesCleared UMETA(DisplayName = "All Zones Cleared")
};


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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	TEnumAsByte<WorldState> worldState;

	TArray<ASquadAgent*> agents;
	TArray<ASearchZone*> Zones;
	//TArray<Obstacle*> Obstacles;
	
	//void AddObstacle(Actor* Obstacle);

	//TArray<TaskList>

	//void AssignTask(ASquadAgent* agent, Task task);

	
};


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



