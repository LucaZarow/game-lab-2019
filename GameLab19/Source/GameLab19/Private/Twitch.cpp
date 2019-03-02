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
}

// Called every frame
void ATwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATwitch::SetVotingItems(FString VotingItem1, FString VotingItem2, FString VotingItem3, FString VotingItem4, FString VotingItem5)
{
	this->VotingItem1 = VotingItem1;
	this->VotingItem2 = VotingItem2;
	this->VotingItem3 = VotingItem3;
	this->VotingItem4 = VotingItem4;
	this->VotingItem5 = VotingItem5;
	ItemsInitialized = true;
}

void ATwitch::StartVote()
{
	VoteCounts.Init(-1, 5);
	if (RandomItemsGenerated == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("3 Random Items needs to be generated first"));
		return;
	}
	VoteCounts[RandomItem1 - 1] = 0;
	VoteCounts[RandomItem2 - 1] = 0;
	VoteCounts[RandomItem3 - 1] = 0;

	UE_LOG(LogTemp, Warning, TEXT("Op %i, Op %i, Op %i"), RandomItem1, RandomItem2, RandomItem3);

	ConnectTwitchAPI();
	UE_LOG(LogTemp, Warning, TEXT("Voting Begins"));
	// Comments Recieving Frequency is 0.1 sec
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATwitch::CountVote, 0.1f, true);

	// Use Blueprint instead
	// Destroy Count Vote
	//GetWorld()->GetTimerManager().SetTimer(DestoryTimerHandle, this, &ATwitch::DestoryCountVote, 0.1f, false, VotingTime);
}

void ATwitch::CountVote()
{
	FString User;
	int32 Result;
	FString OutMessage;
	if (ReceiveData(OutMessage))
	{
		// Parse String
		DetectKeyWord(OutMessage, User, Result);
		
		//UE_LOG(LogTemp, Warning, TEXT("Result: %i"), Result);

		if (!VoteResults.Contains(User) && (Result == RandomItem1 || Result == RandomItem2 || Result == RandomItem3))
		{
			VoteResults.Emplace(User, Result);
			VoteCounts[Result-1] += 1;
			UE_LOG(LogTemp, Warning, TEXT("%s Votes option %i, total of %i people have voted option %i"), *User, Result, VoteCounts[Result - 1], Result);
		}
		else if(Result == RandomItem1 || Result == RandomItem2 || Result == RandomItem3)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s has voted"), *User);
		}
	}
}

void ATwitch::DetectKeyWord(FString Message, FString& User, int32& Result) const
{
	// Parse User Message
	TArray<FString> MessageArray = TArray<FString>();
	Message.ParseIntoArray(MessageArray, TEXT(" "));
	// Parse User Name
	TArray<FString> UserParse = TArray<FString>();
	const TCHAR* Delims[] = { TEXT(":"), TEXT("."), TEXT("!")};
	MessageArray[0].ParseIntoArray(UserParse, Delims, 3);
	User = UserParse[0];
	Result = 0;

	// Detect first keyword in user's message
	int32 i = 3;
	bool KeywordDetected = false;
	while (i < MessageArray.Num() && KeywordDetected == false)
	{
		FString UserMessage = MessageArray[i].ToLower();
		if (UserMessage.Contains(VotingItem1))
		{
			KeywordDetected = true;
			Result = 1;
		}
		else if (UserMessage.Contains(VotingItem2))
		{
			KeywordDetected = true;
			Result = 2;
		}
		else if (UserMessage.Contains(VotingItem3))
		{
			KeywordDetected = true;
			Result = 3;
		}
		else if (UserMessage.Contains(VotingItem4))
		{
			KeywordDetected = true;
			Result = 4;
		}
		else if (UserMessage.Contains(VotingItem5))
		{
			KeywordDetected = true;
			Result = 5;
		}
		i++;
	}
	return;
}

void ATwitch::DestroyCountVote(int32& FinalResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Voting has now ended"));
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
	//GetWorld()->GetTimerManager().SetTimer(VotingTimerHandel, this, &ATwitch::VotingSystem, 0.1f, false, VotingCycle);

	this->CurrentSocket->Close();

	// Find the most voted option
	int32 Index = FMath::RandRange(1, 5);
	float MaxVal = -1;
	for (int32 i = 0; i < 5; i++)
	{
		float Value = VoteCounts[i] + FMath::RandRange(-0.3f, 0.3f);
		if (Value > MaxVal)
		{
			MaxVal = Value;
			Index = i + 1;
		}
	}

	if (MaxVal < 0.5)
	{
		UE_LOG(LogTemp, Warning, TEXT("No one voted"));
	}

	FinalResult = Index;
	UE_LOG(LogTemp, Warning, TEXT("Final result: Option %i"), FinalResult);

	RandomItem1 = 0;
	RandomItem2 = 0;
	RandomItem3 = 0;
	VoteResults.Empty();
	RandomItemsGenerated = false;
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

bool ATwitch::GenerateRandomVotingItems(int32& OutItem1, int32& OutItem2, int32& OutItem3)
{
	// Generate 3 random voting Item
	this->RandomItem1 = FMath::RandRange(1, 5);
	OutItem1 = this->RandomItem1;
	do
	{
		this->RandomItem2 = FMath::RandRange(1, 5);
		OutItem2 = this->RandomItem2;
	} while (this->RandomItem1 == this->RandomItem2);
	do
	{
		this->RandomItem3 = FMath::RandRange(1, 5);
		OutItem3 = this->RandomItem3;
	} while (this->RandomItem3 == this->RandomItem2 && this->RandomItem3 == this->RandomItem1);

	this->RandomItemsGenerated = true;
	return true;
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