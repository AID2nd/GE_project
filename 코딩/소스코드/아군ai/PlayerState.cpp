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
	SetSaveAttackDamage(ASaveGame->SaveAttackDamage);
	SetSaveSkillDamage(ASaveGame->SaveSkillDamage);

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
	//플레이어 데이터를 토대로 확률 피하기
	avoidSkillPercent = 100 - (((SaveSkillDamage / 30) / BossSkillCount) * 100); // 최대 공격 성공확률(100) - 누적 공격 성공확률 
	avoidAttackPercent = 100 - (((SaveAttackDamage / 10) / BossAttackCount) * 100);
	uniform_int_distribution<int> dist1(1, 100);
	randAvoidSkill = dist1(rng); //1 ~ 100사이수

	uniform_int_distribution<int> dist2(1, 100);
	randAvoidAttack = dist2(rng);

	if (avoidSkillPercent > randAvoidSkill) //1~100까지 수 중에 랜덤으로 나온 수(확률)보다 피할 확률이 크면
	{
		UE_LOG(LogClass, Warning, TEXT("스킬공격회피"));
		// 뒤로 스킬사용해서 피해라
	}
	if (avoidAttackPercent > randAvoidAttack)//1~100까지 수 중에 랜덤으로 나온 수(확률)보다 피할 확률이 크면
	{
		UE_LOG(LogClass, Warning, TEXT("일반공격회피"));
		// 뒤로 스킬사용해서 피해라
	}
	


}