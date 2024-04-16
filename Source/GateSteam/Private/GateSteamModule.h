#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FGateSteamModule : public IModuleInterface
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    TSharedPtr<class FGateSteamworksNative> GateSteamworksInstanceRef;
    #if WITH_STEAMSERVER
    TSharedPtr<class FGateSteamServer> GateSteamServerInstanceRef;
    #endif
    public:
    TSharedPtr<class FGateSteamworksNative> GetGateSteamworksInstance();
    #if WITH_STEAMSERVER
    TSharedPtr<class FGateSteamServer> GetGateSteamServerInstance();
    #endif
};