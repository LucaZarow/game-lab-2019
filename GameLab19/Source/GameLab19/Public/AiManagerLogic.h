// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AiManagerLogic.generated.h"
#include "Array.h"
#include "BaseEnemy"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMELAB19_API UAiManagerLogic : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAiManagerLogic();
	TArray<BaseEnemy> archers;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
