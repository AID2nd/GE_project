#include "ABSaveGame.h"

AABPlayerState::AABPlayerState()
{

	BossSkillCount = 0;
	BossAttackCount = 0;
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

	if (false == UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		UE_LOG(LogClass, Warning, TEXT("SaveGame Error!"));
	}
}