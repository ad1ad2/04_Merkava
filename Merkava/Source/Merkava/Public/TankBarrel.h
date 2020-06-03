// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories = ("Collision") )
class MERKAVA_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, category = Setup)
	float MaxDegreesPerSecond = 20;
	
	UPROPERTY(EditAnywhere, category = Setup)
	float MaxElevation = 45;
	
	UPROPERTY(EditAnywhere, category = Setup)
	float MinElevation = 0;
};
