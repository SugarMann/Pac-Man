/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Ending Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include <stdint.h>
#include <string>

#include "raylib.h"
#include "Screens/ScreenEnding.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

static std::string gameOver, options, info, scoreString, timeString;
static uint16_t infoPosX, infoPosY;

//----------------------------------------------------------------------------------
// Ending Screen Functions Definition
//----------------------------------------------------------------------------------

// Ending Screen Initialization logic
void InitEndingScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;

    gameOver = "         you LOOSE!! :(";
    options = "\n\n  Press Enter for Playing.\n    Press 'O' for Options.";
    scoreString = "\n\n           Score: " + std::to_string(score);
    timeString = "\n        Time: " + std::to_string(gameplayTime.count());
    info = gameOver + scoreString + timeString + options;
    infoPosX = GetScreenWidth() / 3;
    infoPosY = GetScreenHeight() / 4;
}

// Ending Screen Update logic
void UpdateEndingScreen(void)
{
    // Press enter or tap to return to TITLE screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1; // TITLE
        PlaySound(fxCoin);
    }
    else if (IsKeyPressed(KEY_O))
    {
        finishScreen = 2; // OPTIONS
        PlaySound(fxCoin);
    }
}

// Ending Screen Draw logic
void DrawEndingScreen(void)
{
    // Draw background
    ClearBackground(BLACK);
    // Add text about options information
    DrawText(info.c_str(), infoPosX, infoPosY, 24U, WHITE);
}

// Ending Screen Unload logic
void UnloadEndingScreen(void)
{

}

// Ending Screen should finish?
int FinishEndingScreen(void)
{
    return finishScreen;
}