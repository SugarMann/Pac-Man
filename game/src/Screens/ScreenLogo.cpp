/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Logo Screen Functions Definitions (Init, Update, Draw, Unload)
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

#include "raylib.h"
#include "Screens/ScreenLogo.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static uint16_t framesCounter;
static uint8_t finishScreen;

static uint16_t logoPositionX, logoPositionY, topSideRecWidth, leftSideRecHeight, bottomSideRecWidth, rightSideRecHeight;
static uint8_t lettersCount;

static uint8_t state;       // Logo animation states
static float alpha;         // Useful for fading

//----------------------------------------------------------------------------------
// Logo Screen Functions Definition
//----------------------------------------------------------------------------------

// Logo Screen Initialization logic
void InitLogoScreen(void)
{
    finishScreen = 0U;
    framesCounter = 0U;
    lettersCount = 0U;

    logoPositionX = static_cast<uint16_t>(GetScreenWidth()/2 - 128);
    logoPositionY = static_cast<uint16_t>(GetScreenHeight()/2 - 128);

    topSideRecWidth = 16U;
    leftSideRecHeight = 16U;
    bottomSideRecWidth = 16U;
    rightSideRecHeight = 16U;

    state = 0U;
    alpha = 1.0f;
}

// Logo Screen Update logic
void UpdateLogoScreen(void)
{
    if (state == 0)                 // State 0: Top-left square corner blink logic
    {
        framesCounter++;

        if (framesCounter == 80)
        {
            state = 1U;
            framesCounter = 0U;      // Reset counter... will be used later...
        }
    }
    else if (state == 1)            // State 1: Bars animation logic: top and left
    {
        topSideRecWidth += 8U;
        leftSideRecHeight += 8U;

        if (topSideRecWidth == 256) state = 2;
    }
    else if (state == 2)            // State 2: Bars animation logic: bottom and right
    {
        bottomSideRecWidth += 8U;
        rightSideRecHeight += 8U;

        if (bottomSideRecWidth == 256) state = 3;
    }
    else if (state == 3)            // State 3: "raylib" text-write animation logic
    {
        framesCounter++;

        if (lettersCount < 10)
        {
            if (framesCounter/12)   // Every 12 frames, one more letter!
            {
                lettersCount++;
                framesCounter = 0U;
            }
        }
        else    // When all letters have appeared, just fade out everything
        {
            if (framesCounter > 200)
            {
                alpha -= 0.02f;

                if (alpha <= 0.0f)
                {
                    alpha = 0.0f;
                    finishScreen = 1U;   // Jump to next screen
                }
            }
        }
    }
}

// Logo Screen Draw logic
void DrawLogoScreen(void)
{
    if (state == 0)         // Draw blinking top-left square corner
    {
        if ((framesCounter/10)%2) DrawRectangle(logoPositionX, logoPositionY, 16U, 16U, BLACK);
    }
    else if (state == 1)    // Draw bars animation: top and left
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16U, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16U, leftSideRecHeight, BLACK);
    }
    else if (state == 2)    // Draw bars animation: bottom and right
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16U, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16U, leftSideRecHeight, BLACK);

        DrawRectangle(logoPositionX + 240, logoPositionY, 16U, rightSideRecHeight, BLACK);
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16U, BLACK);
    }
    else if (state == 3)    // Draw "raylib" text-write animation + "powered by"
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16U, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 16, 16U, leftSideRecHeight - 32, Fade(BLACK, alpha));

        DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16U, rightSideRecHeight - 32, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16U, Fade(BLACK, alpha));

        DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224U, 224U, Fade(RAYWHITE, alpha));

        DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 50U, Fade(BLACK, alpha));

        if (framesCounter > 20) DrawText("powered by", logoPositionX, logoPositionY - 27, 20U, Fade(DARKGRAY, alpha));
    }
}

// Logo Screen Unload logic
void UnloadLogoScreen(void)
{
    // Unload LOGO screen variables here!
}

// Logo Screen should finish?
int FinishLogoScreen(void)
{
    return finishScreen;
}
