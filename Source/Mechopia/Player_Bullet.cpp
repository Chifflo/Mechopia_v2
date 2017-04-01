// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Player_Bullet.h"


// Sets default values
APlayer_Bullet::APlayer_Bullet()
{
	Bullet_Speed = 100;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BulletSphere"));
}

// Called when the game starts or when spawned
void APlayer_Bullet::BeginPlay()
{
	Super::BeginPlay();
	Direction = GetActorForwardVector();
}

// Called every frame
void APlayer_Bullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (!Direction.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (Direction * DeltaTime * Bullet_Speed);
		SetActorLocation(NewLocation);
	}
}

