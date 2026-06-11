#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NetBaseCharacter.generated.h"

UCLASS()
class ASSIGNMENT2_KAAN_API ANetBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ANetBaseCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MovementScale;

    FTimerHandle WaitStateTimer;

    UFUNCTION(BlueprintCallable, Category = "Network")
    void CheckPlayerState();

    UFUNCTION(BlueprintCallable, Category = "Network")
    void SubmitPlayerInfo();

    // Slayttaki materyal rengi ve 30 saniye kuralýný tetikleyecek event
    UFUNCTION(BlueprintImplementableEvent, Category = "Network")
    void OnPlayerInfoChanged();
};