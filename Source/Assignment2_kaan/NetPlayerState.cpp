#include "NetPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "NetBaseCharacter.h"

void ANetPlayerState::OnRep_PlayerInfo()
{
    if (APawn* MyPawn = GetPawn())
    {
        if (ANetBaseCharacter* MyChar = Cast<ANetBaseCharacter>(MyPawn))
        {
            MyChar->OnPlayerInfoChanged();
        }
    }
}

void ANetPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ANetPlayerState, PlayerInfo);
}