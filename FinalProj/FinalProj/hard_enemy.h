#pragma once
#include <SFML\Graphics.hpp>
#include "enemy.h"

class HardEnemy : public Enemy {
public:
	HardEnemy() : HardEnemy(Vector2f(0, 0)) {};
	HardEnemy(Vector2f blitPosition) : Enemy(9.0f, 2.0f, &hard_enemyT, blitPosition) {};
	void Update(Player *user);

};