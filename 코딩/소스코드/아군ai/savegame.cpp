#include "ABSaveGame.h"

AABPlayerState::AABPlayerState()
{
	GameHighScore = 0;
	SaveSlotName = TEXT("Player1");
}

// ������ �ҷ�����.
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

// ������ �����ϱ�.
void AABPlayerState::SavePlayerData()
{
	// SpawnActor�� �ᱹ�� NewObject�� ����Ѵ�.
	UABSaveGame* NewPlayerData = NewObject<UABSaveGame>(); // ������ �÷��� ���п� Delete �Ƚᵵ ��.
	NewPlayerData->PlayerName = GetPlayerName();


	if (false == UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		UE_LOG(LogClass, Warning, TEXT("SaveGame Error!"));
	}
}