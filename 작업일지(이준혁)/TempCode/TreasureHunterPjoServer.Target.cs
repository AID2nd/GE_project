using UnrealBuildTool;
using System.Collections.Generic;

// [SupportedPlatforms(UnrealPlatformClass.Server)]
public class TreasureHunterPjoServerTarget: TargetRules
{
    public TreasureHunterPjoServerTarget(TargetInfo Target) : base(Target)
       {
        Type = TargetType.Server;
        ExtraModuleNames.Add("TreasureHunterPjo");
    }
}
