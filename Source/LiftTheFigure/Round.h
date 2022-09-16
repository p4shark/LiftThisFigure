// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Round.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, MinimalAPI)
class URound : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class LIFTTHEFIGURE_API IRound
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetRemainingTime();
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
