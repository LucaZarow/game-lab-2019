// Fill out your copyright notice in the Description page of Project Settings.

#include "Twitch.h"
#include <string>

// Sets default values
ATwitch::ATwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If recieve a message, print to screen
	FString OutMessage;
	if (ReceiveData(OutMessage))
	{
		// Vote result
		int result = DetectKeyWord("$OP1$", "$OP2$", OutMessage);
		UE_LOG(LogTemp, Error, TEXT("Result: %i"), result);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, *OutMessage);
		
	}

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

int ATwitch::DetectKeyWord(FString OptionOne, FString OptionTwo, FString Message) const
{
	if (Message.Contains(OptionOne))
	{
		UE_LOG(LogTemp, Warning, TEXT("OP1"));
		return 1;
	}
	if (Message.Contains(OptionTwo))
	{
		UE_LOG(LogTemp, Warning, TEXT("OP2"));
		return 2;
	}
	return -1;
}

