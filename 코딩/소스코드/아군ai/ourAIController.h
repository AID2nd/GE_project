// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ourAIController.generated.h"

/**
 * 
 */
UCLASS()
class TEST2_API AourAIController : public AAIController
{
	GENERATED_BODY()
public:
	void getAccumulateData(); //누적 데이터를 얻어오는 함수
	void unlockSkill(int unlockSkillNumber, int getItem); // 특정 아이템이 있을 시 해당 스킬을 해금하는 함수
	void avoidSkill(int getAttackedSkillNumber); // 보스에게 특정 스킬공격받을시 피하는 함수

	void upDamage();
	void upDefense();
private:
	int targetingCount;
	int32 itemUpDamage; // 데미지 아이템에따른 상승량 
	int32 itemUpDefense; //방어력상승
	int32 unlockSkillNumber; // 저장된 해금용 스킬
	int32 itemNumber; // 얻어온 아이템 저장소

	bool getUpAditem; //공격력아이템
	bool getUpSdItem; //방어력아이템

	bool checkAttacked;

	int AccumulateDamage;
	
};
