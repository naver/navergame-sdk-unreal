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
    
    void Init(FString ClientId, FString ClientSecret, FString LoungeId) const;
    
    void StartHome() const;
    void StartSorry() const;
    
    void FinishSdk() const;
    
    void StartBoard(int BoardId) const;
    void StartFeed(int FeedId, bool IsTempFeedId) const;
    
    FString GetCountryCode() const;
    
};


@interface NaverGLinkCallbackObject : NSObject <NNGSDKDelegate>

@property (class, nonatomic, readonly) NaverGLinkCallbackObject *shared;

- (void)setClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret loungeId:(NSString *)loungeId;

- (void)startHome;
- (void)startSorry;

- (void)finishSdk;

- (void)startBoardWithBoardId:(NSNumber *)boardId;
- (void)startFeedWithFeedId:(NSNumber *)feedId tempFeedId:(BOOL)tempFeedId;

@property (nonatomic, readonly) NSString *countryCode;

@end
