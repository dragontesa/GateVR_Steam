// Copyright Epic Games, Inc. All Rights Reserved.
using System;
using System.IO;
using UnrealBuildTool;
namespace UnrealBuildTool.Rules
{
	public class GateSteam : ModuleRules
	{

		public string SteamSdkDir
		{
			get {
				var EngineDir = Path.GetFullPath(Target.RelativeEnginePath);
				string sdkdir = Path.Combine(EngineDir, "Source/ThirdParty/Steamworks/Steamv153/sdk");
				return sdkdir;
			}
		}

		public string SteamSdkInclude
		{
			get { 
				string sdkInc = Path.Combine(SteamSdkDir, "public","steam");
				return sdkInc;
			 }
		}

		public string SteamSdkLibDir
		{
			get {
				string sdkLib = Path.Combine(SteamSdkDir, "redistributable_bin");
                if (Target.Platform == UnrealTargetPlatform.Linux)
			    {
			    	return Path.Combine(sdkLib, "linux64");
			    }
			    else if (Target.Platform == UnrealTargetPlatform.Mac)
			    {
			    	return Path.Combine(sdkLib, "osx");
			    }
			    else if (Target.Platform == UnrealTargetPlatform.Win64)
			    {
			    	return Path.Combine(sdkLib, "win64");
			    }
				else {
					return "";
				}
			}
		}

		public string SteamSdkLibName
		{
            get
            {
                if (Target.Platform == UnrealTargetPlatform.Win64)
                {
                    return "steam_api64.dll";
                }
                else if (Target.Platform == UnrealTargetPlatform.Linux)
                {
                    return "libsteam_api.so";
                }
                else if (Target.Platform == UnrealTargetPlatform.Mac)
                {
                    return "libsteam_api.dylib";
                }
				else {
					return "";
				}
            }
		}

		public GateSteam(ReadOnlyTargetRules Target) : base(Target)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"ApplicationCore",
					"Engine"
				});

         		PrivateIncludePaths.AddRange(
				new string[] {
					ModuleDirectory,
					SteamSdkInclude
				});

				PublicIncludePaths.AddRange(
					new string[] {
						Path.Combine(ModuleDirectory)
					});


            if (Target.Type == TargetRules.TargetType.Server)
			{
				PublicDefinitions.Add("WITH_STEAMSERVER=1");
			}
			else
			{
				PublicDefinitions.Add("WITH_STEAMSERVER=0");
			}

            // add library
            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicAdditionalLibraries.Add(Path.Combine(SteamSdkLibDir,"steam_api64.lib"));
				RuntimeDependencies.Add(Path.Combine(SteamSdkLibDir, "steam_api64.dll"));
            }
			else if (Target.Platform == UnrealTargetPlatform.Linux)
			{
				RuntimeDependencies.Add(Path.Combine(SteamSdkLibDir, "libsteam_api.so"));
			}
			else if (Target.Platform == UnrealTargetPlatform.Mac)
			{
				PublicAdditionalLibraries.Add(Path.Combine(SteamSdkLibDir, "libsteam_api.dylib"));
				RuntimeDependencies.Add(Path.Combine(SteamSdkLibDir, "libsteam_api.dylib"));
			}


			// copy steam app id file, only for development
			string BinariesDirectory = Path.Combine(Path.GetDirectoryName(Path.GetDirectoryName(ModuleDirectory)), "Binaries",Target.Platform.ToString());
			if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "steam_appid.txt")) == false) {
			    File.Copy(Path.Combine(ModuleDirectory,"steam_appid.txt"),Path.Combine(BinariesDirectory, "steam_appid.txt"));
			}

			// copy steam lib into the entripoint game is executed, this must be need for Shipping Packaging
			if (File.Exists(System.IO.Path.Combine(BinariesDirectory, SteamSdkLibName)) == false) {
				File.Copy(Path.Combine(SteamSdkLibDir,SteamSdkLibName),Path.Combine(BinariesDirectory, SteamSdkLibName));
			}

		}
	}
}
