// Fill out your copyright notice in the Description page of Project Settings.


#include "NNGUnrealSampleGameMode.h"
#include "NaverGameSdk.h"
#include "GLink.h"

void ANNGUnrealSampleGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    AGameMode::InitGame(MapName, Options, ErrorMessage);
    
    // 네이버 게임 SDK 시작
    FNaverGameSdkModule::OnSdkStarted.AddUObject(this, &ANNGUnrealSampleGameMode::OnSdkStarted);
        
    // 네이버 게임 SDK 종료
    FNaverGameSdkModule::OnSdkStopped.AddUObject(this, &ANNGUnrealSampleGameMode::OnSdkStopped);
        
    // 인게임 메뉴 코드 수신
    FNaverGameSdkModule::OnReceiveInGameMenuCode.AddUObject(this, &ANNGUnrealSampleGameMode::OnReceiveInGameMenuCode);
}

void ANNGUnrealSampleGameMode::OnSdkStarted()
{
    UE_LOG(LogTemp, Warning, TEXT("OnSdkStarted"));
}

void ANNGUnrealSampleGameMode::OnSdkStopped()
{
    UE_LOG(LogTemp, Warning, TEXT("OnSdkStopped"));
}

void ANNGUnrealSampleGameMode::OnReceiveInGameMenuCode(const FString& InGameMenuCode)
{
    UE_LOG(LogTemp, Warning, TEXT("OnReceiveInGameMenuCode, %s"), *InGameMenuCode );
}

