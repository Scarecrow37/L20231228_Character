// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/BarbarianGameMode.h"

#include "GameModes/BarbarianCharacter.h"
#include "GameModes/BarbarianPlayerController.h"

ABarbarianGameMode::ABarbarianGameMode()
{
	PlayerControllerClass = ABarbarianPlayerController::StaticClass();
	DefaultPawnClass = ABarbarianCharacter::StaticClass();
}
