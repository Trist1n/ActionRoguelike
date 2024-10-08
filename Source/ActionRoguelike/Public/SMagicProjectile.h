// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ASMagicProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASMagicProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> SphereComp;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileComp;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystemComponent> EffectComp;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
