// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_CurrentLocation.h"
#include "ActorsFromContext.generated.h"

/**
 * 
 */
UCLASS()
class CS380RESEARCHPROJECT_API UActorsFromContext : public UEnvQueryGenerator_CurrentLocation
{
	GENERATED_BODY()

protected:

public:
	UActorsFromContext(const FObjectInitializer& ObjectInitializer);
	
	virtual void GenerateItems(FEnvQueryInstance& QueryInstance) const override;

};
