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
	void getAccumulateData(); //���� �����͸� ������ �Լ�
	void unlockSkill(int unlockSkillNumber, int getItem); // Ư�� �������� ���� �� �ش� ��ų�� �ر��ϴ� �Լ�
	void avoidSkill(int getAttackedSkillNumber); // �������� Ư�� ��ų���ݹ����� ���ϴ� �Լ�

	void upDamage();
	void upDefense();
private:
	int targetingCount;
	int32 itemUpDamage; // ������ �����ۿ����� ��·� 
	int32 itemUpDefense; //���»��
	int32 unlockSkillNumber; // ����� �رݿ� ��ų
	int32 itemNumber; // ���� ������ �����

	bool getUpAditem; //���ݷ¾�����
	bool getUpSdItem; //���¾�����

	bool checkAttacked;

	int AccumulateDamage;
	
};
