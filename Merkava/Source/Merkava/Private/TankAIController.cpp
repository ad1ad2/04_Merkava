// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
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

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
    if (GetPlayerTank())
    {
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    }
    
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; } 
	return Cast<ATank>(PlayerPawn);
}
ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
