// Fill out your copyright notice in the Description page of Project Settings.


#include "ourAIController.h"
#include "Blade_Character.h"

void getAccumulateData()
{
	//���������� �޾ƿ���
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
		//�ش� �������� ������ ����������
		itemUpDamage += 10;
	}
	if (getUpSdItem)
	{
		//��������
		itemUpDefense += 10;
	}
}

void AourAIController::upDefense()
{
}
