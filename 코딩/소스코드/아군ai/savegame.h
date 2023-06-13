#pragma once

#include "ArenaBattle.h"
#include "GameFramework/SaveGame.h"
#include "ABSaveGame.generated.h"

UCLASS()
class ARENABATTLE_API UABSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UABSaveGame();

public:
	UPROPERTY()
		FString PlayerName;

};