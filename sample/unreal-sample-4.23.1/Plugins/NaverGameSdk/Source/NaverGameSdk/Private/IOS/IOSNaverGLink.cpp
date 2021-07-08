// NAVER Game SDK for iOS
// Copyright 2021-present NAVER Corp.
//
// Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
// Created by Alan on 2021/05/14.


// Naver Game SDK Bridge Code for Unreal


#include "IOSNaverGLink.h"
#include "NaverGameSdkPrivatePCH.h"
#include "IOSAppDelegate.h"
#include "IOSView.h"


FIOSNaverGLink::FIOSNaverGLink()
{
}

void FIOSNaverGLink::Init(FString ClientId, FString ClientSecret, FString LoungeId) const
{
    [NaverGLinkCallbackObject.shared setClientId:ClientId.GetNSString() clientSecret:ClientSecret.GetNSString() loungeId:LoungeId.GetNSString()];
}

void FIOSNaverGLink::StartHome() const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared startHome];
    });
}

void FIOSNaverGLink::StartSorry() const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared startSorry];
    });
}

void FIOSNaverGLink::FinishSdk() const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared finishSdk];
    });
}

void FIOSNaverGLink::StartBoard(int BoardId) const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared startBoardWithBoardId:@(BoardId)];
    });
}

void FIOSNaverGLink::StartFeed(int FeedId, bool IsTempFeedId) const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared startFeedWithFeedId:@(FeedId) tempFeedId:IsTempFeedId];
    });
}


FString FIOSNaverGLink::GetCountryCode() const
{
    return UTF8_TO_TCHAR(NaverGLinkCallbackObject.shared.countryCode);
}


@implementation NaverGLinkCallbackObject

+ (NaverGLinkCallbackObject *)shared {
    static NaverGLinkCallbackObject *instance = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    });
    
    [instance setParentViewController];
    
    return instance;
}


- (void)setClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret loungeId:(NSString *)loungeId {
    [NNGSDKManager.shared setClientId:clientId clientSecret:clientSecret loungeId:loungeId];
}


- (void)setParentViewController {
    [NNGSDKManager.shared setParentViewController:[IOSAppDelegate GetDelegate].IOSController];
    NNGSDKManager.shared.delegate = self;
}


- (void)startHome {
    [NNGSDKManager.shared presentBannerViewController];
}


- (void)startSorry {
    [NNGSDKManager.shared presentSorryViewController];
}


- (void)finishSdk {
    [NNGSDKManager.shared dismiss];
}


- (void)startBoardWithBoardId:(NSNumber *)boardId {
    [NNGSDKManager.shared presentBoardViewControllerWith:boardId];
}


- (void)startFeedWithFeedId:(NSNumber *)feedId tempFeedId:(BOOL)tempFeedId {
    [NNGSDKManager.shared presentFeedViewControllerWith:feedId scheduled:tempFeedId];
}


- (NSString *)countryCode {
    return NNGSDKManager.shared.countryCode;
}


#pragma mark - NCSDKDelegate

- (void)nngSDKDidLoad {
    FNaverGameSdkModule::OnSdkStarted.Broadcast();
}


- (void)nngSDKDidUnload {
    FNaverGameSdkModule::OnSdkStopped.Broadcast();
}


- (void)nngSDKDidReceiveInGameMenuCode:(NSString *)inGameMenuCode {
    FString inGameMenuCodeString = UTF8_TO_TCHAR(inGameMenuCode);
    FNaverGameSdkModule::OnReceiveInGameMenuCode.Broadcast(inGameMenuCodeString);
}

@end
