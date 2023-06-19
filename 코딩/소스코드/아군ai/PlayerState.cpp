#include "ABSaveGame.h"

AABPlayerState::AABPlayerState()
{

	BossSkillCount = 0;
	BossAttackCount = 0;
	playerAvoidData = 0;
	playerSkillDamage = 0;
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
	SetplayerAvoidData(ASaveGame->playerAvoidData);
	SetplayerSkillDamage(ASaveGame->playerSkillDamage);

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

	NewPlayerData->playerAvoidData = GetplayerAvoidData();
	NewPlayerData->playerSkillDamage = GetplayerSkillDamage();

	if (false == UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		UE_LOG(LogClass, Warning, TEXT("SaveGame Error!"));
	}


}
void AABPlayerState::UpdatePlayerState()
{
	BossSkillCount->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetBossSkillCount())));
	BossAttackCount->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetBossAttackCount())));
	playerAvoidData->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetplayerAvoidData())));
	playerSkillDamage->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetplayerSkillDamage())));

}
void AABPlayerState::AvoidPercentage()
{
	//�÷��̾� �����͸� ���� ���ϱ�
	if (BossSkillCount > BossAttackCount)
	{
		// �ڷ� ��ų����ؼ� ���ض�
	}
	


}