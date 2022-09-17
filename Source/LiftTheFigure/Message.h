// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Message.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, MinimalAPI)
class UMessage : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LIFTTHEFIGURE_API IMessage
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Message(float Time, FName Name);
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
