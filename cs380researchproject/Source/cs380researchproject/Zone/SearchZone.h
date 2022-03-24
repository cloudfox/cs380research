// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchZone.generated.h"

class ASightNode;

UCLASS()
class CS380RESEARCHPROJECT_API ASearchZone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASearchZone();

	void SearchNodeFound();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	int SearchNodesCount = 0;
	int searchNodesFound = 0;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ASightNode*> SearchNodes;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float width = 500;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float depth = 500;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float height = 500;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float spacing = 100;
	
	
};
