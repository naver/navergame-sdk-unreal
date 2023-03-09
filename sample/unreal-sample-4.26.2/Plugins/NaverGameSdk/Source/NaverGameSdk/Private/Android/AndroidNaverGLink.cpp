#include "AndroidNaverGLink.h"
#include "NaverGameSdkPrivatePCH.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"

FAndroidNaverGLink::FAndroidNaverGLink()
{
	if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper");
		Method_Init = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "initModule", "(Landroid/app/Activity;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
		Method_FinishSdk = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "finishSdk", "()V", false);
		Method_StartHome = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "startHome", "(Landroid/app/Activity;)V", false);
		Method_StartSorry = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "startSorry", "(Landroid/app/Activity;)V", false);
		Method_StartBoard = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "startBoard", "(Landroid/app/Activity;I)V", false);
	    Method_StartFeed = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "startFeed", "(Landroid/app/Activity;IZ)V", false);
	    Method_GetCountryCode = FJavaWrapper::FindStaticMethod(Env, localGlinkClass,"getCountryCode", "(Landroid/app/Activity;)Ljava/lang/String;", false);

		Method_SetCanWriteFeedByScreenshot = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "setEnableScreenShot", "(Z)V", false);
		Method_StartFeedWriting = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "writeFeed", "(Landroid/app/Activity;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
		Method_SetGameId = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "putGameId", "(Landroid/app/Activity;Ljava/lang/String;)V", false);

		Method_NaverLogout = FJavaWrapper::FindStaticMethod(Env, localGlinkClass, "logout", "(Landroid/app/Activity;)V", false);
		
		Env->DeleteLocalRef(localGlinkClass);
	}
}
 
 

FString FAndroidNaverGLink::GetCountryCode() const
{
    if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
    {
        jstring countryCodeJstr = nullptr;
        jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper"); 
        countryCodeJstr = (jstring)Env->CallStaticObjectMethod(localGlinkClass, Method_GetCountryCode, FJavaWrapper::GameActivityThis);
        Env->DeleteLocalRef(localGlinkClass);
        
        const char* CountryCodeChars = Env->GetStringUTFChars(countryCodeJstr, 0);   
        FString countryCode = UTF8_TO_TCHAR(CountryCodeChars);
        Env->ReleaseStringUTFChars(countryCodeJstr, CountryCodeChars);    
    
        return countryCode;
    }
    return "";
}
 
void FAndroidNaverGLink::Init(FString ClientId, FString ClientSecret, FString LoungeId) const
{
	if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper");
    
	    jstring LoungeIdJava = Env->NewStringUTF(TCHAR_TO_UTF8(*LoungeId));
        jstring ClientIdJava = Env->NewStringUTF(TCHAR_TO_UTF8(*ClientId));
        jstring ClientSecretJava = Env->NewStringUTF(TCHAR_TO_UTF8(*ClientSecret));

		Env->CallStaticVoidMethod(localGlinkClass, Method_Init, FJavaWrapper::GameActivityThis,LoungeIdJava,ClientIdJava,ClientSecretJava);
		
        Env->DeleteLocalRef(LoungeIdJava);
        Env->DeleteLocalRef(ClientIdJava);
        Env->DeleteLocalRef(ClientSecretJava);
		
		Env->DeleteLocalRef(localGlinkClass);
	}

}




void FAndroidNaverGLink::SetGameId(FString GameId) const {
    if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper"); 

		jstring gameId = Env->NewStringUTF(TCHAR_TO_UTF8(*GameId));

	    Env->CallStaticVoidMethod(localGlinkClass, Method_SetGameId, FJavaWrapper::GameActivityThis,gameId);


		Env->DeleteLocalRef(gameId);
		Env->DeleteLocalRef(localGlinkClass);
	}
	
}

void FAndroidNaverGLink::SetCanWriteFeedByScreenshot(bool Enabled) const {
    if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper"); 
	    Env->CallStaticVoidMethod(localGlinkClass, Method_SetCanWriteFeedByScreenshot, Enabled);
	    Env->DeleteLocalRef(localGlinkClass);
	}
	
}

void FAndroidNaverGLink::StartFeedWriting(int BoardId, FString Title, FString Text, FString ImageFilePath) const {
    if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper"); 

	    jstring TitleJava = Env->NewStringUTF(TCHAR_TO_UTF8(*Title));
        jstring TextJava = Env->NewStringUTF(TCHAR_TO_UTF8(*Text));
        jstring ImagePathJava = Env->NewStringUTF(TCHAR_TO_UTF8(*ImageFilePath));

	    Env->CallStaticVoidMethod(localGlinkClass, Method_StartFeedWriting, FJavaWrapper::GameActivityThis,BoardId,TitleJava,TextJava,ImagePathJava);
	    

		Env->DeleteLocalRef(TitleJava);
        Env->DeleteLocalRef(TextJava);
        Env->DeleteLocalRef(ImagePathJava);

		Env->DeleteLocalRef(localGlinkClass);

	}
	
}


void FAndroidNaverGLink::StartHome() const {
    if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper"); 
	    Env->CallStaticVoidMethod(localGlinkClass, Method_StartHome, FJavaWrapper::GameActivityThis);
	    Env->DeleteLocalRef(localGlinkClass);
	}
	
}

void FAndroidNaverGLink::StartSorry() const {
if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper");
	    Env->CallStaticVoidMethod(localGlinkClass, Method_StartSorry, FJavaWrapper::GameActivityThis);
	    Env->DeleteLocalRef(localGlinkClass);
	}
}

void FAndroidNaverGLink::StartBoard(int BoardId) const {
if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper");
	    Env->CallStaticVoidMethod(localGlinkClass, Method_StartBoard, FJavaWrapper::GameActivityThis,BoardId);
	    Env->DeleteLocalRef(localGlinkClass);
	}
}

void FAndroidNaverGLink::StartFeed(int FeedId, bool IsTempFeedId) const {
if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper");
	    Env->CallStaticVoidMethod(localGlinkClass, Method_StartFeed, FJavaWrapper::GameActivityThis,FeedId,IsTempFeedId);
	    Env->DeleteLocalRef(localGlinkClass);
	}
}

void FAndroidNaverGLink::FinishSdk() const {
    if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
	    jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper"); 
	    Env->CallStaticVoidMethod(localGlinkClass, Method_FinishSdk);
	    Env->DeleteLocalRef(localGlinkClass);
	}
	
}
void FAndroidNaverGLink::NaverLogout() const {
	if (JNIEnv * Env = FAndroidApplication::GetJavaEnv())
	{
		jclass localGlinkClass = FAndroidApplication::FindJavaClass("com.navercorp.nng.android.sdk.NngNdkWrapper"); 
		Env->CallStaticVoidMethod(localGlinkClass, Method_NaverLogout, FJavaWrapper::GameActivityThis);
		Env->DeleteLocalRef(localGlinkClass);
	}
	
}

void FAndroidNaverGLink::SetAppName(FString AppName) const {
    //DO NOTHING
}
void FAndroidNaverGLink::SetAppScheme(FString AppName) const {
    //DO NOTHING
}
FString FAndroidNaverGLink::GetAuthSettingDescription() const {
    //DO NOTHING
    return "";
}

extern "C" void Java_com_navercorp_nng_android_sdk_NngNdkWrapper_nngSdkLoaded(JNIEnv *env, jobject thisObj) {
   FNaverGameSdkModule::OnSdkStarted.Broadcast();
   return;
}
extern "C" void Java_com_navercorp_nng_android_sdk_NngNdkWrapper_nngSdkUnLoaded(JNIEnv *env, jobject thisObj) {
    FNaverGameSdkModule::OnSdkStopped.Broadcast();
   return;
}
extern "C" void Java_com_navercorp_nng_android_sdk_NngNdkWrapper_nngSdkCallInGameMenuCode(JNIEnv *env, jobject thisObj, jstring inGameMenuCode)
{
    const char* AppInGameMenuCodeChars = env->GetStringUTFChars(inGameMenuCode, 0);   
    
    FString inGameMenuCodeString = UTF8_TO_TCHAR(AppInGameMenuCodeChars);
    FNaverGameSdkModule::OnReceiveInGameMenuCode.Broadcast(inGameMenuCodeString);

    env->ReleaseStringUTFChars(inGameMenuCode, AppInGameMenuCodeChars);
}