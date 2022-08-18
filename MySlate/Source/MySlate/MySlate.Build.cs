// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MySlate : ModuleRules
{
	public MySlate(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine","InputCore", "Slate", "SlateCore","HeadMountedDisplay","Json", "JsonUtilities" });

	}
}
