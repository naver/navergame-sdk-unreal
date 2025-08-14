// Fill out your copyright notice in the Description page of Project Settings.
#include "NaverGLink.h"
#include "NaverGameSdkPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidNaverGLink.h"

    FAndroidNaverGLink* GetSharedAndroidSdk()
    {
        static FAndroidNaverGLink* Glink = nullptr;
        if (Glink == nullptr)
        {
            Glink = new FAndroidNaverGLink();
        }
        return Glink;
    }
    
    INaverGLink* GetSharedSdk()
    {
        return GetSharedAndroidSdk();
    }
   

#elif PLATFORM_IOS

    #include "IOS/IOSNaverGLink.h"
    
    FIOSNaverGLink* GetSharedIOSSdk()
    {
        static FIOSNaverGLink* GLink = nullptr;
        if (GLink == nullptr)
        {
            GLink = new FIOSNaverGLink();
        }
        return GLink;
    }
    INaverGLink* GetSharedSdk()
    {
        return GetSharedIOSSdk();
    }


#else

    #include "NaverGLink.h"
    
    INaverGLink* GetSharedSdk()
    {
        return nullptr;
    }
    

#endif

bool IsSdkAvailable()
{
    return GetSharedSdk() != nullptr;
}

