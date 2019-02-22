// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sockets.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Engine/World.h"
#include "Networking.h"
#include "Twitch.generated.h"

UCLASS()
class GAMELAB19_API ATwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetInitialInfo(const FString Oauth, const  FString Username, const FString Channel);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	bool ConnectTwitchAPI();

	bool Connect();

	bool Authentication();

	bool SendIRCMessage(FString _message);

	bool ReceiveData(FString& OutMessage) const;

	void DetectKeyWord(FString OptionOne, FString OptionTwo, FString Message, int& result) const;

	void VotingSystem();

	void CountVote(); 
	
	void DestoryCountVote();

	UPROPERTY(EditAnywhere, Category = "Setup")
	float VotingTime = 15.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float VotingCycle = 10.f;

protected:
	FTimerHandle VotingTimerHandel;
	FTimerHandle DestoryTimerHandle;
	FTimerHandle TimerHandle;
private:
	bool InfoInitialized = false;
	FString Oauth;
	FString Username;
	FString Channel;
	FSocket* CurrentSocket;
	bool VoteStart = false;
};
