// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/BarbarianCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABarbarianCharacter::ABarbarianCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set spring arm for camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	// Set camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void ABarbarianCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABarbarianCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABarbarianCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!IsValid(EnhancedInputComponent)) return; // TODO Debug Log

	if (!IsValid(MoveAction)) return; // TODO Debug log
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,
	                                   &ABarbarianCharacter::MoveActionTriggered);

	if (!IsValid(JumpAction)) return; // TODO Debug log
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this,
	                                   &ABarbarianCharacter::JumpActionStarted);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this,
	                                   &ABarbarianCharacter::JumpActionCompleted);

	if (!IsValid(LookAction)) return; // TODO Debug log
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this,
	                                   &ABarbarianCharacter::LookActionTriggered);
}

void ABarbarianCharacter::MoveActionTriggered(const FInputActionValue& Value)
{
	FVector2d Vector2dValue = Value.Get<FVector2d>();
	AddMovementInput(GetActorForwardVector(), Vector2dValue.Y);
	AddMovementInput(GetActorRightVector(), Vector2dValue.X);
}

void ABarbarianCharacter::JumpActionStarted(const FInputActionValue& Value)
{
	Jump();
}

void ABarbarianCharacter::JumpActionCompleted(const FInputActionValue& Value)
{
	StopJumping();
}


void ABarbarianCharacter::LookActionTriggered(const FInputActionValue& Value)
{
	FVector2d Vector2dValue = Value.Get<FVector2d>();
	AddControllerYawInput(Vector2dValue.X);
	AddControllerPitchInput(Vector2dValue.Y);
}

