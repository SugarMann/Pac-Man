
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// Includes
#include <vector>

#include "Game/Player.h"
#include "Game/Ghost.h"
#include "GlobalGameDefines.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Game logic
//----------------------------------------------------------------------------------
	void playerLogic(Player& player, Tilemap& tilemap, uint32_t& score, bool& isFrightened);

//----------------------------------------------------------------------------------
// Remove methods declaration
//----------------------------------------------------------------------------------
	void removePlayer(Player player);
	void removeHelicopter(Ghost helicopter);

#ifdef __cplusplus
}
#endif

#endif // !GAME_MANAGER_H
