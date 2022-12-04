
#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

// Includes
#include <vector>

#include "raylib.h"
#include "Game/Ghost.h"
#include "Game/Player.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

	//----------------------------------------------------------------------------------
	// Enemy Manager Functions Declaration
	//----------------------------------------------------------------------------------
	void createHelicopter(std::vector<Ghost>& helicopters, float& speed, Texture2D& spriteRight, Texture2D& spriteLeft, float& scale);
	void helicoptersMovement(std::vector<Ghost>& helicopters);
	void removeHelicopters(std::vector<Ghost>& helicopters, std::vector<std::pair<Vector2, float>>& projectiles, uint32_t& score);

#ifdef __cplusplus
}
#endif

#endif // !ENEMY_MANAGER_H