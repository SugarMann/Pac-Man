
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

// Includes
#include <vector>
#include <stdio.h>              // Standard input-output C library
#include <stdlib.h>             // Memory management functions: malloc(), free()
#include <string.h>             // String manipulation functions: strrchr(), strcmp()

#include "GlobalGameDefines.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

	//----------------------------------------------------------------------------------
	// Draw methods
	//----------------------------------------------------------------------------------
	void DrawTilemap(Tilemap map, Texture2D tileset);
	Tilemap LoadTilemap(const char* valuesMap, const char* collidersMap, const char* objectsMap);

	//----------------------------------------------------------------------------------
	// Unload methods
	//----------------------------------------------------------------------------------
	void UnloadTilemap(Tilemap map);

#ifdef __cplusplus
}
#endif

#endif // !GAME_MANAGER_H
