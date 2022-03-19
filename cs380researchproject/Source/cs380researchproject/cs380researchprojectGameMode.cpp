// Copyright Epic Games, Inc. All Rights Reserved.

#include "cs380researchprojectGameMode.h"
#include "cs380researchprojectPlayerController.h"
#include "cs380researchprojectCharacter.h"
#include "UObject/ConstructorHelpers.h"

Acs380researchprojectGameMode::Acs380researchprojectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = Acs380researchprojectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}