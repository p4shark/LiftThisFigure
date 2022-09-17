// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftTheFigureGameState.h"

#include "GameFramework/GameSession.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


void ALiftTheFigureGameStateBase::SetHowFigureToWin(int32 TemporaryHowFigureToWin)
{
	HowFigureToWin = TemporaryHowFigureToWin;
}

void ALiftTheFigureGameStateBase::SetHowFigureNow(int32 TemporaryHowFigureNow)
{
	HowFigureNow = TemporaryHowFigureNow;
}


void ALiftTheFigureGameStateBase::SetTypeFigure(int32 TemporaryTypeFigure)
{
	TypeFigure = TemporaryTypeFigure;
}

void ALiftTheFigureGameStateBase::SetRemainingTime(float TemporaryRemainingTime)
{
	RemainingTime = TemporaryRemainingTime;
}

int32 ALiftTheFigureGameStateBase::GetHowFigureToWin() const
{
	return HowFigureToWin;
}

int32 ALiftTheFigureGameStateBase::GetTypeFigure() const
{
	return TypeFigure;
}

int32 ALiftTheFigureGameStateBase::GetHowFigureNow() const
{
	return  HowFigureNow;
}

int32 ALiftTheFigureGameStateBase::GetTime() const
{
	return RemainingTime;
}

void ALiftTheFigureGameStateBase::AddFigure()
{
	HowFigureNow++;
	OnRep_HowFigureNow();
}

void ALiftTheFigureGameStateBase::Message_Implementation(float Time, FName Name)
{
	IMessage::Message_Implementation(Time, Name);
	RequestTimeReload.Broadcast(Time,Name);
}

float ALiftTheFigureGameStateBase::GetRemainingTime_Implementation()
{
	IRound::GetRemainingTime_Implementation();
	return RemainingTime;
}

void ALiftTheFigureGameStateBase::Multicast_EndGame_Implementation(bool bTemporaryVictory)
{
	if(!UKismetSystemLibrary::IsDedicatedServer(this))
	{
		K2_PlayerEndGame(bTemporaryVictory);
	}
}

void ALiftTheFigureGameStateBase::OnRep_HowFigureNow()
{
	ChangeHowFigureNow.Broadcast(HowFigureNow);
}

void ALiftTheFigureGameStateBase::OnRep_HowFigureToWin()
{
	ChangeHowFigureNeedToWin.Broadcast(HowFigureToWin);
}

void ALiftTheFigureGameStateBase::OnRep_TypeFigure()
{
	ChangeTypeFigureToWin.Broadcast(TypeFigure);
}
void ALiftTheFigureGameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALiftTheFigureGameStateBase, TypeFigure);
	DOREPLIFETIME(ALiftTheFigureGameStateBase, HowFigureToWin);
	DOREPLIFETIME(ALiftTheFigureGameStateBase, HowFigureNow);
	DOREPLIFETIME(ALiftTheFigureGameStateBase, RemainingTime);
}