// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerController.h"

#include "DetailLayoutBuilder.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SCharacter.h"


ASPlayerController::ASPlayerController()
{
}

void ASPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(MappingContext,0);
}

void ASPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(TurnAction,ETriggerEvent::Triggered,this, &ThisClass::Turn);
	EnhancedInputComponent->BindAction(PrimaryAttackAction, ETriggerEvent::Started, this, &ThisClass::PrimaryAttack);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
}

void ASPlayerController::Move(const FInputActionValue& InputActionValue)
{
	FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();

	FRotator YawRotation(0.f,GetControlRotation().Yaw, 0.f);

	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);
	}
}

void ASPlayerController::Turn(const FInputActionValue& InputActionValue)
{
	FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	AddYawInput(InputAxisVector.X);
	AddPitchInput(InputAxisVector.Y);
}

void ASPlayerController::PrimaryAttack(const FInputActionValue& InputActionValue)
{
	if(ASCharacter* ControlledCharacter = Cast<ASCharacter>(GetPawn()))
	{
		//
		FVector HandLocation = ControlledCharacter->GetMesh()->GetSocketLocation("Muzzle_01");
		FTransform Transform(GetControlRotation(), HandLocation);
		
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<AActor>(ControlledCharacter->ProjectileClass, Transform, SpawnParameters);
	}
}

void ASPlayerController::Jump(const FInputActionValue& InputActionValue)
{
	if(ASCharacter* ControlledCharacter = Cast<ASCharacter>(GetPawn()))
	{
		ControlledCharacter->Jump();
	}
}


