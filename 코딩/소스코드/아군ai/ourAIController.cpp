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
	if (checkAttacked) //공격받았다
	{
		Blade_Character* Blade_Character = Cast<Blade_Character>(OtherActor);
		Blade_Character->Avoid(); //피하는 애니메이션출력
	}
}

void AourAIController::upDamage()
{
	if (getUpAditem)
	{
		//해당 아이템이 있으면 데미지증가
		itemUpDamage += 10;
	}
	
}

void AourAIController::upDefense()
{
	if (getUpSdItem)
	{
		//방어력증가
		itemUpDefense += 10;
	}
}
