// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JsonDBConfigLoaderEditor : ModuleRules
{
	public JsonDBConfigLoaderEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...
				"Core",
				"DesktopPlatform",
				"Slate", 
				"SlateCore",
				"Json",
				"EditorStyle", 
				"PropertyEditor",
				"JsonDBConfigLoader"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
				"Projects",
				"InputCore",
				"UnrealEd",
				"ToolMenus",
				"CoreUObject",
				"Engine",
				"OpenSSL",
				"SSL",
				"JsonDBConfigLoader"
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
