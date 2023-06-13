#include "ABSaveGame.h"

AABPlayerState::AABPlayerState()
{
	GameHighScore = 0;
	SaveSlotName = TEXT("Player1");
}

// 데이터 불러오기.
void AABPlayerState::InitPlayerData()
{
	UABSaveGame* ABSaveGame = Cast<UABSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (nullptr == ABSaveGame)
	{
		ABSaveGame = GetMutableDefault<UABSaveGame>(); // Gets the mutable default object of a class.
	}

	SetPlayerName(ABSaveGame->PlayerName);

	SavePlayerData();
}

// 데이터 저장하기.
void AABPlayerState::SavePlayerData()
{
	// SpawnActor도 결국엔 NewObject를 사용한다.
	UABSaveGame* NewPlayerData = NewObject<UABSaveGame>(); // 가비지 컬렉터 덕분에 Delete 안써도 됨.
	NewPlayerData->PlayerName = GetPlayerName();


	if (false == UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		UE_LOG(LogClass, Warning, TEXT("SaveGame Error!"));
	}
}