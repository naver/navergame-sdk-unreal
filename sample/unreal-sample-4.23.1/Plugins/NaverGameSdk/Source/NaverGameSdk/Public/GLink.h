// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GLink.generated.h"

/**
 * 
 */
UCLASS()
class NAVERGAMESDK_API UGLink : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void Init(FString ClientId, FString ClientSecret, FString LoungeId);
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void ExecuteHomeBanner();
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void ExecuteSorryBanner();
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void TerminateSdk();
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void ExecuteBoard(int BoardId);
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void ExecuteFeed(int FeedId, bool IsTempFeedId);
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static FString GetCountryCode();
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void SetCanWriteFeedByScreenshot(bool Enabled);
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void SetGameId(FString GameId);
    
    UFUNCTION(BlueprintCallable, Category = "Naver GameSdk")
    static void ExecuteFeedWriting(int BoardId, FString Title, FString Text, FString ImageFilePath);

};
