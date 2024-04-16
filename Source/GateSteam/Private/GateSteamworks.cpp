#include "GateSteamworks.h"
#include "GateSteamDefs.h"
#include "GateSteamModule.h"
#if WITH_STEAMSERVER
#include "GateSteamServer.h"
#else
#include "GateSteamworksNative.h"
#endif

UGateSteamworks::UGateSteamworks()
{
    FGateSteamModule *gateSteamModule = &FModuleManager::LoadModuleChecked<FGateSteamModule>(FName("GateSteam"));
    #if WITH_STEAMSERVER
    #else
        GateSteamworksInstanceRef = gateSteamModule->GetGateSteamworksInstance();
    #endif
    AddToRoot();
}

UGateSteamworks::~UGateSteamworks()
{

}

bool UGateSteamworks::GateSteam_ClientInit()
{
    return GateSteamworksInstanceRef->GateSteam_Init();
}
