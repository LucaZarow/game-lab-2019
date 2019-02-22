// Fill out your copyright notice in the Description page of Project Settings.

#include "Twitch.h"
#include <string>

// Sets default values
ATwitch::ATwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATwitch::BeginPlay()
{
	Super::BeginPlay();
	
	VotingSystem();
}

// Called every frame
void ATwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATwitch::VotingSystem()
{
	ConnectTwitchAPI();
	UE_LOG(LogTemp, Warning, TEXT("Voting Begins"));
	// Comments Recieving Frequency is 0.1 sec
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATwitch::CountVote, 0.1f, true);
	// Destroy Count Vote
	GetWorld()->GetTimerManager().SetTimer(DestoryTimerHandle, this, &ATwitch::DestoryCountVote, 0.1f, false, VotingTime);
}

void ATwitch::CountVote()
{
	int result;
	FString OutMessage;
	if (ReceiveData(OutMessage))
	{
		// Vote result
		DetectKeyWord("$OP1$", "$OP2$", OutMessage, result);
		if (result == 1)
		{
			UE_LOG(LogTemp, Warning, TEXT("Result: %i"), result);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, *OutMessage);
		}
		if (result == 2)
		{
			UE_LOG(LogTemp, Warning, TEXT("Result: %i"), result);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, *OutMessage);
		}
	}
}

void ATwitch::DestoryCountVote()
{
	UE_LOG(LogTemp, Warning, TEXT("Voting has now ended"));
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
	GetWorld()->GetTimerManager().SetTimer(VotingTimerHandel, this, &ATwitch::VotingSystem, 0.1f, false, VotingCycle);

	this->CurrentSocket->Close();
}

bool ATwitch::ConnectTwitchAPI()
{
	if (Connect())
	{
		return Authentication();
	}
	return false;
}

// Setup initial Info (twitch oauth, username and channel)
void ATwitch::SetInitialInfo(FString Oauth, FString Username, FString Channel)
{
	this->Oauth = Oauth;
	this->Username = Username;
	this->Channel = Channel;
	if (!Oauth.IsEmpty() && !Username.IsEmpty() && !Channel.IsEmpty())
	{
		InfoInitialized = true;
	}
}

bool ATwitch::Connect()
{
	auto SocketSub = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	auto HostAddr = SocketSub->CreateInternetAddr();
	auto HostResolveError = SocketSub->GetHostByName("irc.twitch.tv", *HostAddr);
	HostAddr->SetPort(6667);

	// Create Socket
	FSocket* Socket = SocketSub->CreateSocket(NAME_Stream, TEXT("Socket"), false);
	if (Socket == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create socket"));
		return false;
	}

	int32 NewSize;
	Socket->SetReceiveBufferSize(1024 * 1024, NewSize);
	Socket->SetReuseAddr(true);

	// Check Connection
	if (!Socket->Connect(*HostAddr))
	{
		Socket->Close();
		SocketSub->DestroySocket(Socket);
		UE_LOG(LogTemp, Error, TEXT("Failed to connect"));
		return false;
	}

	this->CurrentSocket = Socket;
	return true;
}

bool ATwitch::Authentication()
{

	if (CurrentSocket == nullptr || !InfoInitialized)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to connect"));
		return false;
	}

	// Send oauth user and channel to twitch
	bool PassOK = SendIRCMessage("PASS " + this->Oauth);
	bool UserOK = SendIRCMessage("NICK " + this->Username);
	bool ChanOK = SendIRCMessage("JOIN #" + this->Channel);

	bool Success = PassOK && UserOK && ChanOK;
	if (!Success)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Authenticate"));
		return false;
	}
	return true;
}

bool ATwitch::SendIRCMessage(FString FMessage)
{
	// Cast FString to TCHAR
	FMessage += "\n";
	TCHAR* TMessage = FMessage.GetCharArray().GetData();

	// Send message to twitch
	int32 OutSent;
	return CurrentSocket->Send((uint8*)TCHAR_TO_UTF8(TMessage), FCString::Strlen(TMessage), OutSent);
}

bool ATwitch::ReceiveData(FString& OutMessage) const
{
	// Check if Socket is intialized
	if (CurrentSocket == nullptr)
	{
		return false;
	}

	TArray<uint8> Data;
	uint32 Size;
	bool HasData = false;
	if (CurrentSocket->HasPendingData(Size))
	{
		HasData = true;
		Data.SetNumUninitialized(Size);
		int32 data_read;
		CurrentSocket->Recv(Data.GetData(), Data.Num(), data_read);
	}

	FString Message = "";
	if (HasData)
	{
		// uint8 to char
		const std::string c_string_data(reinterpret_cast<const char*>(Data.GetData()), Data.Num());
		// TCHAR to FString
		Message = FString(c_string_data.c_str());
	}

	if (Message != "")
	{
		OutMessage = Message;
		return true;
	}

	return false;
}

void ATwitch::DetectKeyWord(FString OptionOne, FString OptionTwo, FString Message, int& result) const
{
	if (Message.Contains(OptionOne))
	{
		result = 1;
		return;
	}
	if (Message.Contains(OptionTwo))
	{
		result = 2;
		return;
	}
	result = -1;
	return;
}