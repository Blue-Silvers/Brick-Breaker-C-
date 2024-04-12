#pragma once
#include "raylib.h"
class ShowScreen
{
private:
	bool mStartScren = true;
	float mTime = 0;

public:
	bool mWin = false;
	bool mGameOver = false;
	ShowScreen();
	bool Update(int life);
	void Draw(Font ft, int score);

};

