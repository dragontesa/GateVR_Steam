#pragma once
#include "steam_api.h"
#include "CoreMinimal.h"

class GATESTEAM_API FGateSteamworksNative
{
    public:
    bool GateSteam_Init();
    void GateSteam_Shutdown();

    // Steam Apps

    // Steam Friends
    FString GateSteam_PersonName();


    // Steam User
    bool GateSteam_UserLoggedOn();
    CSteamID GateSteam_SteamID();
    int GateSteam_PlayerSteamLevel();

    // Steam User Stat
    int GateSteam_GetPlayersNumer();

    private:
    void OnGetNumberOfCurrentPlayers( NumberOfCurrentPlayers_t *pCallback, bool bIOFailure );
	CCallResult< FGateSteamworksNative, NumberOfCurrentPlayers_t > numberOfCurrentPlayersCallResult;
    int numOfPlayers;


    

};

