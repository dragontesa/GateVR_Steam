#pragma once

#include "CoreMinimal.h"
#include "Core.h"

#include "GateSteamworks.generated.h"


UCLASS()
class GATESTEAM_API UGateSteamworks: public UObject
{
    GENERATED_BODY()
    public:
    UGateSteamworks();
    ~UGateSteamworks();

    bool GateSteam_ClientInit();

    private:
    TSharedPtr<class FGateSteamworksNative> GateSteamworksInstanceRef;
};

