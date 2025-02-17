// Copyright Jeremiah Cooper. All Rights Reserved.

#include "MoverSampleBasePawn.h"

#include "MoverComponent.h"

AMoverSampleBasePawn::AMoverSampleBasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	MoverComponent = CreateDefaultSubobject<UMoverComponent>(TEXT("MoverComponent"));
}

void AMoverSampleBasePawn::BeginPlay()
{
	Super::BeginPlay();
}

void AMoverSampleBasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
