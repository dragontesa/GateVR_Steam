// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class GateVR : ModuleRules
{
	public GateVR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDefinitions.Add("WITH_ONLINESUBSYSTEM=0");

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", 
			"UMG", "Networking", "Sockets", "Json",
	   		"Voice",
		    }); // "HeadMountedDisplay",

        if (Target.Platform == UnrealTargetPlatform.Android || Target.Platform == UnrealTargetPlatform.Win64) 
		{
			// PublicDependencyModuleNames.AddRange(new string[] { "GateTalkingfree" });  // Agora need to get fixed build error for Android
		}
		
		if (Target.Platform == UnrealTargetPlatform.Android || Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Linux)
		{
			PrivateDependencyModuleNames.AddRange(new string[] {
				// "OnlineSubsystem", "OnlineSubsystemNull", "OnlineSubsystemUtils",   // Steam need to get fixed build error for Android
			});
			// DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		}
		
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore"});
        DynamicallyLoadedModuleNames.AddRange(new string[] { "InMemoryNetworkReplayStreaming" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

		// Loade Steam Module inside Game
		DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
    }
}
