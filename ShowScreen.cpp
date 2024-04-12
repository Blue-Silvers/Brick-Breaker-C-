#include "ShowScreen.h"
ShowScreen::ShowScreen()
{

}

bool ShowScreen::Update(int life)
{
    if (life == 0) 
    {
        mGameOver = true;
    }
    else 
    {
        mTime += 1;
    }
    if (mGameOver == true || mWin == true) 
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            mTime = 0; // restart
            mGameOver = false;
            mGameOver = false;
            return true;
        }
    }

}

void ShowScreen::Draw(Font ft, int score)
{
    if (mGameOver == true)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
        Vector2 endScorePos{ GetScreenWidth() / 6, GetScreenHeight() / 2 };
        Vector2 endGameOverPos{ GetScreenWidth() / 3.5, GetScreenHeight() / 4 };
        Vector2 endTimePos{ GetScreenWidth() / 5, GetScreenHeight() / 1.5 };
        DrawTextEx(ft, "GAME OVER", endGameOverPos, 150, 5, WHITE);
        DrawTextEx(ft, TextFormat("Your score : %08i", score), endScorePos, 100, 5, WHITE);
        DrawTextEx(ft, TextFormat("Your time : %02.02f min", (mTime/60)/60), endTimePos, 100, 5, WHITE);

        Vector2 endEnterPos{ GetScreenWidth() / 3.2, GetScreenHeight() / 1.1 };
        DrawTextEx(ft, "Press ENTER for restart", endEnterPos, 50, 5, WHITE);
    }

    if (mWin == true)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
        Vector2 endScorePos{ GetScreenWidth() / 6, GetScreenHeight() / 2 };
        Vector2 endCongartsPos{ GetScreenWidth() / 4, GetScreenHeight() / 4 };
        Vector2 endTimePos{ GetScreenWidth() / 5, GetScreenHeight() / 1.5 };
        DrawTextEx(ft, "Congratulation", endCongartsPos, 150, 5, WHITE);
        DrawTextEx(ft, TextFormat("Your final score : %08i", score), endScorePos, 100, 5, WHITE);
        DrawTextEx(ft, TextFormat("Your time : %02f min", (mTime /60)/60), endTimePos, 100, 5, WHITE);

        Vector2 endEnterPos{ GetScreenWidth() / 3.2, GetScreenHeight() / 1.1 };
        DrawTextEx(ft, "Press ENTER for restart", endEnterPos, 50, 5, WHITE);
    }
}