// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "golemAIController.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API AgolemAIController : public AAIController
{
	GENERATED_BODY()
public:
	AgolemAIController();

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

private:
	void RandomMove();

private:
	FTimerHandle TimerHandle;

};
