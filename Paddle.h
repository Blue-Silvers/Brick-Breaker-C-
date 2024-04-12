#pragma once
#include "raylib.h"
class Paddle
{
private:
	float mPaddleSpeed = 8;
	float mPaddleHeight = 20;
	Color mPaddleColor = LIGHTGRAY;

public:
	float mPaddleX = 500;
	float mPaddleY = 725;
	float mPaddleWidth = 150;
	Paddle();
	void Update(int screenWidth);
	void Draw();
	void BonusSize();
	void BackSize();
};

