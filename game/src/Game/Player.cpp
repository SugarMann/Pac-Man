// Includes
#include "Game/Player.h"

// Player constructors
Player::Player() {
	m_x = 0;
	m_y = 0;
	m_life = 3U;
	m_prevMov = 5U; // No prev. movement
    m_speed = 1.f;
    m_alive = true;
}

Player::Player(uint16_t x, uint16_t y, float speed) {
	m_x = x;
	m_y = y;
    m_speed = speed;
	m_life = 3U;
	m_prevMov = 5U; // No prev. movement
    m_alive = true;
}

void Player::playerMovement()
{
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        Player::m_y += Player::m_speed;
        Player::m_prevMov = 3U;
    }
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        Player::m_y -= Player::m_speed;
        Player::m_prevMov = 1U;
    }
    else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        Player::m_x += Player::m_speed;
        Player::m_prevMov = 0U;
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        Player::m_x -= Player::m_speed;
        Player::m_prevMov = 2U;
    }
    else {
        if (Player::m_prevMov == 0U)
        {
            Player::m_x += Player::m_speed;
            Player::m_prevMov = 0U;
        }
        else if (Player::m_prevMov == 1U)
        {
            Player::m_y -= Player::m_speed;
            Player::m_prevMov = 1U;
        }
        else if (Player::m_prevMov == 2U)
        {
            Player::m_x -= Player::m_speed;
            Player::m_prevMov = 2U;
        }
        else if (Player::m_prevMov == 3U)
        {
            Player::m_y += Player::m_speed;
            Player::m_prevMov = 3U;
        }
    }
}