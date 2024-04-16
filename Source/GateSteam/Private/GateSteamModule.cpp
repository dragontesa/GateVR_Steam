// #include "Modules/ModuleManager.h" 
#include "GateSteamModule.h"
#include "GateSteamDefs.h"
#if WITH_STEAMSERVER
#include "GateSteamServer.h"
#else
#include "GateSteamworksNative.h"
#endif

#define LOCTEXT_NAMESPACE "GateSteam"
DEFINE_LOG_CATEGORY(GateSteamLog);
IMPLEMENT_MODULE(FGateSteamModule, GateSteam);

void FGateSteamModule::StartupModule()
{
    // Init Steamworks API 
    #if WITH_STEAMSERVER
       GateSteamServerInstanceRef = MakeShareable(new FGateSteamServer());
       GateSteamServerInstanceRef->GateSteamServer_Init(INADDR_ANY,7777,27015);
    #else
       GateSteamworksInstanceRef = MakeShareable(new FGateSteamworksNative());
       GateSteamworksInstanceRef->GateSteam_Init();
    #endif
    
}

void FGateSteamModule::ShutdownModule()
{
    // Shutdown Steamworks API
    GateSteamworksInstanceRef->GateSteam_Shutdown();
}

TSharedPtr<FGateSteamworksNative> FGateSteamModule::GetGateSteamworksInstance()
{
    return GateSteamworksInstanceRef;
}

#if WITH_STEAMSERVER
TSharedPtr<class FGateSteamServer> FGateSteamModule::GetGateSteamServerInstance()
{
    return GateSteamServerInstanceRef;
}
#endif

#undef LOCTEXT_NAMESPACE