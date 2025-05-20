// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
    
    if (HasAuthority())
    {
        SetReplicates(true);
        SetReplicateMovement(true);
    }
} 

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority())                             // 자신이 서버인지 bool로 리턴(true면 서버, false면 클라이언트)
    {
        FVector Location = GetActorLocation();
        Location += FVector(MovingSpeed * DeltaTime, 0, 0);
        SetActorLocation(Location);
    }
     
}

  
