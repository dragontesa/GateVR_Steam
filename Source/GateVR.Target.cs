// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class GateVRTarget : TargetRules
{
	public GateVRTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
        // bUsesSteam = true;

        DisablePlugins.Add("Convai");
        DisablePlugins.Add("OVRLipSync");
        DisablePlugins.Add("ThreeDGaussians");
        ExtraModuleNames.AddRange( new string[] { "GateVR", "GateXRMovement", "GateGameLift"} );
	}
}
