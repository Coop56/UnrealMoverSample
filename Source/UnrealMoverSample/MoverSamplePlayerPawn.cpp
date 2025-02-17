// Copyright Jeremiah Cooper. All Rights Reserved.

#include "MoverSamplePlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMoverSamplePlayerPawn::AMoverSamplePlayerPawn()
{
	// Create and setup capsule collision
	UCapsuleComponent* CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCylinder"));
	SetRootComponent(CapsuleComp);
	CapsuleComp->InitCapsuleSize(34.0f, 88.0f);

	// Create camera boom
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 300.0f;
	SpringArmComponent->bUsePawnControlRotation = true;

	// Create follow camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;
}
