#include "Paddle.h"

Paddle::Paddle()
{

}

void Paddle::Update(int screenWidth)
{
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        if (mPaddleX > 0)
        {
            mPaddleX -= mPaddleSpeed;
        }
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if (mPaddleX + mPaddleWidth < screenWidth)
        {
            mPaddleX += mPaddleSpeed;
        }
    }

}

void Paddle::Draw()
{
    DrawRectangle(mPaddleX, mPaddleY, mPaddleWidth, mPaddleHeight, mPaddleColor);
}

void Paddle::BonusSize() 
{
    mPaddleWidth += 50;
}

void Paddle::BackSize()
{
    mPaddleWidth -= 50;
}