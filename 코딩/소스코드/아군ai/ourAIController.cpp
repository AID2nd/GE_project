// Fill out your copyright notice in the Description page of Project Settings.


#include "ourAIController.h"
#include "Blade_Character.h"

void getAccumulateData()
{
	//누적데미지 받아오기
	Blade_Character* Blade_Character = Cast<Blade_Character>(OtherActor);
	getAccumulateData = Blade_Character->getAccumulateData();
}

void AourAIController::unlockSkill(int unlockSkillNumber, int getItem)
{
	
}

void AourAIController::avoidSkill(int getAttackedSkillNumber)
{
}

void AourAIController::upDamage()
{
	if (getUpAditem)
	{
		//해당 아이템이 있으면 데미지증가
		itemUpDamage += 10;
	}
	if (getUpSdItem)
	{
		//방어력증가
		itemUpDefense += 10;
	}
}

void AourAIController::upDefense()
{
}
