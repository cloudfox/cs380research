// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorsFromContext.h"
#include "AI/Navigation/NavigationTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Point.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

UActorsFromContext::UActorsFromContext(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	QueryContext = UEnvQueryContext_Querier::StaticClass();
	ItemType = UEnvQueryItemType_Actor::StaticClass();
}

void UActorsFromContext::GenerateItems(FEnvQueryInstance& QueryInstance) const
{
	TArray<AActor*> ContextActors;
	QueryInstance.PrepareContext(QueryContext, ContextActors);

	
	QueryInstance.AddItemData<UEnvQueryItemType_Actor>(ContextActors);
}
