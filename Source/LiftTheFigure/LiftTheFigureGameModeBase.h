// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LiftTheFigureGameState.h"
#include "GameFramework/GameModeBase.h"
#include "LiftTheFigureGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LIFTTHEFIGURE_API ALiftTheFigureGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
private:
	int32 HowFigureToWin;
	int32 TypeFigure;
	FTimerHandle Timer;
	bool bVictory;
	UPROPERTY()
	ALiftTheFigureGameStateBase * MainGameState;

	void EndedGame();
	UFUNCTION()
	void EndGame();
	UFUNCTION()
	void CheckVictory(int32 TemparyHowNow);
	
public:
	ALiftTheFigureGameModeBase();
};
