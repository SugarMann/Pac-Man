// Includes
#include "Game/Player.h"

// Player constructors
Player::Player() {
	m_x = 0U;
	m_y = 0U;
	m_life = 3U;
	m_playerSprite = Texture2D();
}

Player::Player(const uint16_t& x, const uint16_t& y, Texture2D& playerSprite) {
	m_x = x;
	m_y = y;
	m_life = 3U;
	m_playerSprite = playerSprite;
}

// Setters
void Player::setPlayerTexture(Texture2D& playerSprite)
{
	m_playerSprite = playerSprite;
}
