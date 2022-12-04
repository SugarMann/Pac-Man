// Includes
#include "Game/Ghost.h"

// Ghost constructors
Ghost::Ghost() {
	m_position = Vector2();
	m_speed = 0.f;
	m_alive = true;
	m_sprite = Texture2D();
	m_rightOrientation = true;
	m_scale = 1.f;
	m_despawn = 15U;
}

Ghost::Ghost(const Vector2& position, const float& speed, Texture2D& sprite, bool rightOrientation, float& scale) {
	m_position = position;
	m_speed = speed;
	m_alive = true;
	m_sprite = sprite;
	m_rightOrientation = rightOrientation;
	m_scale = scale;
	m_despawn = 15U;
}


// Setters
void Ghost::setPosition(const Vector2& position) 
{
	m_position = position;
}

void Ghost::setSpeed(const float& speed)
{
	m_speed = speed;
}

void Ghost::setScale(const float& scale)
{
	m_scale = scale;
}

void Ghost::setTexture(Texture2D& sprite)
{
	m_sprite = sprite;
}

//Ghost destructor
Ghost::~Ghost()
{
	//TODO: Think about what is here
}