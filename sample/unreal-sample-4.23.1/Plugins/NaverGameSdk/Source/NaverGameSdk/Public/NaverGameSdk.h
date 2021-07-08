#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class NAVERGAMESDK_API FNaverGameSdkModule : public IModuleInterface
{
public:
    
    DECLARE_MULTICAST_DELEGATE(FOnSdkStarted);
    DECLARE_MULTICAST_DELEGATE(FOnSdkStopped);
    DECLARE_MULTICAST_DELEGATE_OneParam(FOnReceiveInGameMenuCode, const FString& /* In-Game Menu Code */);
    
    static inline FNaverGameSdkModule& Get()
    {
        return FModuleManager::LoadModuleChecked< FNaverGameSdkModule >( "NaverGameSdk" );
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded( "NaverGameSdk" );
    }

    static FOnSdkStarted OnSdkStarted;
    static FOnSdkStopped OnSdkStopped;
    static FOnReceiveInGameMenuCode OnReceiveInGameMenuCode;
};
