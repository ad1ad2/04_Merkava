// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("No tank is being possessed by player"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()){return; }
    FVector HitLocation; // Out parameter
    if (GetSightRayHitLocation(HitLocation))
    {
        //UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
        //tell controlled tank to aim barrel at this point
    }
    
    //get world location of linetrace through crosshair
    //if it hits landscape
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    int32 ViewPortSizeX, ViewPortSizeY;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);
    auto ScreenLocation = FVector2D(CrosshairXLocation * ViewPortSizeX, CrosshairYLocation * ViewPortSizeY);

    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
       UE_LOG(LogTemp, Warning, TEXT("LookDirection:%s"), *LookDirection.ToString());
    }
    
    return true;
}							

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation;
    return DeprojectScreenPositionToWorld
    (
        ScreenLocation.X, 
        ScreenLocation.Y, 
        CameraWorldLocation, 
        LookDirection
    );
}