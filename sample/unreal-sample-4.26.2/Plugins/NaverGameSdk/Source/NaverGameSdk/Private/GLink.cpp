// Fill out your copyright notice in the Description page of Project Settings.
#include "GLink.h"
#include "NaverGameSdkPrivatePCH.h"
#include "NaverGLink.h"


UGLink::UGLink(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // do nothing.
}

void UGLink::Init(FString ClientId, FString ClientSecret, FString LoungeId)
{
    GetSharedSdk()->Init(ClientId, ClientSecret, LoungeId);
}

void UGLink::ExecuteHomeBanner()
{
    GetSharedSdk()->StartHome();
}

void UGLink::ExecuteSorryBanner()
{
    GetSharedSdk()->StartSorry();
}

void UGLink::TerminateSdk()
{
    GetSharedSdk()->FinishSdk();
}

void UGLink::ExecuteBoard(int BoardId)
{
    GetSharedSdk()->StartBoard(BoardId);
}

void UGLink::ExecuteFeed(int FeedId, bool IsTempFeedId)
{
    GetSharedSdk()->StartFeed(FeedId, IsTempFeedId);
}

FString UGLink::GetCountryCode()
{
    return GetSharedSdk()->GetCountryCode();
}

void UGLink::SetCanWriteFeedByScreenshot(bool Enabled)
{
    GetSharedSdk()->SetCanWriteFeedByScreenshot(Enabled);
}

void UGLink::SetGameId(FString GameId)
{
    GetSharedSdk()->SetGameId(GameId);
}

void UGLink::SetAppName(FString AppName)
{
    GetSharedSdk()->SetAppName(AppName);
}

void UGLink::SetAppScheme(FString AppScheme)
{
    GetSharedSdk()->SetAppScheme(AppScheme);
}

FString UGLink::GetAuthSettingDescription()
{
    return GetSharedSdk()->GetAuthSettingDescription();
}

void UGLink::ExecuteFeedWriting(int BoardId, FString Title, FString Text, FString ImageFilePath)
{
    GetSharedSdk()->StartFeedWriting(BoardId, Title, Text, ImageFilePath);
}

void UGLink::NaverLogout()
{
    GetSharedSdk()->NaverLogout();
}
