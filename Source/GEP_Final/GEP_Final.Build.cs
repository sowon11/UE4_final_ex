// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GEP_Final : ModuleRules
{
	public GEP_Final(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });
	}
}
