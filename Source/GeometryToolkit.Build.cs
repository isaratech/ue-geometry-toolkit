// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

using UnrealBuildTool;

public class GeometryToolkit : ModuleRules
{
	public GeometryToolkit(ReadOnlyTargetRules ROTargetRules) : base(ROTargetRules)
    {
        // This prevents UBT from complaining when it finds module PCH before class header
        // PCHUsage = PCHUsageMode.NoSharedPCHs;
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
			new string[] {
				"GeometryToolkit/Public"
				
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                "GeometryToolkit/Classes",
                "GeometryToolkit/Private"
				
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",

				// ... add private dependencies that you statically link with here ...	
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
