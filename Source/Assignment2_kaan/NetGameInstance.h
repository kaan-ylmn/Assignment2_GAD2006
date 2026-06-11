#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NetGameInstance.generated.h"

UENUM(BlueprintType)
enum class EPlayerTeam : uint8
{
    TEAM_Unknown    UMETA(DisplayName = "Unknown"),
    TEAM_Blue       UMETA(DisplayName = "Blue"),
    TEAM_Red        UMETA(DisplayName = "Red")
};

USTRUCT(BlueprintType)
struct FSPlayerInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
    FString Nickname;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
    EPlayerTeam Team;
};

UCLASS()
class ASSIGNMENT2_KAAN_API UNetGameInstance : public UGameInstance
{
    GENERATED_BODY()
};