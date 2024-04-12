#include "Bonus.h"


Bonus::Bonus() 
{

}

void Bonus::Start(int posX, int posY, int brickWidth, int brickHeight)
{
	mBallCollide = false;
	mBallX = posX + brickWidth / 2;
	mBallY = posY + brickHeight;
	mBonusCountDown = false;
}

bool Bonus::Update(Paddle paddle)
{
	mBallY += mBallSpeedY;
	if (mBallY + mBallRadius == paddle.mPaddleY && mBallX + mBallRadius > paddle.mPaddleX && mBallX - mBallRadius < paddle.mPaddleX + paddle.mPaddleWidth)
	{
		mBallCollide = true;
		mBonusCountDown = true;
		return true;
		
	}
	else 
	{
		return false;
	}

	if (mBallY + mBallRadius > GetScreenHeight())
	{
		mBallCollide = true;
	}

}

void Bonus::Draw()
{
	if (mBallCollide == false) 
	{
		DrawCircle(mBallX, mBallY, mBallRadius, mBallColor);
	}
}

bool Bonus::Time(Paddle paddle) 
{
	if (mBonusCountDown == true)
	{
		mBonusTime -= 1;
		if (mBonusTime <= 0) 
		{
			mBonusCountDown = false;
			mBonusTime = 1000;
			return true;
		}
	}
}