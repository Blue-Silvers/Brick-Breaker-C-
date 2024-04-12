#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Bonus.h"
#include <iostream>

using namespace std;

void Start();
void Update();
void Draw();
void NewStage();
void End();

Ball ball;
Paddle paddle;

Brick brick;

int score = 0;

int column = 10;
int row = 1;
int nbBrick = 0;
Brick theWall[14][10];
Bonus bonus[14][10];

Font ft;
Vector2 textPos{ GetScreenWidth() / 5, GetScreenHeight() / 2.5 };
Vector2 scorePos{ GetScreenWidth() / 5, 20 };

bool win = false;
bool gameOver = false;
int main() {

    Start();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    End();
    return 0;
}


void Start()
{
    InitWindow(1200, 800, "Brick Breaker !");
    SetTargetFPS(60);
    ft = LoadFont("resources/fonts/jupiter_crash.png");
    textPos.x = GetScreenWidth() / 5;
    textPos.y = GetScreenHeight() / 2.5;
    scorePos.x = GetScreenWidth() / 2.3;
    scorePos.y = 5;
    score = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            theWall[i][j].Start(i,j);
        }
    }
    nbBrick = row * column *brick.mBrickLife ;
}

void Update()
{
    ball.Update(ft, textPos, GetScreenWidth(), GetScreenHeight(), paddle);
    paddle.Update(GetScreenWidth());

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            if (theWall[i][j].Update(ball))
            {
                ball.CollideBrick();
                nbBrick -= 1;
                score += 100;
                //spawn bonus
                int random = rand() % 10;
                if(random == 5)
                {
                    bonus[i][j].Start(theWall[i][j].mBrickX, theWall[i][j].mBrickY, theWall[i][j].mBrickWidth, theWall[i][j].mBrickHeight);
                }
            }
            if (bonus[i][j].Update(paddle))
            {
                paddle.BonusSize();
                score += 200;
            }
            if (bonus[i][j].Time(paddle) == true)
            {
                paddle.BackSize();
            }
        }
    }

    if (nbBrick <= 0) 
    {
        NewStage();
    }
}

void Draw()
{
    BeginDrawing();

    ClearBackground(DARKBLUE);
    DrawRectangle(0, 50, GetScreenWidth(), 15, GRAY);

    
    paddle.Draw();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            theWall[i][j].Draw();
            bonus[i][j].Draw();
        }
    }

    ball.Draw();

    DrawTextEx(ft, TextFormat("%08i", score), scorePos, 50, 5, WHITE);

    if (win == true) 
    {
        float timer = GetFrameTime();
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
        Vector2 endScorePos{ GetScreenWidth() / 6, GetScreenHeight() / 2 };
        Vector2 endCongartsPos{ GetScreenWidth() / 4, GetScreenHeight() / 4 };
        Vector2 endTimePos{ GetScreenWidth() / 5, GetScreenHeight() / 1.5 };
        DrawTextEx(ft, "Congratulation", endCongartsPos, 150, 5, WHITE);
        DrawTextEx(ft, TextFormat("Your final score : %08i", score), endScorePos, 100, 5, WHITE);
        DrawTextEx(ft, TextFormat("Your time : %02.02f min", time), endTimePos, 100, 5, WHITE);
    }
    EndDrawing();
}

void NewStage() 
{
    score += 1000;
    ball.NewStage();
    row += 3;
    if (row > 2) 
    {
        win = true;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            theWall[i][j].Start(i, j);
        }
    }
    nbBrick = row * column * brick.mBrickLife;

    ball.Draw();
}

void End()
{
    CloseWindow();
}