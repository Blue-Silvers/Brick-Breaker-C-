#pragma once
#include "raylib.h"
#include "Paddle.h"
class Ball{
private:
	float mBallSpeedX = 5;
	float mBallSpeedY = -5;
	float mBallSpeedMax = 10;
	bool mBallLunched = false;
	Color mBallColor = WHITE;

public:
	int mBallLife = 3;
	int mBallRadius = 15;
	float mBallX = 500;
	float mBallY = 500;
	Ball();
	void Update(Font ft, Vector2 startTextPos, int screenWidth, int screenHeight, Paddle paddle);
	void Draw();
	void CollideBrick();
	void LoosingGame();
	void NewStage();
};

