// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/BarbarianAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UBarbarianAnimInstance::UBarbarianAnimInstance() : Velocity(FVector::Zero()), Speed(0.0f), IsFalling(false),
                                                   IsJumping(false), JumpingVelocity(100.0f), ShouldMove(false),
                                                   PreviousVelocity(FVector::Zero()), WalkSpeed(3.0f)
{
}

void UBarbarianAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();
	if (!IsValid(Pawn)) return; // TODO Debug log

	Velocity = Pawn->GetVelocity();

	FVector DeltaVector = Velocity - PreviousVelocity;
	PreviousVelocity = Velocity;
	FVector Acceleration = DeltaVector / DeltaSeconds;

	Speed = Velocity.Size();
	float GroundSpeed = Velocity.Size2D();

	ACharacter* Character = Cast<ACharacter>(Pawn);
	if (!IsValid(Character)) return; // TODO Debug log

	IsFalling = Character->GetMovementComponent()->IsFalling();

	IsJumping = IsFalling && Velocity.Z > JumpingVelocity;

	ShouldMove = Acceleration != FVector::Zero() && GroundSpeed > WalkSpeed;
}
