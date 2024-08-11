// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SItemChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	float TargetPitch;
public:
	// Sets default values for this actor's properties
	ASItemChest();

	
	void Interact_Implementation(APawn* InstigatorPawn) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> LidMesh;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
