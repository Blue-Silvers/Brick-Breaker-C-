#include "Ball.h"

Ball::Ball() 
{

}

void Ball::Update(Font ft, Vector2 startTextPos, int screenWidth, int screenHeight, Paddle paddle)
{
    if (IsKeyDown(KEY_SPACE))
    {
        mBallLunched = true;
    }

    if (mBallLunched)
    {
        mBallX += mBallSpeedX;
        mBallY += mBallSpeedY;

        if (mBallX + mBallRadius > screenWidth)
        {
            mBallSpeedX *= -1;
            mBallX = screenWidth - mBallRadius;
        }
        else if (mBallX - mBallRadius < 0)
        {
            mBallSpeedX *= -1;
            mBallX = mBallRadius;
        }
        else if (mBallY + mBallRadius > screenHeight)
        {
            mBallLunched = false; 
            mBallLife -= 1;
        }
        else if (mBallY - mBallRadius <= 65)
        {
            mBallSpeedY *= -1;
            mBallY = mBallRadius + 65;
        }
        
        if (mBallY + mBallRadius == paddle.mPaddleY && mBallX + mBallRadius > paddle.mPaddleX && mBallX - mBallRadius < paddle.mPaddleX + paddle.mPaddleWidth)
        {
            if (mBallX > paddle.mPaddleX + paddle.mPaddleWidth / 2)
            {
                float distanceRight = paddle.mPaddleX + paddle.mPaddleWidth / 2 - mBallX;
                mBallSpeedX = -mBallSpeedMax * (distanceRight / (paddle.mPaddleWidth / 2));
            }
            else if(mBallX < paddle.mPaddleX + paddle.mPaddleWidth / 2)
            {
                float distanceLeft = paddle.mPaddleX + paddle.mPaddleWidth / 2 - mBallX;
                mBallSpeedX = -mBallSpeedMax * (distanceLeft / (paddle.mPaddleWidth / 2));
            }
            else 
            {
                mBallX = 0;
            }
            mBallSpeedY *= -1;
        }
    }
    else
    {
        DrawTextEx(ft, "Press space for start", startTextPos, 100, 5, WHITE);
        mBallSpeedX = 5;
        mBallSpeedY = -5;
        mBallX = paddle.mPaddleX + paddle.mPaddleWidth / 2;
        mBallY = paddle.mPaddleY - 10 - mBallRadius;
    }


}

void Ball::Draw()
{
    DrawCircle(mBallX, mBallY, mBallRadius, mBallColor);

    if (mBallLife >= 6)
    {
        DrawCircle(mBallRadius * 11 + mBallRadius, GetScreenHeight() - 2 * mBallRadius, mBallRadius / 1.5, mBallColor);
    }
    if (mBallLife >= 5)
    {
        DrawCircle(mBallRadius * 9 + mBallRadius, GetScreenHeight() - 2 * mBallRadius, mBallRadius / 1.5, mBallColor);
    }
    if (mBallLife >= 4)
    {
        DrawCircle(mBallRadius * 7 + mBallRadius, GetScreenHeight() - 2 * mBallRadius, mBallRadius / 1.5, mBallColor);
    }
    if (mBallLife >= 3) 
    {
        DrawCircle(mBallRadius *5 + mBallRadius, GetScreenHeight() - 2*mBallRadius, mBallRadius / 1.5, mBallColor);
    }
    if (mBallLife >= 2)
    {
        DrawCircle(mBallRadius * 3 + mBallRadius, GetScreenHeight() - 2*mBallRadius, mBallRadius / 1.5, mBallColor);
    }
    if (mBallLife >= 1)
    {
        DrawCircle(mBallRadius + mBallRadius, GetScreenHeight() - 2*mBallRadius, mBallRadius / 1.5, mBallColor);
    }
    else 
    {
        LoosingGame();
    }
}

void Ball::CollideBrick() 
{
    mBallSpeedX *= -1;
    mBallSpeedY *= -1;
}

void Ball::LoosingGame() 
{
    //restart
}

void Ball::NewStage() 
{
    mBallLunched = false;
    mBallLife += 1;
}