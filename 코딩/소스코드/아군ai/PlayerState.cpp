#include "ABSaveGame.h"
#include <random>

random_device rng; 

AABPlayerState::AABPlayerState()
{

	BossSkillCount = 0;
	BossAttackCount = 0;
	SaveSkillDamage = 0;
	SaveAttackDamage = 0;
	SaveSlotName = TEXT("SlotName");
}

// ���������� �ҷ�����.
void AABPlayerState::InitPlayerData()
{
	UABSaveGame* ASaveGame = Cast<UASaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (nullptr == ABSaveGame)
	{
		ASaveGame = GetMutableDefault<UASaveGame>(); // Gets the mutable default object of a class.
	}

	SetPlayerName(ASaveGame->PlayerName);
	SetBossSkillCount(ASaveGame->BossSkillCount);
	SetBossAttackCount(ASaveGame->BossAttackCount);
	SetSaveAttackDamage(ASaveGame->SaveAttackDamage);
	SetSaveSkillDamage(ASaveGame->SaveSkillDamage);

	SavePlayerData();
}

// ���������� �����ϱ�.
void AABPlayerState::SavePlayerData()
{
	// SpawnActor�� �ᱹ�� NewObject�� ����Ѵ�.
	USaveGame* NewPlayerData = NewObject<UABSaveGame>(); // ������ �÷��� ���п� Delete �Ƚᵵ ��.
	NewPlayerData->PlayerName = GetPlayerName();
	NewPlayerData->BossSkillCount = GetBossSkillCount();
	NewPlayerData->BossAttackCount = GetBossAttackCount();

	NewPlayerData->SaveSkillDamage = GetSaveSkillDamage();
	NewPlayerData->SaveAttackDamage = GetSaveAttackDamage();

	if (false == UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		UE_LOG(LogClass, Warning, TEXT("SaveGame Error!"));
	}


}
void AABPlayerState::UpdatePlayerState()
{
	BossSkillCount->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetBossSkillCount())));
	BossAttackCount->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetBossAttackCount())));
	SaveAttackDamage->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetSaveAttackDamage))));
	SaveSkillDamage->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetSaveSkillDamage())));

}
void AABPlayerState::AvoidPercentage()
{
	//�÷��̾� �����͸� ���� Ȯ�� ���ϱ�
	avoidSkillPercent = 100 - (((SaveSkillDamage / 30) / BossSkillCount) * 100); // �ִ� ���� ����Ȯ��(100) - ���� ���� ����Ȯ�� 
	avoidAttackPercent = 100 - (((SaveAttackDamage / 10) / BossAttackCount) * 100);
	uniform_int_distribution<int> dist1(1, 100);
	randAvoidSkill = dist1(rng); //1 ~ 100���̼�

	uniform_int_distribution<int> dist2(1, 100);
	randAvoidAttack = dist2(rng);

	if (avoidSkillPercent > randAvoidSkill) //1~100���� �� �߿� �������� ���� ��(Ȯ��)���� ���� Ȯ���� ũ��
	{
		UE_LOG(LogClass, Warning, TEXT("��ų����ȸ��"));
		// �ڷ� ��ų����ؼ� ���ض�
	}
	if (avoidAttackPercent > randAvoidAttack)//1~100���� �� �߿� �������� ���� ��(Ȯ��)���� ���� Ȯ���� ũ��
	{
		UE_LOG(LogClass, Warning, TEXT("�Ϲݰ���ȸ��"));
		// �ڷ� ��ų����ؼ� ���ض�
	}
	


}