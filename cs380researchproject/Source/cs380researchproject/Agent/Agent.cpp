// Fill out your copyright notice in the Description page of Project Settings.


#include "Agent.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "../Zone/SightNode.h"
#include "cs380researchproject/Zone/SightNode.h"


// Sets default values
AAgent::AAgent()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	aiPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));

	sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	aiPerceptionComponent->SetDominantSense(sightConfig->GetSenseImplementation());

	sightConfig->SightRadius = 1000.0f;
	sightConfig->LoseSightRadius = 1000.0f;
	sightConfig->PeripheralVisionAngleDegrees = 60.0f;
	sightConfig->DetectionByAffiliation.bDetectEnemies = true;
	sightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	sightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	aiPerceptionComponent->ConfigureSense(*sightConfig);
}

// Called when the game starts or when spawned
void AAgent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AAgent::NodeQueryFinished(TSharedPtr<FEnvQueryResult> Result)
{
	FVector ZonePosition = Result->GetItemAsLocation(0);
	ASightNode* TargetNode = static_cast<ASightNode*>(Result->GetItemAsActor(0));
	TargetNode->Targeted = true;
	
	
	SetTarget(ZonePosition);
	SetTask(ETasks::MoveToNode);
	
}

void AAgent::SetTarget(FVector& Position)
{
	TargetPosition = Position;
	UBlackboardComponent* blackboard = UAIBlueprintHelperLibrary::GetBlackboard(this);
	blackboard->SetValueAsVector("Location", Position);
}

void AAgent::SetTask(ETasks Task)
{
	CurrentTask = Task;
	UBlackboardComponent* blackboard = UAIBlueprintHelperLibrary::GetBlackboard(this);
	blackboard->SetValueAsEnum("CurrentTask", static_cast<uint8>(Task));
	
}

