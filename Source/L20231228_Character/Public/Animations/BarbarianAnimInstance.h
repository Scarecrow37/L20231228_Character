// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BarbarianAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class L20231228_CHARACTER_API UBarbarianAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UBarbarianAnimInstance();

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	bool IsFalling;
};
