// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class nng_unreal_sampleEditorTarget : TargetRules
{
	public nng_unreal_sampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "nng_unreal_sample" } );
	}
}
