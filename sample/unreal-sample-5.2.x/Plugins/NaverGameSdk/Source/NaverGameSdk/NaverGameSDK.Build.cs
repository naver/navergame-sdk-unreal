
using System.IO;
using UnrealBuildTool;

public class NaverGameSdk : ModuleRules
{
	
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "./ThirdPartyFrameworks/")); }
	}

	public NaverGameSdk(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivatePCHHeaderFile = "Private/NaverGameSdkPrivatePCH.h";

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Engine",
				"Core",
				"CoreUObject",
				"Slate",
				"SlateCore",
				"UMG"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...
			}
		);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "NaverGameSdk_UPL.xml"));
		}

		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			// Add framework
			PublicAdditionalFrameworks.Add(
				new Framework(
					"NNGSDK",
					"./ThirdPartyFrameworks/iOS/NNGSDK.xcframework",
					null,
					true
				)
			);

			PublicAdditionalFrameworks.Add(
                new Framework(
					"NaverThirdPartyLogin",
					"./ThirdPartyFrameworks/iOS/NaverThirdPartyLogin.xcframework",
					null,
					true
            	)
         	);

			bEnableObjCExceptions = false;
			
			PublicFrameworks.AddRange(
				new string[]
				{
					"UIKit",
					"Foundation",
					"MediaPlayer",
					"SystemConfiguration",
					"Security",
					"MobileCoreServices",
					"GameKit",
					"AssetsLibrary",
					"WebKit",
					"SafariServices"
				}
			);
		}
	}

}
