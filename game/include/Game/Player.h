
#ifndef PLAYER_H
#define PLAYER_H

// Includes
#include <stdint.h>
#include <string>

#include "raylib.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

class Player {

	// Private Variables

public:
	// Public variables
	uint8_t m_life;
	int m_x;
	int m_y;
	uint8_t m_prevMov; // 0 - right, 1 - up, 2 - left, 3 - down
	float m_speed;
	bool m_alive;

	// Contructors
	Player();
	Player(uint16_t x, uint16_t y, float speed);

	// Methods
	void Player::playerMovement();

};

#ifdef __cplusplus
}
#endif

#endif // !PLAYER_H
