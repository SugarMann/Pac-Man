// Includes
#include "Game/Ghost.h"

// Ghost constructors
Ghost::Ghost() {
	m_x = 0;
	m_y = 0;
	m_speed = 1.f;
	m_alive = true;
    m_prevMov = 5U;
}

Ghost::Ghost(uint16_t x, uint16_t y, float speed) {
	m_x = x;
	m_y = y;
	m_speed = speed;
	m_alive = true;
	m_speed = speed;
    m_prevMov = 5U;
}

void Ghost::ghostMovement(Player& player)
{
	// Variables
	float distanceX, distanceY = 0.f;
	int posX, posY = 0;

	if (player.m_x > Ghost::m_x) // Target on right side
	{
		if (player.m_y > Ghost::m_y) // Target under
		{
			posX = Ghost::m_x + Ghost::m_speed;
			posY = Ghost::m_y + Ghost::m_speed;
			distanceX = sqrt(pow(player.m_x - posX, 2) + pow(player.m_y - Ghost::m_y, 2));
			distanceY = sqrt(pow(player.m_x - Ghost::m_x, 2) + pow(player.m_y - posY, 2));

			if (distanceX < distanceY) 
			{
				Ghost::m_x += Ghost::m_speed; // Move in x-axis
				Ghost::m_prevMov = 0U;
			}
			else
			{
				Ghost::m_y += Ghost::m_speed; // Move in y-axis
				Ghost::m_prevMov = 3U;
			}
		}
		else // Target upper
		{
			posX = Ghost::m_x + Ghost::m_speed;
			posY = Ghost::m_y - Ghost::m_speed;
			distanceX = sqrt(pow(player.m_x - posX, 2) + pow(player.m_y - Ghost::m_y, 2));
			distanceY = sqrt(pow(player.m_x - Ghost::m_x, 2) + pow(player.m_y - posY, 2));

			if (distanceX < distanceY)
			{
				Ghost::m_x += Ghost::m_speed; // Move in x-axis
				Ghost::m_prevMov = 0U;
			}
			else
			{
				Ghost::m_y -= Ghost::m_speed; // Move in y-axis
				Ghost::m_prevMov = 1U;
			}
		}
	}
	else // Target on the left side
	{
		if (player.m_y > Ghost::m_y) // Target under
		{
			posX = Ghost::m_x - Ghost::m_speed;
			posY = Ghost::m_y + Ghost::m_speed;
			distanceX = sqrt(pow(player.m_x - posX, 2) + pow(player.m_y - Ghost::m_y, 2));
			distanceY = sqrt(pow(player.m_x - Ghost::m_x, 2) + pow(player.m_y - posY, 2));

			if (distanceX < distanceY)
			{
				Ghost::m_x -= Ghost::m_speed; // Move in x-axis
				Ghost::m_prevMov = 2U;
			}
			else
			{
				Ghost::m_y += Ghost::m_speed; // Move in y-axis
				Ghost::m_prevMov = 3U;
			}
		}
		else // Target upper
		{
			posX = Ghost::m_x - Ghost::m_speed;
			posY = Ghost::m_y - Ghost::m_speed;
			distanceX = sqrt(pow(player.m_x - posX, 2) + pow(player.m_y - Ghost::m_y, 2));
			distanceY = sqrt(pow(player.m_x - Ghost::m_x, 2) + pow(player.m_y - posY, 2));

			if (distanceX < distanceY)
			{
				Ghost::m_x -= Ghost::m_speed; // Move in x-axis
				Ghost::m_prevMov = 2U;
			}
			else
			{
				Ghost::m_y -= Ghost::m_speed; // Move in y-axis
				Ghost::m_prevMov = 1U;
			}
		}
	}
}

// Setters
void Ghost::setSpeed(const float& speed)
{
	m_speed = speed;
}

//Ghost destructor
Ghost::~Ghost()
{
	//TODO: Think about what is here
}