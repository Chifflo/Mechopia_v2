// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "PlayerBullet.h"


// Sets default values
APlayerBullet::APlayerBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation.
	MeshComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	// Set the sphere's collision radius.
	MeshComponent->InitSphereRadius(15.0f);
	// Set the root component to be the collision component.
	RootComponent = MeshComponent;

	Speed = 500;
}

// Called when the game starts or when spawned
void APlayerBullet::BeginPlay()
{
	Super::BeginPlay();
	Forward = GetActorForwardVector();
}

// Called every frame
void APlayerBullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector Location = GetActorLocation();

	SetActorLocation(Location + (Forward * DeltaTime * Speed));
	
}
