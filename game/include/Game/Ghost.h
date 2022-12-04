
#ifndef HELICOPTER_H
#define HELICOPTER_H

// Includes
#include <stdint.h>

#include "raylib.h"

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

class Ghost {

	// Variables
	Vector2 m_position;
	Texture2D m_sprite;
	float m_speed;
	float m_scale;

public:

	// Public Variables
	bool m_alive;
	bool m_rightOrientation;
	uint8_t m_despawn;

	// Contructors
	Ghost();
	Ghost(const Vector2& position,const float& speed, Texture2D& sprite, bool rightOrientation, float& scale);

	// Getters and Setters
	void setPosition(const Vector2& position);
	void setSpeed(const float& speed);
	void setScale(const float& scale);
	void setTexture(Texture2D& sprite);
	Vector2 getPosition() { return m_position; }
	float getSpeed() { return m_speed; }
	float getScale() { return m_scale; }
	Texture2D getTexture() { return m_sprite; }

	//Destructor
	~Ghost();
};

#ifdef __cplusplus
}
#endif

#endif // !HELICOPTER_H
