// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Projectile.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMELAB19_API UProjectile : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile")
		int Damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile")
		float range;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile")
		float speed;

#pragma region GeneratedFunctions
public:	
	// Sets default values for this component's properties
	UProjectile();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
#pragma endregion GeneratedFunctions

		
};
