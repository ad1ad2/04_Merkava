// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    //auto Time = GetWorld()->GetTimeSeconds();
    auto Name  = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle %f"), *Name, Throttle);
}
