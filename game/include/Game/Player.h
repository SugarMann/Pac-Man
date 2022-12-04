
#ifndef PLAYER_H
#define PLAYER_H

// Includes
#include <stdint.h>

#include "raylib.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

class Player {

	// Variables
	Texture2D m_playerSprite;

public:
	// Public variables
	uint8_t m_life;
	uint16_t m_x;
	uint16_t m_y;

	// Contructors
	Player();
	Player(const uint16_t& x, const uint16_t& y, Texture2D& playerSprite);

	// Getters and Setters
	void setPlayerTexture(Texture2D& playerSprite);
	Texture2D getPlayerTexture() { return m_playerSprite;  }

};

#ifdef __cplusplus
}
#endif

#endif // !PLAYER_H
