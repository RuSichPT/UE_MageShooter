// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameSession.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"

void AMyGameSession::RegisterServer()
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();

	if (OnlineSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("OnlineSubsystem == nullptr"))
		return;
	}
	
	IOnlineSessionPtr Session = OnlineSubsystem->GetSessionInterface();

	FOnlineSessionSettings Settings;

	Settings.bIsDedicated = true; // выделенный сервер
	Settings.bIsLANMatch = true; // локальный матч
	Settings.bAllowJoinInProgress = true; // подключение в процессе самого сервера
	Settings.bShouldAdvertise = true; // наш сервер виден через систему онлайн, чтобы виден был в поиске
	Settings.bUsesPresence = true;
	Settings.NumPublicConnections = 16;

	Session->CreateSession(0, GameSessionName, Settings);
	UE_LOG(LogTemp, Log, TEXT("--------------------------Session created--------------------------"))

}
