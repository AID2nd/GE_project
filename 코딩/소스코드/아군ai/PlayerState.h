#pragma once

#include "ArenaBattle.h"
#include "GameFramework/SaveGame.h"
#include "ABSaveGame.generated.h"

UCLASS()
class ARENABATTLE_API UABSaveGame : public USaveGame
{
	GENERATED_BODY()
private:
	UPROPERTY()
	float avoidPercent;

public:

	UABSaveGame();

public:
	void InitPlayerData();
	void SavePlayerData();

	void UpdatePlayerState();

	void AvoidPercentage();

};