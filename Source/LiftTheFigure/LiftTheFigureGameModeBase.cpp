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
	MainGameState = Cast<ALiftTheFigureGameStateBase>(GameState);

	MainGameState->SetHowFigureToWin(HowFigureToWin);
	MainGameState->SetTypeFigure(TypeFigure);
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ALiftTheFigureGameModeBase::EndGame, 30, false);
	MainGameState->ChangeHowFigureNow.AddDynamic(this, &ALiftTheFigureGameModeBase::CheckVictory);
}

void ALiftTheFigureGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	MainGameState->SetRemainingTime(UKismetSystemLibrary::K2_GetTimerRemainingTimeHandle(this,Timer));
}

void ALiftTheFigureGameModeBase::EndedGame()
{
	MainGameState->Multicast_EndGame(bVictory);
}

void ALiftTheFigureGameModeBase::EndGame()
{
	UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(this,Timer);
	EndedGame();
}

void ALiftTheFigureGameModeBase::CheckVictory(int32 TemparyHowNow)
{
	if(TemparyHowNow>=HowFigureToWin)
	{
		bVictory = true;
		UKismetSystemLibrary::K2_PauseTimerHandle(this, Timer);
		EndedGame();
	}
}

