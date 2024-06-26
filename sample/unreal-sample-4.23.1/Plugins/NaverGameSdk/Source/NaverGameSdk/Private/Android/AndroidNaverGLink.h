

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

	jmethodID Method_SetCanWriteFeedByScreenshot;
	jmethodID Method_StartFeedWriting;
	jmethodID Method_SetGameId;
	jmethodID Method_NaverLogout;

 
public:
	FAndroidNaverGLink();
    ~FAndroidNaverGLink();
    FString GetCountryCode() const;
	void Init(FString ClientId, FString ClientSecret, FString LoungeId) const;
	void SetCanWriteFeedByScreenshot(bool Enabled) const;
    void SetGameId(FString GameId) const;

	void StartHome() const;
    void StartSorry() const;
    void StartBoard(int BoardId) const;
    void StartFeed(int FeedId, bool IsTempFeedId) const;
    void StartFeedWriting(int BoardId, FString Title, FString Text, FString ImageFilePath) const;
    
    void SetAppName(FString AppName) const;
    void SetAppScheme(FString AppScheme) const;
    FString GetAuthSettingDescription() const;
        
    
    void FinishSdk() const;
	void NaverLogout() const;

};
