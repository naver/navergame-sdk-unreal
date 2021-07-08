

#pragma once

#include "Core.h"
#include "Android/AndroidJava.h"
#include "NaverGLink.h"
class FAndroidNaverGLink : public INaverGLink
{
	jmethodID Method_Init;
	jmethodID Method_FinishSdk;
	
	jmethodID Method_StartHome;
	jmethodID Method_StartSorry;
	jmethodID Method_StartBoard;
	jmethodID Method_StartFeed;
	jmethodID Method_GetCountryCode;
 
public:
	FAndroidNaverGLink();
    ~FAndroidNaverGLink();
    FString GetCountryCode() const;
	void Init(FString ClientId, FString ClientSecret, FString LoungeId) const;
	void StartHome() const;
    void StartSorry() const;
    void StartBoard(int BoardId) const;
    void StartFeed(int FeedId, bool IsTempFeedId) const;
    void FinishSdk() const;
};
