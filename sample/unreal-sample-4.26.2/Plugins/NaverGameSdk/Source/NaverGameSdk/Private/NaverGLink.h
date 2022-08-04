
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class INaverGLink
{
public:
	
	virtual void Init(FString ClientId, FString ClientSecret, FString LoungeId) const = 0;
	virtual void StartHome() const = 0;
    virtual void StartSorry() const = 0;
    virtual void FinishSdk() const = 0;
    virtual void StartBoard(int BoardId) const = 0;
    virtual void StartFeed(int FeedId, bool IsTempFeedId) const = 0;
    virtual FString GetCountryCode() const = 0;
    virtual void SetCanWriteFeedByScreenshot(bool Enabled) const = 0;
    virtual void SetGameId(FString GameId) const = 0;
    virtual void StartFeedWriting(int BoardId, FString Title, FString Text, FString ImageFilePath) const = 0;
    
};

INaverGLink* GetSharedSdk();
bool IsNaverGameSdkAvailable();
