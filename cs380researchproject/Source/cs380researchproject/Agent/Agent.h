// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Agent.generated.h"

class ASquadManager;
class ASearchZone;

UENUM()
enum class ETasks: uint8
{
	Wait,
	MoveToZone,
	MoveToNode,
	ClearObstacle,
	TaskCount,
};




UCLASS()
class CS380RESEARCHPROJECT_API AAgent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAgent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void NodeQueryFinished(TSharedPtr<FEnvQueryResult> Result);
	

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class UAIPerceptionComponent* aiPerceptionComponent;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAISenseConfig_Sight* sightConfig;


	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	ETasks CurrentTask;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FVector TargetPosition;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	ASquadManager* SquadManager;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	ASearchZone* CurrentZone;

	UFUNCTION(BlueprintCallable)
	void SetTarget(FVector& Position);

	UFUNCTION(BlueprintCallable)
	void SetTask(ETasks Task);

	
};
