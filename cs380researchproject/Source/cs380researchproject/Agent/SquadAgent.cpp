// Fill out your copyright notice in the Description page of Project Settings.


#include "SquadAgent.h"

// Sets default values
ASquadAgent::ASquadAgent()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Comp"));
	
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);

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
void ASquadAgent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquadAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASquadAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

