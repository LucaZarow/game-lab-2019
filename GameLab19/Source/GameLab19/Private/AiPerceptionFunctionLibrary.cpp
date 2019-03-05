// Fill out your copyright notice in the Description page of Project Settings.

#include "AiPerceptionFunctionLibrary.h"
#include "AIPerceptionTypes.generated.h"
#include "AISense.generated.h"
#include "AISense_Sight.generated.h"
#include "AISenseConfig.generated.h"

bool UAiPerceptionFunctionLibrary::SetSightRadiusRange(AAIController* Controller, float newRange) {

	if (Controller == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Controller == nullptr"));
		return false;
	}

	//FAISenseID Id = UAISense::GetSenseID(UAISense_Sight::StaticClass());
	return true;
}
