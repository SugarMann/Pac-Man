
#ifndef GLOBAL_GAME_DEFINES_H
#define GLOBAL_GAME_DEFINES_H

#include <stdint.h>
#include <chrono>

#define TILESET_TILES  32                   // Size of tiles
#define PLAYER_COLLISION_PADDING    10      // Player padding to detect collision with walls

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, OPTIONS, GAMEPLAY, ENDING } GameScreen;

typedef struct Tile {
    int value;                  // Tile index value (in tileset)
    bool collider;              // Tile collider (0 -> walkable)
    int object;                 // Tile object
    uint16_t score;              // Score value of the object
    Color color;                // Tile color (could be useful)
} Tile;

typedef struct Tilemap {
    Tile* tiles;                // Tiles data
    int tileCountX;             // Tiles counter X
    int tileCountY;             // Tiles counter Y
    int tileSize;               // Tile size (XY)
    Vector2 position;           // Tilemap position in screen
} Tilemap;

// NOTE: Tileset rectangles are directly provided in this array but
// they can also be loaded from a file... usually generated with
// a tilemap editor software
static Rectangle tilesetRecs[TILESET_TILES] = {
    { 0, 0, 32, 32 },    { 32, 0, 32, 32 },    { 64, 0, 32, 32 },       // 1, 2, 3
    { 0, 32, 32, 32 },   { 32, 32, 32, 32 },   { 64, 32, 32, 32 },      // 4, 5,6
    { 0, 64, 32, 32 },   { 32, 64, 32, 32 },   { 64, 64, 32, 32 },      // 7, 8, 9
    { 96, 0, 32, 32 },   { 128, 0, 32, 32 },   { 160, 0, 32, 32 },      // 10, 11, 12
    { 96, 32, 32, 32 },  { 128, 32, 32, 32 },  { 160, 32, 32, 32 },     // 13, 14, 15
    { 96, 64, 32, 32 },  { 128, 64, 32, 32 },  { 160, 64, 32, 32 },     // 16, 17, 18
    { 192, 0, 32, 32 },  { 192, 32, 32, 32 },  { 192, 64, 32, 32 },     // 19, 20, 21
    { 224, 0, 32, 32 },  { 256, 0, 32, 32 },   { 288, 0, 32, 32 },      // 22, 23 ,24
    { 224, 32, 32, 32 },  { 256, 32, 32, 32 }, { 288, 32, 32, 32 },     // 25, 26, 27
    { 224, 64, 32, 32 }, { 256, 64, 32, 32 },  { 288, 64, 32, 32 }      // 28, 29, 30
};

static Rectangle playerTilesetRecs[TILESET_TILES] = {
    { 0, 0, 32, 32 }, { 32, 0, 32, 32 },        // 1, 2
    { 0, 32, 32, 32 }, { 32, 32, 32, 32 },      // 3, 4
    { 0, 64, 32, 32 }, { 32, 64, 32, 32 },      // 5, 6
    { 0, 96, 32, 32 }, { 32, 96, 32, 32 },      // 7, 8
};

static Rectangle ghostTilesetRecs[TILESET_TILES] = {
    { 0, 0, 32, 32 }, { 32, 0, 32, 32 },        // 1, 2
    { 64, 0, 32, 32 }, { 96, 0, 32, 32 },       // 3, 4
    {128, 0, 32, 32 }, { 160, 0, 32, 32 },      // 5, 6
    {192, 0, 32, 32 }, {224, 0, 32, 32 },       // 7, 8
    {256, 0, 32, 32 }, {288, 0, 32, 32 },       // 9, 10
    {256, 32, 32, 32 }, {288, 32, 32, 32},      // 11, 12
    {320, 32, 32, 32}, {352, 32, 32, 32}        // 13, 14
};

static Rectangle playerDeadTilesetRecs[TILESET_TILES] = {
    { 0, 0, 32, 32 }, { 32, 0, 32, 32 },         // 1, 2
    { 64, 0, 32, 32 }, { 96, 0, 32, 32 },        // 3, 4
    { 128, 0, 32, 32 }, { 192, 0, 32, 32 },      // 5, 6
    { 256, 0, 32, 32 }, { 288, 0, 32, 32 },      // 7, 8
    { 320, 0, 32, 32 }, { 352, 0, 32, 32 },      // 9, 10
    { 384, 0, 32, 32 }, { 416, 0, 32, 32 }       // 11, 12
};

//----------------------------------------------------------------------------------
// Global Variables Declaration (shared by several modules)
//----------------------------------------------------------------------------------
extern GameScreen currentScreen;
extern Font font;
extern Music introMusic;
extern Sound fxCoin;
extern Sound fxWaka;
extern Sound fxGameOver;
extern Sound fxDeath;
extern Sound fxCherry;
extern Sound fxEatingGhost;

extern uint32_t score;
extern uint16_t tileCount;
extern uint16_t difficulty;
extern std::chrono::duration<double> gameplayTime;

#endif // GLOBAL_GAME_DEFINES_H