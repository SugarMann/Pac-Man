
// Includes
#include <algorithm>

#include "raylib.h"
#include "TextureManager.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Initialization methods definition
//----------------------------------------------------------------------------------

// Unload tilemap data from memory
void UnloadTilemap(Tilemap map)
{
    if (map.tiles != NULL) free(map.tiles);
}

// Draw tilemap using tileset
void DrawTilemap(Tilemap map, Texture2D tileset)
{
    for (int y = 0; y < map.tileCountY; y++)
    {
        for (int x = 0; x < map.tileCountX; x++)
        {
            // Draw each piece of the tileset in the right position to build map
            DrawTextureRec(tileset, tilesetRecs[map.tiles[y * map.tileCountX + x].value - 1],
                { map.position.x + x * map.tileSize, map.position.y + y * map.tileSize}, WHITE);
            // Draw objects if they exist
            if (map.tiles[y * map.tileCountX + x].object != -1) {
                DrawTextureRec(tileset, tilesetRecs[map.tiles[y * map.tileCountX + x].object -1],
                    { map.position.x + x * map.tileSize, map.position.y + y * map.tileSize }, WHITE);
            }
        }
    }
}

//Draw player using tileset
void DrawPlayer(Player& player, Texture2D tileset, bool texChoice)
{
    if (texChoice)
    {
        if (player.m_prevMov == 0U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[0],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else if (player.m_prevMov == 1U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[4],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else if (player.m_prevMov == 2U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[2],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else if (player.m_prevMov == 3U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[6],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else
        {
            DrawTextureRec(tileset, playerTilesetRecs[0],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
    }
    else
    {
        if (player.m_prevMov == 0U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[1],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else if (player.m_prevMov == 1U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[5],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else if (player.m_prevMov == 2U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[3],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else if (player.m_prevMov == 3U)
        {
            DrawTextureRec(tileset, playerTilesetRecs[7],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
        else
        {
            DrawTextureRec(tileset, playerTilesetRecs[1],
                { static_cast<float>(player.m_x), static_cast<float>(player.m_y) }, WHITE);
        }
    }
    
}

//Draw player using tileset
void DrawGhost(Ghost& ghost, Texture2D tileset, bool texChoice, bool isFrightened)
{
    if (texChoice) // boolean to choose which texture depending of time
    {
        if (isFrightened && ghost.m_alive) // is the ghost frightened?
        {
            DrawTextureRec(tileset, ghostTilesetRecs[8],
                { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
        }
        else // if not, just use the normal textures
        {
            if (ghost.m_prevMov == 0U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[0],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[10],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else if (ghost.m_prevMov == 1U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[4],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[13],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else if (ghost.m_prevMov == 2U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[2],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[11],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else if (ghost.m_prevMov == 3U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[6],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[13],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else
            {
                DrawTextureRec(tileset, ghostTilesetRecs[0],
                    { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
            }
        }
    }
    else 
    {
        if (isFrightened && ghost.m_alive) // is the ghost frightened?
        {
            DrawTextureRec(tileset, ghostTilesetRecs[9],
                { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
        }
        else // if not, just use the normal textures
        {
            if (ghost.m_prevMov == 0U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[1],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[10],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else if (ghost.m_prevMov == 1U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[5],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[12],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else if (ghost.m_prevMov == 2U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[3],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[11],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else if (ghost.m_prevMov == 3U)
            {
                if (ghost.m_alive)
                {
                    DrawTextureRec(tileset, ghostTilesetRecs[7],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
                else {
                    DrawTextureRec(tileset, ghostTilesetRecs[13],
                        { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
                }
            }
            else
            {
                DrawTextureRec(tileset, ghostTilesetRecs[1],
                    { static_cast<float>(ghost.m_x), static_cast<float>(ghost.m_y) }, WHITE);
            }
        }
    }    
}

Tilemap LoadTilemap(const char* valuesMap, const char* collidersMap, const char* objectsMap)
{
    Tilemap map = { 0 };
    const char* fileExt;

    if ((fileExt = strrchr(valuesMap, '.')) != NULL)
    {
        // Check if file extension is supported
        if (strcmp(fileExt, ".txt") == 0)
        {
            int counter = 0;
            int temp = 0;

            // Read values from text file
            FILE* valuesFile = fopen(valuesMap, "rt");

            while (!feof(valuesFile))
            {
                fscanf(valuesFile, "%i", &temp);
                counter++;
            }

            rewind(valuesFile);        // Return to the beginning of the file, to read again

            map.tiles = (Tile*)malloc(counter * sizeof(Tile));

            map.tileCountX = 27;
            map.tileCountY = 23;
            counter = 0;

            while (!feof(valuesFile))
            {
                fscanf(valuesFile, "%i", &map.tiles[counter].value);
                counter++;
            }

            fclose(valuesFile);

            // Read values from text file
            // NOTE: Colliders map data MUST match values data, 
            // or we need to do a previous check like done with values data
            FILE* collidersFile = fopen(collidersMap, "rt");
            counter = 0;
            temp = 0;

            while (!feof(collidersFile))
            {
                fscanf(collidersFile, "%i", &temp);
                map.tiles[counter].collider = temp;

                counter++;
            }
            fclose(collidersFile);

            // Read values from text file
            // NOTE: Objects map data MUST match values data, 
            // or we need to do a previous check like done with values data
            FILE* objectsFile = fopen(objectsMap, "rt");
            counter = 0;
            temp = 0;

            while (!feof(objectsFile))
            {
                fscanf(objectsFile, "%i", &temp);
                map.tiles[counter].object = temp;

                // If this tile is an object we save the score value
                if (temp != -1)
                {
                    if (temp == 30U) {
                        map.tiles[counter].score = 10U;
                    }
                    else if (temp == 29U) {
                        map.tiles[counter].score = 50U;
                    }
                }

                counter++;
            }
            fclose(objectsFile);

        }
    }

    return map;
}