// Fill out your copyright notice in the Description page of Project Settings.


#include "ourAIController.h"
#include "Blade_Character.h"
#include "PlayerState.h"

void getAccumulateData()
{
	//���������� �޾ƿ���
	Blade_Character* Blade_Character = Cast<Blade_Character>(OtherActor);
	getAccumulateData = Blade_Character->getAccumulateData();
}

void AourAIController::unlockSkill(int unlockSkillNumber, int getItem)
{
	if (targettingCount >= 3) // ĳ���Ͱ� ������ 3���̻� ��ų�� ����� �ش� �ִϸ��̼� ���
	{
		Blade_Character* Blade_Character = Cast<Blade_Character>(OtherActor);
		Blade_Character->unlock(unlockSkillNumber); //�ش� ��ų�ѹ����ִ� �ִϸ��̼��� ���
	}

}

void AourAIController::avoidSkill(int getAttackedSkillNumber)
{
	if (checkAttacked) //���ݹ޾Ҵ�
	{
		if (AccumulateDamage > 50)
		{
			Blade_Character* Blade_Character = Cast<Blade_Character>(OtherActor);
			Blade_Character->Avoid(); //���ϴ� �ִϸ��̼����
		}
	}
}

void AourAIController::upDamage()
{
	if (getUpAditem)
	{
		//�ش� �������� ������ ����������
		itemUpDamage += 10;
	}

	
}

void AourAIController::upDefense()
{
	if (getUpSdItem)
	{
		//��������
		itemUpDefense += 10;
	}
}
