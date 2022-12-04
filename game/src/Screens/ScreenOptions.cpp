/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Options Screen Functions Definitions (Init, Update, Draw, Unload)
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
#include "Screens\ScreenOptions.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

static std::string gameInfo;
static std::string controls;
static std::string escapeInfo;
static uint16_t infoPosX, difPosX;
static uint16_t infoPosY, difPosY;
static std::string stringInfo;
static std::string stringDifficulty;

//----------------------------------------------------------------------------------
// Options Screen Functions Definition
//----------------------------------------------------------------------------------

// Options Screen Initialization logic
void InitOptionsScreen(void)
{
    // TODO: Initialize OPTIONS screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    gameInfo = "\n      To move PACMAN use the direction keys or W,A,S,D.\n    PACMAN has 3 lifes, every dot eaten increases 10 points\n          the big dots adds 50 points to the score";
    controls = "\n\n               To win PACMAN has to eat all the dots\n         You loose if the ghost SHADOW kills you 3 times.\n";
    escapeInfo = "\n\n                     Press 'O' to return to Title\n        Press 'Left Arrow' and 'Right Arrow' to modify\n                             the difficulty";
    stringInfo = gameInfo + controls + escapeInfo;
    infoPosX = GetScreenWidth() / 6;
    infoPosY = GetScreenHeight() / 8;
    difPosX = static_cast<uint16_t>(GetScreenWidth() / 2.75f);
    difPosY = 15U;
}

// Options Screen Update logic
void UpdateOptionsScreen(void)
{

    if (IsKeyPressed(KEY_LEFT) && difficulty > 4U)
        difficulty -= 3U;
    if (IsKeyPressed(KEY_RIGHT) && difficulty < 10U)
        difficulty += 3U;

    if (IsKeyPressed(KEY_O) || IsKeyPressed(KEY_ENTER))
    {
        finishScreen = 1;   // TITLE
        PlaySound(fxCoin);
    }
}

// Options Screen Draw logic
void DrawOptionsScreen(void)
{
    // Draw background
    ClearBackground(BLACK);

    // Add text about options information
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, WHITE);

    // Add text to choose difficulty
    switch (difficulty)
    {
    case 4: 
        stringDifficulty = "\nDIFFICULTY: EASY";
        DrawText(stringDifficulty.c_str(), difPosX, difPosY, 24U, WHITE); 
        break;
    case 7: 
        stringDifficulty = "\nDIFFICULTY: NORMAL";
        DrawText(stringDifficulty.c_str(), difPosX, difPosY, 24U, WHITE); 
        break;
    case 10: 
        stringDifficulty = "\nDIFFICULTY: EXPERT";
        DrawText(stringDifficulty.c_str(), difPosX, difPosY, 24U, WHITE); 
        break;
    }

}

// Options Screen Unload logic
void UnloadOptionsScreen(void)
{

}

// Options Screen should finish?
int FinishOptionsScreen(void)
{
    return finishScreen;
}