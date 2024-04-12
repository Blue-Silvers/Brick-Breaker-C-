#include "Brick.h"
Brick::Brick()
{

}

void Brick::Start(int row, int column)
{
    mBrickLife = 2;
    mBrickX = 50 + 1.1 * mBrickWidth * (column*1);
    mBrickY = 75 + 2 * mBrickHeight * (row +1);

    SetColor(row+1);
}

bool Brick::Update(Ball ball)
{
    if (mBrickLife != 0 && ball.mBallX - ball.mBallRadius < mBrickX + mBrickWidth && ball.mBallX + ball.mBallRadius > mBrickX && ball.mBallY - ball.mBallRadius < mBrickY + mBrickHeight && ball.mBallY + ball.mBallRadius > mBrickY)
    {
        mBrickLife -= 1;
        return true;
    }
    else 
    {
        return false;
    }
}

void Brick::Draw()
{    
    if (mBrickLife == 2)
    {
        DrawRectangle(mBrickX, mBrickY, mBrickWidth, mBrickHeight, mBrickColor);
    }
    if (mBrickLife == 1) 
    {
        DrawRectangle(mBrickX, mBrickY, mBrickWidth, mBrickHeight, mBrickColor);

        DrawRectangle(mBrickX, mBrickY, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);
        DrawRectangle(mBrickX, mBrickY + mBrickHeight - mBrickHeight / 4, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);

        DrawRectangle(mBrickX + mBrickWidth - mBrickWidth / 9, mBrickY, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);
        DrawRectangle(mBrickX + mBrickWidth - mBrickWidth / 9, mBrickY + mBrickHeight - mBrickHeight / 4, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);

        DrawRectangle(mBrickX + mBrickWidth/2 - 1.6* mBrickWidth / 8, mBrickY + mBrickHeight - mBrickHeight / 4, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);
        DrawRectangle(mBrickX + mBrickWidth/2 - 1.6* mBrickWidth / 8, mBrickY, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);

        DrawRectangle(mBrickX + mBrickWidth / 2 + 0.70 * mBrickWidth / 8, mBrickY + mBrickHeight - mBrickHeight / 4, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);
        DrawRectangle(mBrickX + mBrickWidth / 2 + 0.70 * mBrickWidth / 8, mBrickY, mBrickWidth / 8, mBrickHeight / 4, DARKBLUE);
    }

}

void Brick::SetColor(int row) 
{
    if (row == 1) 
    {
        mBrickColor = RED;
    }
    else if (row == 2)
    {
        mBrickColor = DARKGREEN;
    }
    else if (row == 3)
    {
        mBrickColor = YELLOW;
    }
    else if (row == 4)
    {
        mBrickColor = DARKPURPLE;
    }
    else if (row == 5)
    {
        mBrickColor = ORANGE;
    }
    else if (row == 6)
    {
        mBrickColor = MAGENTA;
    }
    else if (row == 7)
    {
        mBrickColor = GOLD;
    }
    else if (row == 8)
    {
        mBrickColor = RED;
    }
    else if (row == 9)
    {
        mBrickColor = GREEN;
    }
    else if (row == 10)
    {
        mBrickColor = YELLOW;
    }
    else if (row == 11)
    {
        mBrickColor = PURPLE;
    }
    else if (row == 12)
    {
        mBrickColor = ORANGE;
    }
    else if (row == 13)
    {
        mBrickColor = PINK;
    }
    else
    {
        mBrickColor = LIME;
    }
}