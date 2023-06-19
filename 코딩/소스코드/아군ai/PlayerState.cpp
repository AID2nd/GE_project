#include "ABSaveGame.h"

AABPlayerState::AABPlayerState()
{

	BossSkillCount = 0;
	BossAttackCount = 0;
	playerAvoidData = 0;
	playerSkillDamage = 0;
	SaveSlotName = TEXT("SlotName");
}

// 누적데이터 불러오기.
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

// 누적데이터 저장하기.
void AABPlayerState::SavePlayerData()
{
	// SpawnActor도 결국엔 NewObject를 사용한다.
	USaveGame* NewPlayerData = NewObject<UABSaveGame>(); // 가비지 컬렉터 덕분에 Delete 안써도 됨.
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
	//플레이어 데이터를 토대로 피하기
	if (BossSkillCount > BossAttackCount)
	{
		// 뒤로 스킬사용해서 피해라
	}
	


}