// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NNGUnrealSampleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class NNG_UNREAL_SAMPLE_API ANNGUnrealSampleGameMode : public AGameMode
{
	GENERATED_BODY()
	
    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
    
    void OnSdkStarted();
    void OnSdkStopped();
    void OnReceiveInGameMenuCode(const FString& InGameMenuCode);
};
