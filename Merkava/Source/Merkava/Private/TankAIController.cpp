// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found no PlayerController possessed tank!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found PlayerController possessing: %s"), *(PlayerTank->GetName()));
    } 
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; } // Note the !, very important
	return Cast<ATank>(PlayerPawn);
}
ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
