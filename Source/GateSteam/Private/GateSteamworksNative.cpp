#include "GateSteamworksNative.h"
#include "GateSteamDefs.h" // for GateSteam LOG

bool FGateSteamworksNative::GateSteam_Init()
{
    if ( SteamAPI_RestartAppIfNecessary( 480 ) ) // Replace with your App ID
	{
		return true;
	}

	if ( !SteamAPI_Init() )
	{
		UE_LOG(GateSteamLog,Error,TEXT("Error - Steam must be running to play this game, steam init failed)") );
		return true;
	}

    return false;
}

void FGateSteamworksNative::GateSteam_Shutdown()
{
    UE_LOG(GateSteamLog, Warning, TEXT("Steamworks API is shutdowned!"));
}


FString FGateSteamworksNative::GateSteam_PersonName()
{
    FString name = ANSI_TO_TCHAR(SteamFriends()->GetPersonaName());
    return name;
}

CSteamID FGateSteamworksNative::GateSteam_SteamID()
{
    CSteamID steamID = SteamUser()->GetSteamID();
    return steamID;
}

int FGateSteamworksNative::GateSteam_PlayerSteamLevel()
{
    int level =  SteamUser()->GetPlayerSteamLevel();
    return level;
}

int FGateSteamworksNative::GateSteam_GetPlayersNumer()
{
	SteamAPICall_t hSteamAPICall = SteamUserStats()->GetNumberOfCurrentPlayers();
	numberOfCurrentPlayersCallResult.Set( hSteamAPICall, this, &FGateSteamworksNative::OnGetNumberOfCurrentPlayers );
    return numOfPlayers;
}

void FGateSteamworksNative::OnGetNumberOfCurrentPlayers( NumberOfCurrentPlayers_t *pCallback, bool bIOFailure )
{
    if ( bIOFailure || !pCallback->m_bSuccess )
	{
		UE_LOG(GateSteamLog,Warning, TEXT("NumberOfCurrentPlayers_t failed!"));
		return;
	}

	UE_LOG(GateSteamLog,Warning, TEXT("Number of players currently playing: %d"), pCallback->m_cPlayers );
    numOfPlayers = pCallback->m_cPlayers;
}
