
// Includes
#include "Game/EnemyManager.h"
#include "GameManager.h"
#include "GlobalGameDefines.h"

//----------------------------------------------------------------------------------
// Enemy Manager Definition (local)
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Enemy Manager Functions Definition
//----------------------------------------------------------------------------------
void createHelicopter(std::vector<Ghost>& helicopters, float& speed, Texture2D& spriteRight, Texture2D& spriteLeft, float& scale)
{
	// 50% of possibilities to get the helicopter orientation
	uint8_t prob = std::rand() % 100U;

	if (prob >= 50U) // Right
	{
		if (prob >= 75U) // Highest position 
		{
			float posX = 0.f - spriteLeft.width * scale;
			float posY = 50.f;
			Ghost helicopter(Vector2 {posX, posY}, speed, spriteRight, true, scale);
			helicopters.push_back(helicopter);
		}
		else // Lowest position
		{
			float posX = 0.f - spriteLeft.width * scale;
			float posY = 100.f;
			Ghost helicopter(Vector2{posX, posY}, speed, spriteRight, true, scale);
			helicopters.push_back(helicopter);
		}
	}
	else // From left
	{
		if (prob <= 25U) // Highest position 
		{
			float posX = GetScreenWidth();
			float posY = 50.f;
			Ghost helicopter(Vector2{posX, posY}, speed, spriteLeft, false, scale);
			helicopters.push_back(helicopter);
		}
		else // Lowest position
		{
			float posX = GetScreenWidth();
			float posY = 100.f;
			Ghost helicopter(Vector2{posX, posY}, speed, spriteLeft, false, scale);
			helicopters.push_back(helicopter);
		}
	}

}

void helicoptersMovement(std::vector<Ghost>& helicopters)
{
	for (Ghost& helicopter : helicopters)
	{
		if (helicopter.m_rightOrientation && helicopter.m_alive)
		{
			// helicopter only moves on x axis
			float newPosX = helicopter.getPosition().x + 1.f * helicopter.getSpeed();
			float newPosY = helicopter.getPosition().y;
			helicopter.setPosition(Vector2 {newPosX, newPosY});
		}
		else if (!helicopter.m_rightOrientation && helicopter.m_alive)
		{
			// helicopter only moves on x axis
			float newPosX = helicopter.getPosition().x - 1.f * helicopter.getSpeed();
			float newPosY = helicopter.getPosition().y;
			helicopter.setPosition(Vector2{ newPosX, newPosY });
		}
	}
}

void removeHelicopters(std::vector<Ghost>& helicopters, std::vector<std::pair<Vector2, float>>& projectiles, uint32_t& score)
{
	// Remove helicopters out of bounds
	helicopters.erase(
		std::remove_if(
			helicopters.begin(),
			helicopters.end(),
			[](Ghost& h) -> bool {
				if (h.m_rightOrientation && h.getPosition().x > GetScreenWidth())
					return true;
				else if (!h.m_rightOrientation && h.getPosition().x < (0.f - h.getTexture().width * 0.75f))
					return true;
				else if (h.m_despawn == 0U)
					return true;
				else
					return false;
			}
		),
		helicopters.end()
	);

	// Kill helicopters in same positions than projectiles
	for (Ghost& helicopter : helicopters)
	{
		for (std::pair<Vector2, float>& projectile : projectiles)
		{
			if (projectile.first.x >= helicopter.getPosition().x && 
				projectile.first.x <= helicopter.getPosition().x + helicopter.getTexture().width * helicopter.getScale())
			{
				if (projectile.first.y >= helicopter.getPosition().y && 
					projectile.first.y <= helicopter.getPosition().y + helicopter.getTexture().height * helicopter.getScale())
				{
					// If the helicopter was alive means player score 10 points and remove THAT bullet
					if (helicopter.m_alive)
					{
						score += 10U;
						removeProjectile(projectiles, projectile);
						PlaySound(fxExplosion);
					}
					// This helicopter is now dead
					helicopter.m_alive = false;
				}
			}
		}
	}

}