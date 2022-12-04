/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
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
#include <chrono>

#include "raylib.h"
#include "Screens/ScreenTitle.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter;
static int finishScreen;
std::string info, author;
static uint16_t infoPosX, infoPosY, authorPosX, authorPosY;
Vector2 titlePosition;

// Time variables
static std::chrono::system_clock::time_point start, end;
static std::chrono::duration<double> elapsedTime;

// Textures
Texture2D titleTexture;

//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    // Save title texture and position
    titleTexture = LoadTexture("resources/Menu/PacMan_MainLogo.png");
    titlePosition = { static_cast<float> (GetScreenWidth() / 1.85f - titleTexture.width / 1.85f), static_cast<float> (GetScreenHeight() / 3 - titleTexture.height / 2.f) };
    // Save information about menu
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 2.85f);
    infoPosY = static_cast<uint16_t>(GetScreenHeight() / 1.35f);
    info = "  Press Enter for Playing\n  Press 'I' for Instructions";
    // Save author's info.
    authorPosX = static_cast<uint16_t>(GetScreenWidth() / 2.15f);
    authorPosY = static_cast<uint16_t>(GetScreenHeight() / 1.75f);
    author = "     by\n Carlos C.";

    // Start counter for title screen
    start = std::chrono::system_clock::now();
    PlayMusicStream(introMusic);
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    // Update the elapsed time since the gameplay screen was initialized
    end = std::chrono::system_clock::now();
    elapsedTime = end - start;

    // Press enter or tap to change to GAMEPLAY screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 2;   // GAMEPLAY
        PlaySound(fxCoin);
    }
    else if (IsKeyPressed(KEY_I))
    {
        finishScreen = 1; // OPTIONS
        PlaySound(fxCoin);
    }
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
    // Draw background
    ClearBackground(BLACK);

    // Load and draw title image
    
    DrawTextureEx(titleTexture, titlePosition , 0.0f, 1.f, WHITE);

    // Add text about menu information 
    DrawText(info.c_str(), infoPosX, infoPosY, 24U, WHITE);

    // Add author's name texture  
    DrawText(author.c_str(), authorPosX, authorPosY, 20U, WHITE);
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
    UnloadTexture(titleTexture);
    StopMusicStream(introMusic);
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}