// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ASPlayerController();
	
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> MappingContext;
	
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> TurnAction;

	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> PrimaryAttackAction;

	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> JumpAction;

	
	virtual void SetupInputComponent() override;
	
	void Move(const FInputActionValue& InputActionValue);

	void Turn(const FInputActionValue& InputActionValue);

	void PrimaryAttack(const FInputActionValue& InputActionValue);

	void Jump(const FInputActionValue& InputActionValue);
};
