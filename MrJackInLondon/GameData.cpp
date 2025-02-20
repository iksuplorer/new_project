#include "pch.h"
#include "GameData.h"

GameData::GameData()
{

}

GameData::~GameData()
{
}

/// <summary>
/// 홀수 라운드 시작할 때, 8개의 카드 중 랜덤으로 4개를 뽑는 함수
/// </summary>
void GameData::randomCard() {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 8; i++) {					// 홀수 라운드마다 모두 0으로 초기화
		this->selectedCard[i] = 0;
	}
	while (1) {
		int n = rand() % 8;
		this->selectedCard[n] = 1;				// 뽑힌 카드는 1로 표시
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			if (this->selectedCard[i] == 1)
				cnt++;
		}
		if (cnt == 4) {						// 뽑힌 카드 4개 될 때 종료
			break;
		}
	}
}

/// <summary>
/// 홀수 라운드에서 짝수 라운드로 바뀔 때,
/// 전 라운드에서 사용하지 않은 카드를 세팅해주는 함수
/// </summary>
void GameData::remainCard() {
	for (int i = 0; i < 8; i++) {
		if (this->selectedCard[i] == 1) {
			this->selectedCard[i] = 0;
		}
		else {
			this->selectedCard[i] = 1;
		}
	}
	// 홀수일때 1인 카드를 0으로, 0인 카드를 1로 바꿈!
}

void GameData::InfoGameRound() {
	if (this->RoundTurn[1] == 4) {
		this->RoundTurn[0]++;
		this->RoundTurn[1] = 1;
	}
	else {
		this->RoundTurn[1]++;
	}
}

/// <summary>
/// 유저의 순서를 확인하는 함수
/// </summary>
/// <returns>0이면 잭의 차례, 1이면 수사관의 차례</returns>
int GameData::check_user() {
	int oddround[4] = { 1, 0, 0, 1 };				// 홀수 : 수사관(1)부터
	int evenround[4] = { 0, 1, 1, 0 };				// 짝수 : 잭(0)부터

	if (this->RoundTurn[0] % 2 == 0) {				// 짝수 라운드인 경우
		return evenround[this->RoundTurn[1] - 1];
	}
	else {											// 홀수 라운드인 경우
		return oddround[this->RoundTurn[1] - 1];
	}
}

/// <summary>
/// 8개의 카드 중 잭 역할의 캐릭터를 고르고 세팅하는 함수
/// </summary>
void GameData::set_Jack() {
	srand((unsigned int)time(NULL));
	this->jack = (Characters)(rand() % 8);
}