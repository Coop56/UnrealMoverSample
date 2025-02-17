// Copyright Jeremiah Cooper. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MoverSampleBasePawn.h"
#include "MoverSamplePlayerPawn.generated.h"

/**
 * 
 */
UCLASS()
class UNREALMOVERSAMPLE_API AMoverSamplePlayerPawn : public AMoverSampleBasePawn
{
	GENERATED_BODY()

public:
	AMoverSamplePlayerPawn();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* SpringArmComponent;
};
