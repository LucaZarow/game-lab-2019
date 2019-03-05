// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AiPerceptionFunctionLibrary.generated.h"
#include "Classes/AIController.h"

/**
 * 
 */
UCLASS()
class GAMELAB19_API UAiPerceptionFunctionLibrary : public UObject
{
	GENERATED_BODY()

public:
	bool SetSightRadiusRange(AAIController* Controller, float newRange);
	
};
