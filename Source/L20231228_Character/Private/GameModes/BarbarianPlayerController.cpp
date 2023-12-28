// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/BarbarianPlayerController.h"
#include "EnhancedInputSubsystems.h"

void ABarbarianPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Set enhanced input system.
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(Subsystem)) return; // TODO Debug log
	if (!InputContext) return; // TODO Debug log
	Subsystem->AddMappingContext(InputContext, 0);
}
