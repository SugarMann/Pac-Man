
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

// Includes
#include <vector>
#include <stdio.h>              // Standard input-output C library
#include <stdlib.h>             // Memory management functions: malloc(), free()
#include <string.h>             // String manipulation functions: strrchr(), strcmp()

#include "GlobalGameDefines.h"
#include "Game/Player.h"
#include "Game/Ghost.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

	//----------------------------------------------------------------------------------
	// Draw methods
	//----------------------------------------------------------------------------------
	void DrawTilemap(Tilemap map, Texture2D tileset);
	void DrawPlayer(Player& player, Texture2D tileset, bool texChoice);
	void DrawGhost(Ghost& ghost, Texture2D tileset, bool texChoice, bool isFrightened);
	Tilemap LoadTilemap(const char* valuesMap, const char* collidersMap, const char* objectsMap);

	//----------------------------------------------------------------------------------
	// Unload methods
	//----------------------------------------------------------------------------------
	void UnloadTilemap(Tilemap map);

#ifdef __cplusplus
}
#endif

#endif // !GAME_MANAGER_H
