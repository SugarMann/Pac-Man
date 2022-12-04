
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// Includes
#include <vector>

#include "Game/Player.h"
#include "Game/Ghost.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Game logic
//----------------------------------------------------------------------------------
	void playerMovement(Player& player, float speed);
	void projectilesMovement(std::vector<std::pair<Vector2, float>>& projectiles, float projectileSpeed);
	void removeProjectiles(std::vector<std::pair<Vector2, float>>& projectiles);
	void removeProjectile(std::vector<std::pair<Vector2, float>>& projectiles, std::pair<Vector2, float> projectile);

//----------------------------------------------------------------------------------
// Remove methods declaration
//----------------------------------------------------------------------------------
	void removePlayer(Player player);
	void removeHelicopter(Ghost helicopter);

#ifdef __cplusplus
}
#endif

#endif // !GAME_MANAGER_H
