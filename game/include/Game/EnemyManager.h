
#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

// Includes
#include <vector>

#include "raylib.h"
#include "Game/Ghost.h"
#include "Game/Player.h"
#include "GlobalGameDefines.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

	//----------------------------------------------------------------------------------
	// Enemy Manager Functions Declaration
	//----------------------------------------------------------------------------------
	void ghostLogic(Ghost& ghost, Player& player, Tilemap& tilemap, bool& isFrightened);

#ifdef __cplusplus
}
#endif

#endif // !ENEMY_MANAGER_H