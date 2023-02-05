// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Critter.generated.h"

UENUM(BlueprintType)
enum class ECritterDeathType : uint8
{
	EDT_None,
	EDT_Fall,
	EDT_Shot,
	EDT_Explosion,
	EDT_Squished,
	EDT_Expired
};

UCLASS()
class BORTAL_API ACritter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACritter();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Critter")
	bool bIsAlive = true;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// create an event for the critter to die
	UFUNCTION(BlueprintCallable, Category = "Critter")
	void TriggerDeath(ECritterDeathType DeathType);
};
