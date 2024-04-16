#pragma once
#include "steam_gameserver.h"

class GATESTEAM_API FGateSteamServer
{
    public:
    FGateSteamServer();
    ~FGateSteamServer();

    bool GateSteamServer_Init(uint32 unIP, uint16 usGamePort, uint16 usQueryPort);
    void GateSteamServer_Shutdown();
    void GateSteamServer_RunCallbacks();
};