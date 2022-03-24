// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "SightNode.generated.h"



class ASearchZone;

UCLASS()
class CS380RESEARCHPROJECT_API ASightNode : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASightNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	bool NodeFound = false;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ASearchZone* Parent;
	
	UFUNCTION(BlueprintCallable)
	bool Found();


	friend class ASearchZone;
};
