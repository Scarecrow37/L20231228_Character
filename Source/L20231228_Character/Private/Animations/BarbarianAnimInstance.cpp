// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/BarbarianAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UBarbarianAnimInstance::UBarbarianAnimInstance() : Speed(0.0f), IsFalling(false)
{
}

void UBarbarianAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();
	if(!IsValid(Pawn)) return; // TODO Debug log
	Speed = Pawn->GetVelocity().Size();
	ACharacter* Character = Cast<ACharacter>(Pawn);
	if(!IsValid(Character)) return; // TODO Debug log
	IsFalling = Character->GetMovementComponent()->IsFalling();
}
