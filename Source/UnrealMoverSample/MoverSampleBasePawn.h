// Copyright Jeremiah Cooper. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MoverSampleBasePawn.generated.h"

class UMoverComponent;

UCLASS(Abstract)
class UNREALMOVERSAMPLE_API AMoverSampleBasePawn : public APawn
{
	GENERATED_BODY()

public:
	AMoverSampleBasePawn();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UMoverComponent* MoverComponent;
};
