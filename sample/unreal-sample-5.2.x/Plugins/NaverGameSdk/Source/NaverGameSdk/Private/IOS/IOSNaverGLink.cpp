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


static void ListenNNGSDKOpenURL(UIApplication* application, NSURL* url, NSString* sourceApplication, id annotation)
{
    [NNGSDKManager.shared handleCallbackUrl:url];
}

FIOSNaverGLink::FIOSNaverGLink()
{
}

FString FIOSNaverGLink::GetCountryCode() const
{
    return UTF8_TO_TCHAR(NaverGLinkCallbackObject.shared.countryCode);
}

void FIOSNaverGLink::Init(FString ClientId, FString ClientSecret, FString LoungeId) const
{
    [NaverGLinkCallbackObject.shared setClientId:ClientId.GetNSString() clientSecret:ClientSecret.GetNSString() loungeId:LoungeId.GetNSString()];
    FIOSCoreDelegates::OnOpenURL.AddStatic(&ListenNNGSDKOpenURL);
}

void FIOSNaverGLink::SetCanWriteFeedByScreenshot(bool Enabled) const
{
    [NaverGLinkCallbackObject.shared setCanWriteFeedByScreenshot:Enabled];
}

void FIOSNaverGLink::SetGameId(FString GameId) const
{
    [NaverGLinkCallbackObject.shared setGameId:GameId.GetNSString()];
}

void FIOSNaverGLink::SetAppName(FString AppName) const
{
    [NaverGLinkCallbackObject.shared setAppName:AppName.GetNSString()];
}

void FIOSNaverGLink::SetAppScheme(FString AppScheme) const
{
    [NaverGLinkCallbackObject.shared setAppScheme:AppScheme.GetNSString()];
}

FString FIOSNaverGLink::GetAuthSettingDescription() const
{
    return UTF8_TO_TCHAR(NaverGLinkCallbackObject.shared.authSettingDescription);
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

void FIOSNaverGLink::StartFeedWriting(int BoardId, FString Title, FString Text, FString ImageFilePath) const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared startFeedWritingWithBoardId:@(BoardId) title:Title.GetNSString() text:Text.GetNSString() imageFilePath:ImageFilePath.GetNSString()];
    });
}

void FIOSNaverGLink::FinishSdk() const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared finishSdk];
    });
}

void FIOSNaverGLink::NaverLogout() const
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [NaverGLinkCallbackObject.shared naverLogout];
    });
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


- (NSString *)countryCode {
    return NNGSDKManager.shared.countryCode;
}


- (NSString *)authSettingDescription {
    return NNGSDKManager.shared.authSettingDescription;
}


- (void)setClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret loungeId:(NSString *)loungeId {
    [NNGSDKManager.shared setClientId:clientId clientSecret:clientSecret loungeId:loungeId];
}


- (void)setParentViewController {
    [NNGSDKManager.shared setParentViewController:[IOSAppDelegate GetDelegate].IOSController];
    NNGSDKManager.shared.delegate = self;
}


- (void)setCanWriteFeedByScreenshot:(BOOL)enabled {
    NNGSDKManager.shared.canWriteFeedByScreenshot = enabled;
}


- (void)setGameId:(NSString *)gameId {
    [NNGSDKManager.shared registerMemberGameId:gameId];
}


- (void)setAppName:(NSString *)appName {
    [NNGSDKManager.shared setAppName:appName];
}


- (void)setAppScheme:(NSString *)appScheme {
    [NNGSDKManager.shared setAppScheme:appScheme];
}


- (void)startHome {
    [NNGSDKManager.shared presentBannerViewController];
}


- (void)startSorry {
    [NNGSDKManager.shared presentSorryViewController];
}


- (void)startBoardWithBoardId:(NSNumber *)boardId {
    [NNGSDKManager.shared presentBoardViewControllerWith:boardId];
}


- (void)startFeedWithFeedId:(NSNumber *)feedId tempFeedId:(BOOL)tempFeedId {
    [NNGSDKManager.shared presentFeedViewControllerWith:feedId scheduled:tempFeedId];
}


- (void)startFeedWritingWithBoardId:(NSNumber *)boardId title:(NSString *)title text:(NSString *)text imageFilePath:(NSString *)imageFilePath {
    [NNGSDKManager.shared presentFeedWritingWithBoardId:boardId title:title text:text imageFilePath:imageFilePath];
}


- (void)finishSdk {
    [NNGSDKManager.shared dismiss];
}

- (void)naverLogout {
    [NNGSDKManager.shared logout];
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
