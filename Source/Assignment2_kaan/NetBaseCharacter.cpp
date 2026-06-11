#include "NetBaseCharacter.h"
#include "NetPlayerState.h"

ANetBaseCharacter::ANetBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    MovementScale = 1.0f;
}

void ANetBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Zamanlayýcýyý baþlatarak her 0.5 saniyede bir PlayerState'i kontrol et
    GetWorldTimerManager().SetTimer(WaitStateTimer, this, &ANetBaseCharacter::CheckPlayerState, 0.5f, true);
}

void ANetBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ANetBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ANetBaseCharacter::CheckPlayerState()
{
    if (GetPlayerState<ANetPlayerState>())
    {
        // PlayerState geçerli olduðunda zamanlayýcýyý temizle ve veriyi gönder
        GetWorldTimerManager().ClearTimer(WaitStateTimer);
        SubmitPlayerInfo();
    }
}

void ANetBaseCharacter::SubmitPlayerInfo()
{
    // Blueprint tarafýnda kurgulayacaðýn Event'i tetikler
    OnPlayerInfoChanged();
}