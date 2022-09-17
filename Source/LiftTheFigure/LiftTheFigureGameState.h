// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Message.h"
#include "Round.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "UObject/Object.h"
#include "LiftTheFigureGameState.generated.h"


/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChangedHowFigureNeedToWin , int32, Id);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChangedHowFigureNow, int32, HowNow);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChangedTypeFigureToWin, int32, HowAll);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRequestedInfoAboutReloadAbility, float, Time, FName, Name);
UCLASS()
class LIFTTHEFIGURE_API ALiftTheFigureGameStateBase : public AGameStateBase, public IRound, public IMessage
{
	GENERATED_BODY()
private:
	
	UPROPERTY(ReplicatedUsing=OnRep_HowFigureNow)
	int32 HowFigureNow;
	UPROPERTY(ReplicatedUsing=OnRep_HowFigureToWin)
	int32 HowFigureToWin;
	UPROPERTY(ReplicatedUsing=OnRep_TypeFigure)
	int32 TypeFigure;

	UPROPERTY(Replicated)
	float RemainingTime;

	UFUNCTION()
	void OnRep_HowFigureNow();
	UFUNCTION()
	void OnRep_HowFigureToWin();
	UFUNCTION()
	void OnRep_TypeFigure();
public:
	void SetHowFigureToWin(int32 TemporaryHowFigureToWin);
	void SetHowFigureNow(int32 TemporaryHowFigureNow);
	void SetTypeFigure(int32 TemporaryTypeFigure);
	void SetRemainingTime(float TemporaryRemainingTime);
	UFUNCTION(BlueprintCallable)
	int32 GetHowFigureToWin() const;
	UFUNCTION(BlueprintCallable)
	int32 GetTypeFigure() const;
	UFUNCTION(BlueprintCallable)
	int32 GetHowFigureNow() const;
	UFUNCTION(BlueprintCallable)
	int32 GetTime() const;
	
	UFUNCTION(BlueprintCallable)
	void AddFigure();

	UFUNCTION(NetMulticast,Unreliable)
	void Multicast_EndGame(bool bTemporaryVictory);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_PlayerEndGame(bool bTemporaryVictory);

	
	UPROPERTY(BlueprintAssignable)
	FChangedHowFigureNeedToWin ChangeHowFigureNeedToWin;
	UPROPERTY(BlueprintAssignable)
	FChangedHowFigureNow ChangeHowFigureNow;
	UPROPERTY(BlueprintAssignable)
	FChangedTypeFigureToWin ChangeTypeFigureToWin;
	UPROPERTY(BlueprintAssignable)
	FRequestedInfoAboutReloadAbility RequestTimeReload;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetRemainingTime();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Message(float Time, FName Name);


};
