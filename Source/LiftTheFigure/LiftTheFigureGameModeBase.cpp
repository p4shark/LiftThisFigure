// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftTheFigureGameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

ALiftTheFigureGameModeBase::ALiftTheFigureGameModeBase()
{
	this->SetActorTickEnabled(true);
}


void ALiftTheFigureGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HowFigureToWin = UKismetMathLibrary::RandomIntegerInRange(2, 6);
	TypeFigure = UKismetMathLibrary::RandomIntegerInRange(0, 2);
	MainGameState = Cast<ALiftTheFigureGameStateBase>(UGameplayStatics::GetGameState(this));

	MainGameState->SetHowFigureToWin(HowFigureToWin);
	MainGameState->SetTypeFigure(TypeFigure);
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ALiftTheFigureGameModeBase::EndTime, 30, false);
}

void ALiftTheFigureGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	MainGameState->SetRemainingTime(UKismetSystemLibrary::K2_GetTimerRemainingTimeHandle(this,Timer));
	if(MainGameState->GetHowFigureNow()>=HowFigureToWin)
	{
		bVictory = true;
		UKismetSystemLibrary::K2_PauseTimerHandle(this, Timer);
		EndGame();
	}
}

void ALiftTheFigureGameModeBase::EndGame()
{
	MainGameState->Multicast_EndGame(bVictory);
}

void ALiftTheFigureGameModeBase::EndTime()
{
	UKismetSystemLibrary::K2_ClearTimerHandle(this,Timer);
	UKismetSystemLibrary::K2_InvalidateTimerHandle(Timer);
	EndGame();
}

