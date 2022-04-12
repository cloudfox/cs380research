// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchZone.generated.h"

class ASightNode;
class ASquadManager;

UCLASS()
class CS380RESEARCHPROJECT_API ASearchZone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASearchZone();

	UFUNCTION(BlueprintCallable)
	void SearchNodeFound() const;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool IsCleared() const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ASquadManager* squadManager;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AActor*> SearchNodes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ASearchZone*> ConnectedZones;
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NodeCount;
	
	
};
