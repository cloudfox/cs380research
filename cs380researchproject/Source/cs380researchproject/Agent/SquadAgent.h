// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SkeletalMeshComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "SquadAgent.generated.h"


UCLASS()
class CS380RESEARCHPROJECT_API ASquadAgent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASquadAgent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class USkeletalMeshComponent* MeshComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class UAIPerceptionComponent* aiPerceptionComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAISenseConfig_Sight* sightConfig;
	
private:

	
	
	
};
