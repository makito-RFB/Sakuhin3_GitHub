#include<iostream>
#include <DxLib.h>
#include"score.hpp"

void SetScore::setS(float time_, int mintime_, int COINCnt_) {

	TIMEScore = floor(100 * (time_ * 10 + mintime_ * 600 + 20)) / 100;	//秒×10pt
	COINScore = COINCnt_ / 5 * 500;	//5枚で＋500pt
	Score = TIMEScore + COINScore;	//上2つを足した合計がスコア

	return;
}

float SetScore::reS() {
	return Score;
}

bool DrawScore::drawS(float time, int mintime, int COINCnt, int SecondCnt) {
	SetScore::setS(time, mintime, COINCnt);

	SetFontSize(32);
	if (SecondCnt > GAME_FPS) {
		if (mintime > 0)
			DrawFormatString(10, 10, GetColor(255, 255, 255), "クリアタイム : %d分%.2f", mintime, time);
		else
			DrawFormatString(10, 10, GetColor(255, 255, 255), "クリアタイム : %.2f", time);
	}
	if (SecondCnt > (GAME_FPS * 2))
	{
		DrawFormatString(10, 80, GetColor(255, 255, 255), "総獲得コイン : %d", COINCnt);
	}
	if (SecondCnt > (GAME_FPS * 3))
	{
		SetFontSize(64);
		DrawFormatString((GAME_WIDTH - GetDrawFormatStringWidth("スコア: %.2f", Score, -1)) / 2, GAME_HEIGHT / 4 * 3, GetColor(255, 255, 255), "スコア: %.2f", Score);
		BTNIsDraw = true;
	}

	return BTNIsDraw;
}


void DrawScore::drawStop(float time, int mintime, int COINCnt)
{
	SetScore::setS(time, mintime, COINCnt);

	SetFontSize(32);
	if (mintime > 0)
		DrawFormatString(10, 10, GetColor(255, 255, 255), "現タイム : %d分%.2f", mintime, time);
	else
		DrawFormatString(10, 10, GetColor(255, 255, 255), "現タイム : %.2f", time);
	DrawFormatString(10, 80, GetColor(255, 255, 255), "獲得コイン数 : %d", COINCnt);
	return;
}
