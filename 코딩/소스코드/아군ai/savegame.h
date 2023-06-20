#pragma once

#include "ArenaBattle.h"
#include "GameFramework/SaveGame.h"
#include "SaveGame.generated.h"

UCLASS()
class ARENABATTLE_API UABSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	USaveGame();

public:
	UPROPERTY()
		FString PlayerName;

	UPROPERTY()
		float BossSkillCount;

	UPROPERTY()
		float BossAttackCount;

	UPROPERTY()
		float SaveAttackDamage;

	UPROPERTY()
		float SaveSkillDamage;

};