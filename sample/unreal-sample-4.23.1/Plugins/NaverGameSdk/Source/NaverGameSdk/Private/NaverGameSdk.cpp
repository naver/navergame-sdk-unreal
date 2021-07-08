#include "NaverGameSdk.h"
#include "NaverGameSdkPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FNaverGameSdkModule"

FNaverGameSdkModule::FOnSdkStarted FNaverGameSdkModule::OnSdkStarted;
FNaverGameSdkModule::FOnSdkStopped FNaverGameSdkModule::OnSdkStopped;
FNaverGameSdkModule::FOnReceiveInGameMenuCode FNaverGameSdkModule::OnReceiveInGameMenuCode;

class NaverGameSdkModule : public FNaverGameSdkModule
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(NaverGameSdkModule, NaverGameSdk)

void NaverGameSdkModule::StartupModule()
{
    // This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}

void NaverGameSdkModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}
