#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NetGameInstance.h"
#include "NetPlayerState.generated.h"

UCLASS()
class ASSIGNMENT2_KAAN_API ANetPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    UPROPERTY(ReplicatedUsing = OnRep_PlayerInfo, EditAnywhere, BlueprintReadWrite, Category = "Network")
    FSPlayerInfo PlayerInfo;

    UFUNCTION()
    void OnRep_PlayerInfo();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};