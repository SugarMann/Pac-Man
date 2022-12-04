/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
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
#include <ctime>
#include <vector>

#include "raylib.h"
#include "Screens/ScreenGameplay.h"
#include "GlobalGameDefines.h"
#include "Game/Player.h"
#include "Game/EnemyManager.h"
#include "Game/Ghost.h"
#include "GameManager.h"
#include "TextureManager.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------

// Gameplay objects
static Player player;
static Ghost ghost;

// Ghost variables
static float ghostSpeed;
static float ghostScale;

//Gameplay variables
static uint16_t framesCounter, infoPosX, infoPosY;
static uint8_t finishScreen;
static std::string stringInfo;

// Time variables
static std::chrono::system_clock::time_point start, end;

//Textures
Tilemap tilemap = LoadTilemap("resources/TileMap/tilemap.txt", "resources/TileMap/tilemap_colliders.txt", "resources/TileMap/tilemap_objects.txt");
Image imTileset = LoadImage("resources/TileMap/tileset.png");
Texture2D texTileset;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // Initialize variables
    framesCounter = 0U;
    finishScreen = 0U;
    stringInfo = "";
    infoPosX = 0U;
    infoPosY = 0U;
    score = 0U;

    ghostSpeed = 1.5f;
    ghostScale = 0.75f;


    // Load Textures


    // Tile map
    texTileset = LoadTextureFromImage(imTileset);
    tilemap.tileSize = 32U;
    tilemap.position = { static_cast<float>(GetScreenWidth() / 2 - tilemap.tileCountX * tilemap.tileSize / 2), 
        static_cast<float>(GetScreenHeight() / 2 - tilemap.tileCountY * tilemap.tileSize / 2)};
    
    // Start counter for gameplay screen
    start = std::chrono::system_clock::now();

    // Objects initialization
    //player = Player(0U, 0U, playerSprite);

}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    //----------------------------------------------------------------------------------
    // Player logic
    //----------------------------------------------------------------------------------
    playerMovement(player, 1.f);

    //----------------------------------------------------------------------------------
    // Ghost logic
    //----------------------------------------------------------------------------------
    
    // Ghost state

    // Ghost movement


    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_Q) || player.m_life == 0U)
    {
        finishScreen = 1U;
        PlaySound(fxGameOver);
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Draw background
    ClearBackground(BLACK);

    // Add text about score points
    stringInfo = "SCORE: " + std::to_string(score);
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 8.25f);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, RED);

    // Update the elapsed time since the gameplay screen was initialized
    end = std::chrono::system_clock::now();
    gameplayTime = end - start;

    // Add text about time
    stringInfo = "TIME: " + std::to_string(gameplayTime.count());
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 2.5f);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, WHITE);

    // Add text about landed soldiers
    stringInfo = "LIFES: " + std::to_string(player.m_life);
    infoPosX = static_cast<uint16_t>(GetScreenWidth() / 1.25f);
    infoPosY = 5U;
    DrawText(stringInfo.c_str(), infoPosX, infoPosY, 22U, RED);

    //----------------------------------------------------------------------------------
    // Map
    //----------------------------------------------------------------------------------
    DrawTilemap(tilemap, texTileset);   // Draw tilemap using provide tileset

    //----------------------------------------------------------------------------------
    // Ghost
    //----------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------
    // Player
    //----------------------------------------------------------------------------------
    
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    UnloadImage(imTileset);
    UnloadTilemap(tilemap);
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
