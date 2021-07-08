// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class nng_unreal_sampleTarget : TargetRules
{
	public nng_unreal_sampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "nng_unreal_sample" } );
	}
}
