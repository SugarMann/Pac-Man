
// Includes
#include "Game/EnemyManager.h"
#include "GameManager.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Enemy Manager Definition (local)
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Enemy Manager Functions Definition
//----------------------------------------------------------------------------------
void ghostLogic(Ghost& ghost, Player& player, Tilemap& tilemap, bool& isFrightened)
{
    // Save old positions
    uint16_t oldPosX = ghost.m_x;
    uint16_t oldPosY = ghost.m_y;
    uint16_t prob = 0U;

    if (isFrightened && ghost.m_alive)
    {
        // Random movement (Frightened effect)
        prob = rand() % 100 + 1;
        if (prob < 25U && tileCount >= 8U)
        {
            ghost.m_x++;
            tileCount = 0U;
        }
        else if (prob >= 25U && prob < 50U && tileCount >= 8U)
        {
            ghost.m_x--;
            tileCount = 0U;
        }
        else if (prob >= 50U && prob < 75U && tileCount >= 8U)
        {
            ghost.m_y++;
            tileCount = 0U;
        }
        else if (prob > 75U && tileCount >= 8U)
        {
            ghost.m_y--;
            tileCount = 0U;
        }

        // Check if there are somo collisions with the tilemap
        for (int y = 0; y < tilemap.tileCountY; y++)
        {
            for (int x = 0; x < tilemap.tileCountX; x++)
            {

                Rectangle ghostCollision = { ghost.m_x + PLAYER_COLLISION_PADDING, ghost.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                // TODO: Review ghost padding for a better collision with walls
                if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(ghostCollision, tilemapCollision))
                {
                    // There is a collision! Restore ghost position (undo ghost position update!) 
                    ghost.m_x = oldPosX;
                    ghost.m_y = oldPosY;
                    ghost.m_prevMov = 0U; //Right
                }
                if (CheckCollisionRecs(ghostCollision, playerCollision) && ghost.m_alive) // Ghost dead
                {
                    // There is a collision! Restore ghost position (undo ghost position update!) 
                    score += 50U;
                    ghost.m_alive = false;
                    PlaySound(fxEatingGhost);
                }
            }
        }
    }

    else if (!isFrightened && ghost.m_alive)// if ghost is not frightened, normal behaviour
    {
        switch (ghost.m_prevMov) {
        case 0: // Right

            // Player try to move
            if (tileCount >= 8U) // Update movement
            {
                ghost.ghostMovement(player);
                tileCount = 0U;
            }  else {
                ghost.m_x += ghost.m_speed;
            }

            //Check if there are somo collisions with the tilemap
            for (int y = 0; y < tilemap.tileCountY; y++)
            {
                for (int x = 0; x < tilemap.tileCountX; x++)
                {

                    Rectangle ghostCollision = { ghost.m_x + PLAYER_COLLISION_PADDING, ghost.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                    // TODO: Review ghost padding for a better collision with walls
                    if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(ghostCollision, tilemapCollision))
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        ghost.m_x = oldPosX;
                        ghost.m_y = oldPosY;
                        ghost.m_prevMov = 0U; //Right
                    }
                    if (CheckCollisionRecs(ghostCollision, playerCollision)) // Player dead
                    {
                        // There is a collision! Restore player and ghost position
                        player.m_life--;
                        player.m_x = GetScreenWidth() / 2 + 16;
                        player.m_y = GetScreenHeight() / 2 + 176;
                        ghost.m_x = GetScreenWidth() / 2;
                        ghost.m_y = GetScreenHeight() / 2 - 80;
                        PlaySound(fxDeath);
                    }
                }
            }
            break;

        case 1: // Up

            // Player try to move
            if (tileCount >= 8U) // Update movement
            {
                ghost.ghostMovement(player);
                tileCount = 0U;
            }  else {
                ghost.m_y -= ghost.m_speed;
            }

            //Check if there are somo collisions with the tilemap
            for (int y = 0; y < tilemap.tileCountY; y++)
            {
                for (int x = 0; x < tilemap.tileCountX; x++)
                {

                    Rectangle ghostCollision = { ghost.m_x + PLAYER_COLLISION_PADDING, ghost.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                    // TODO: Review ghost padding for a better collision with walls
                    if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(ghostCollision, tilemapCollision))
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        ghost.m_x = oldPosX;
                        ghost.m_y = oldPosY;
                        ghost.m_prevMov = 1U; //Up
                    }
                    if (CheckCollisionRecs(ghostCollision, playerCollision)) // Player dead
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        player.m_life--;
                        player.m_x = GetScreenWidth() / 2 + 16;
                        player.m_y = GetScreenHeight() / 2 + 176;
                        ghost.m_x = GetScreenWidth() / 2;
                        ghost.m_y = GetScreenHeight() / 2 - 80;
                        PlaySound(fxDeath);
                    }
                }
            }
            break;

        case 2: // Left
            
            // Player try to move
            if (tileCount >= 8U) // Update movement
            {
                ghost.ghostMovement(player);
                tileCount = 0U;
            }  else {
                ghost.m_x -= ghost.m_speed;
            }

            //Check if there are somo collisions with the tilemap
            for (int y = 0; y < tilemap.tileCountY; y++)
            {
                for (int x = 0; x < tilemap.tileCountX; x++)
                {

                    Rectangle ghostCollision = { ghost.m_x + PLAYER_COLLISION_PADDING, ghost.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                    // TODO: Review ghost padding for a better collision with walls
                    if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(ghostCollision, tilemapCollision))
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        ghost.m_x = oldPosX;
                        ghost.m_y = oldPosY;
                        ghost.m_prevMov = 2U; //Left
                    }
                    if (CheckCollisionRecs(ghostCollision, playerCollision)) // Player dead
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        player.m_life--;
                        player.m_x = GetScreenWidth() / 2 + 16;
                        player.m_y = GetScreenHeight() / 2 + 176;
                        ghost.m_x = GetScreenWidth() / 2;
                        ghost.m_y = GetScreenHeight() / 2 - 80;
                        PlaySound(fxDeath);
                    }
                }
            }
            break;

        case 3: // Down

            // Player try to move
            if (tileCount >= 8U) // Update movement
            {
                ghost.ghostMovement(player);
                tileCount = 0U;
            }  else {
                ghost.m_y += ghost.m_speed;
            }

            //Check if there are somo collisions with the tilemap
            for (int y = 0; y < tilemap.tileCountY; y++)
            {
                for (int x = 0; x < tilemap.tileCountX; x++)
                {

                    Rectangle ghostCollision = { ghost.m_x + PLAYER_COLLISION_PADDING, ghost.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle playerCollision = { player.m_x + PLAYER_COLLISION_PADDING, player.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                    // TODO: Review ghost padding for a better collision with walls
                    if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(ghostCollision, tilemapCollision))
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        ghost.m_x = oldPosX;
                        ghost.m_y = oldPosY;
                        ghost.m_prevMov = 3U; //Down
                    }
                    if (CheckCollisionRecs(ghostCollision, playerCollision)) // Player dead
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        player.m_life--;
                        player.m_x = GetScreenWidth() / 2 + 16;
                        player.m_y = GetScreenHeight() / 2 + 176;
                        ghost.m_x = GetScreenWidth() / 2;
                        ghost.m_y = GetScreenHeight() / 2 - 80;
                        PlaySound(fxDeath);
                    }
                }
            }
            break;

        default:

            // Ghost try to move
            ghost.ghostMovement(player);

            //Check if there are somo collisions with the tilemap
            for (int y = 0; y < tilemap.tileCountY; y++)
            {
                for (int x = 0; x < tilemap.tileCountX; x++)
                {

                    Rectangle ghostCollision = { ghost.m_x + PLAYER_COLLISION_PADDING, ghost.m_y + PLAYER_COLLISION_PADDING, 32, 32 };
                    Rectangle tilemapCollision = { tilemap.position.x + x * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.position.y + y * tilemap.tileSize + PLAYER_COLLISION_PADDING, tilemap.tileSize, tilemap.tileSize };

                    // TODO: Review ghost padding for a better collision with walls
                    if ((tilemap.tiles[y * tilemap.tileCountX + x].collider == 0) && CheckCollisionRecs(ghostCollision, tilemapCollision))
                    {
                        // There is a collision! Restore ghost position (undo ghost position update!) 
                        ghost.m_x = oldPosX;
                        ghost.m_y = oldPosY;
                        ghost.m_prevMov = 5U; //No movement before
                    }
                }
            }
            break;
        }
    } 

else if (!ghost.m_alive)
    {
        ghost.m_x = oldPosX;
        ghost.m_y = oldPosY;
    }

    // Update tile account
    tileCount++;

}