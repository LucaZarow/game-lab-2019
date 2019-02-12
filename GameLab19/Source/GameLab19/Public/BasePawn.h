// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BasePawn.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMELAB19_API UBasePawn : public UActorComponent
{
	GENERATED_BODY()

public:
	// health proprety
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		bool isDead;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		int MaxHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		int CurrentHealth;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		bool hasMelee;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		int Melee_Damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		float Melee_AttackSp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		bool hasRange;
	// UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
	//	AActor Projectile;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Actor")
		float Range_AttackSp; // Attacks per second

	virtual void CalculateHealth(int addition);

	virtual void CheckDeath();

#pragma region GeneratedFunctions
public:	
	// Sets default values for this component's properties
	UBasePawn();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
#pragma endregion GeneratedFunctions
		
};
