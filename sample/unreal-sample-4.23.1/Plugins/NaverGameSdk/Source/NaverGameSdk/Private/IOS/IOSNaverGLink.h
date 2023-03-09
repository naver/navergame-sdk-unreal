// NAVER Game SDK for iOS
// Copyright 2021-present NAVER Corp.
//
// Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
// Created by Alan on 2021/05/14.


// Naver Game SDK Bridge Code for Unreal


#pragma once

#import <NNGSDK/NNGSDKManager.h>
#include "NaverGLink.h"


class FIOSNaverGLink : public INaverGLink
{
public:
    FIOSNaverGLink();
    
    FString GetCountryCode() const;
    
    void Init(FString ClientId, FString ClientSecret, FString LoungeId) const;
    void SetCanWriteFeedByScreenshot(bool Enabled) const;
    void SetGameId(FString GameId) const;
    
    void SetAppName(FString AppName) const;
    void SetAppScheme(FString AppScheme) const;
    FString GetAuthSettingDescription() const;
    
    void StartHome() const;
    void StartSorry() const;
    
    void StartBoard(int BoardId) const;
    
    void StartFeed(int FeedId, bool IsTempFeedId) const;
    
    void StartFeedWriting(int BoardId, FString Title, FString Text, FString ImageFilePath) const;
    
    void FinishSdk() const;
    
    void NaverLogout() const;
};


@interface NaverGLinkCallbackObject : NSObject <NNGSDKDelegate>

@property (class, nonatomic, readonly) NaverGLinkCallbackObject *shared;

@property (nonatomic, readonly) NSString *countryCode;

@property (nonatomic, readonly) NSString *authSettingDescription;


- (void)setClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret loungeId:(NSString *)loungeId;
- (void)setCanWriteFeedByScreenshot:(BOOL)enabled;
- (void)setGameId:(NSString *)gameId;

- (void)setAppName:(NSString *)appName;
- (void)setAppScheme:(NSString *)appScheme;

- (void)startHome;
- (void)startSorry;

- (void)startBoardWithBoardId:(NSNumber *)boardId;

- (void)startFeedWithFeedId:(NSNumber *)feedId tempFeedId:(BOOL)tempFeedId;

- (void)startFeedWritingWithBoardId:(NSNumber *)boardId title:(NSString *)title text:(NSString *)text imageFilePath:(NSString *)imageFilePath;

- (void)finishSdk;

- (void)naverLogout;

@end
