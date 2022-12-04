
// Includes
#include <algorithm>
#include <string>

#include "raylib.h"
#include "GameManager.h"

//----------------------------------------------------------------------------------
// Initialization methods definition
//----------------------------------------------------------------------------------
void playerLogic(Player& player, Tilemap& tilemap, uint32_t& score, bool& isFrightened)
{
    // Save old positions
    uint16_t oldPosX = player.m_x;
    uint16_t oldPosY = player.m_y;

    // Collision boolean
    bool isCollision = false;

    switch (player.m_prevMov) {
    case 0: // Right
        
        // Player try to move
        player.playerMovement();

        if (player.m_prevMov == 2) // Forbidden
        { 
            player.m_x = oldPosX;
            player.m_y = oldPosY;
            player.m_prevMov = 0U; //Right
        }

        //Check if there are somo collisions with the tilemap
        for (int y = 0; y < tilemap.tileCountY; y++)
        {
            for (int x = 0; x < tilemap.tileCountX; x++)
            {

                Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                // TODO: Review player padding for a better collision with walls
                if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // There is a collision! Restore player position (undo player position update!) 
                    player.m_x = oldPosX;
                    player.m_y = oldPosY;
                    player.m_prevMov = 0U; //Right
                    isCollision = true;
                }
                // Add score from objects
                if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 30) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxWaka);
                }
                else if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 29) && CheckCollisionRecs(playerCollision, tilemapCollision)) 
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxCherry);
                    // Ghost goes frigthened
                    isFrightened = true;
                }
            }
        }
        break;

    case 1: // Up

        // Player try to move
        player.playerMovement();

        if (player.m_prevMov == 3) // Forbidden
        {
            player.m_x = oldPosX;
            player.m_y = oldPosY;
            player.m_prevMov = 1U; // Up
        }

        //Check if there are somo collisions with the tilemap
        for (int y = 0; y < tilemap.tileCountY; y++)
        {
            for (int x = 0; x < tilemap.tileCountX; x++)
            {

                Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                // TODO: Review player padding for a better collision with walls
                if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // There is a collision! Restore player position (undo player position update!) 
                    player.m_x = oldPosX;
                    player.m_y = oldPosY;
                    player.m_prevMov = 1U; //Up
                    isCollision = true;
                }
                // Add score from objects
                if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 30) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxWaka);
                }
                else if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 29) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxCherry);
                    // Ghost goes frigthened
                    isFrightened = true;
                }
            }
        }
        break;

    case 2: // Left
        // Player try to move
        player.playerMovement();

        if (player.m_prevMov == 0) // Forbidden
        {
            player.m_x = oldPosX;
            player.m_y = oldPosY;
            player.m_prevMov = 2U; // Left
        }

        //Check if there are somo collisions with the tilemap
        for (int y = 0; y < tilemap.tileCountY; y++)
        {
            for (int x = 0; x < tilemap.tileCountX; x++)
            {

                Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                // TODO: Review player padding for a better collision with walls
                if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // There is a collision! Restore player position (undo player position update!) 
                    player.m_x = oldPosX;
                    player.m_y = oldPosY;
                    player.m_prevMov = 2U; //Left
                    isCollision = true;
                }
                // Add score from objects
                if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 30) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxWaka);
                }
                else if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 29) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxCherry);
                    // Ghost goes frigthened
                    isFrightened = true;
                }
            }
        }
        break;

    case 3: // Down
        
        // Player try to move
        player.playerMovement();

        if (player.m_prevMov == 1) // Forbidden
        {
            player.m_x = oldPosX;
            player.m_y = oldPosY;
            player.m_prevMov = 0U; // Down
        }

        //Check if there are somo collisions with the tilemap
        for (int y = 0; y < tilemap.tileCountY; y++)
        {
            for (int x = 0; x < tilemap.tileCountX; x++)
            {

                Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                // TODO: Review player padding for a better collision with walls
                if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // There is a collision! Restore player position (undo player position update!) 
                    player.m_x = oldPosX;
                    player.m_y = oldPosY;
                    player.m_prevMov = 3U; //Down
                    isCollision = true;
                }
                // Add score from objects
                if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 30) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxWaka);
                }
                else if ((tilemap.tiles[y * tilemap.tileCountX + x].object == 29) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // Remove object
                    tilemap.tiles[y * tilemap.tileCountX + x].object = -1;
                    // Add the score
                    score += tilemap.tiles[y * tilemap.tileCountX + x].score;
                    tilemap.tiles[y * tilemap.tileCountX + x].score = 0U;
                    PlaySound(fxCherry);
                    // Ghost goes frigthened
                    isFrightened = true;
                }
            }
        }
        break;

    default:
        
        // Player try to move
        player.playerMovement();

        //Check if there are somo collisions with the tilemap
        for (int y = 0; y < tilemap.tileCountY; y++)
        {
            for (int x = 0; x < tilemap.tileCountX; x++)
            {

                Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                // TODO: Review player padding for a better collision with walls
                if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(playerCollision, tilemapCollision))
                {
                    // There is a collision! Restore player position (undo player position update!) 
                    player.m_x = oldPosX;
                    player.m_y = oldPosY;
                    player.m_prevMov = 5U; //No movement before
                    isCollision = true;
                }
            }
        }
        break;
    }
}

// Unload tilemap data from memory
static void UnloadTilemap(Tilemap map)
{
    if (map.tiles != NULL) free(map.tiles);
}

// Draw tilemap using tileset
static void DrawTilemap(Tilemap map, Texture2D tileset)
{
    for (int y = 0; y < map.tileCountY; y++)
    {
        for (int x = 0; x < map.tileCountX; x++)
        {
            // Draw each piece of the tileset in the right position to build map
            DrawTextureRec(tileset, tilesetRecs[map.tiles[y * map.tileCountX + x].value - 1],
                { map.position.x + x * map.tileSize, map.position.y + y * map.tileSize }, WHITE);
        }
    }
}