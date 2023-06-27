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
		float avoidSkillPercent;
	UPROPERTY()
		float avoidAttackPercent;

	UPROPERTY()
		float playerSkillCount;
	UPROPERTY()
		float playerSkillDamage;

public:

	UABSaveGame();

public:
	void InitPlayerData();
	void SavePlayerData();

	void UpdatePlayerState();

	void AvoidPercentage();

	void playerSkillOpen();
};