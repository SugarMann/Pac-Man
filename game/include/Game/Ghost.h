
#ifndef HELICOPTER_H
#define HELICOPTER_H

// Includes
#include <stdint.h>

#include "raylib.h"
#include "Game/Player.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

class Ghost {

	// Variables

public:

	// Public Variables
	bool m_alive;
	uint8_t m_prevMov;
	int m_x;
	int m_y;
	float m_speed;

	// Contructors
	Ghost();
	Ghost(uint16_t x, uint16_t y, float speed);

	// Methods
	void ghostMovement(Player& player);

	// Getters and Setters
	void setSpeed(const float& speed);
	float getSpeed() { return m_speed; }

	//Destructor
	~Ghost();
};

#ifdef __cplusplus
}
#endif

#endif // !HELICOPTER_H
