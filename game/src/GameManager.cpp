
// Includes
#include <algorithm>

#include "raylib.h"
#include "GameManager.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Initialization methods definition
//----------------------------------------------------------------------------------
void playerMovement(Player& player, float speed)
{
    if (IsKeyDown(KEY_DOWN)) player.m_y += speed;
    else if (IsKeyDown(KEY_UP)) player.m_y -= speed;

    if (IsKeyDown(KEY_RIGHT)) player.m_x += speed;
    else if (IsKeyDown(KEY_LEFT)) player.m_x -= speed;
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

void projectilesMovement(std::vector<std::pair<Vector2, float>>& projectiles, float projectileSpeed)
{
    for (std::pair<Vector2, float>& projectile : projectiles)
    {
        // Movement
        // converting degrees to radians
        float x = projectile.second * 3.14159f / 180.f;

        projectile.first.x = projectile.first.x + (projectileSpeed * static_cast<float>(sin(x)));
        projectile.first.y = projectile.first.y - (projectileSpeed * static_cast<float>(cos(x)));
    }
}

void removeProjectiles(std::vector<std::pair<Vector2, float>>& projectiles)
{
    // Out of bounds
    projectiles.erase(
        std::remove_if(
            projectiles.begin(),
            projectiles.end(),
            [](std::pair<Vector2, float>& pr) -> bool {
                if (pr.first.x > GetScreenWidth() || pr.first.y < 0)
                    return true;
                else if (pr.first.y > GetScreenHeight() || pr.first.y < 0)
                    return true;
                else
                    return false;
            }
        ),
        projectiles.end()
    );
}

void removeProjectile(std::vector<std::pair<Vector2, float>>& projectiles, std::pair<Vector2, float> projectile)
{
    // Remove one specific projectile
    for (std::vector<std::pair<Vector2, float>>::iterator iter = projectiles.begin(); iter != projectiles.end(); ++iter)
    {
        if (iter->first.x == projectile.first.x && iter->first.y == projectile.first.y)
        {
            projectiles.erase(iter);
            break;
        }
    }
}

//----------------------------------------------------------------------------------
// Remove methods difinition
//----------------------------------------------------------------------------------
void removePlayer(Player player)
{

}
void removeHelicopter(Ghost helicopter)
{

}