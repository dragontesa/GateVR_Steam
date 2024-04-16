#include "GateSteamServer.h"
#include "GateSteamDefs.h"

FGateSteamServer::FGateSteamServer()
{

}

FGateSteamServer::~FGateSteamServer()
{
}


bool FGateSteamServer::GateSteamServer_Init(
      uint32 unIP
    , uint16 usGamePort
    , uint16 usQueryPort)
{
    const char* vers = "2023.12.11";
    bool success = SteamGameServer_Init(
        unIP
        ,usGamePort
        ,usQueryPort
        ,eServerModeAuthentication
        ,vers);

    return success;
}

void FGateSteamServer::GateSteamServer_Shutdown()
{
    SteamGameServer_Shutdown();
}

void FGateSteamServer::GateSteamServer_RunCallbacks()
{
    SteamGameServer_RunCallbacks();
}