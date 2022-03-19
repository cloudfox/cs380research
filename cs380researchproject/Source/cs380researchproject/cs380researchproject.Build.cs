// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cs380researchproject : ModuleRules
{
	public cs380researchproject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
