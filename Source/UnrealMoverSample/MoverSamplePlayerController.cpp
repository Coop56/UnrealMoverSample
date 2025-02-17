// Copyright Jeremiah Cooper. All Rights Reserved.

#include "MoverSamplePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMoverSamplePlayerController::AMoverSamplePlayerController()
{
}

void AMoverSamplePlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Add Input Mapping Context
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}

void AMoverSamplePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMoverSamplePlayerController::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMoverSamplePlayerController::Look);
    }
}

void AMoverSamplePlayerController::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();

    if (APawn* ControlledPawn = GetPawn())
    {
        const FRotator Rotation = GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Forward/Backward direction
        if (MovementVector.Y != 0.f)
        {
            const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
            ControlledPawn->AddMovementInput(Direction, MovementVector.Y);
        }

        // Right/Left direction
        if (MovementVector.X != 0.f)
        {
            const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
            ControlledPawn->AddMovementInput(Direction, MovementVector.X);
        }
    }
}

void AMoverSamplePlayerController::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxisVector = Value.Get<FVector2D>();

    AddYawInput(LookAxisVector.X);
    AddPitchInput(LookAxisVector.Y);
}

