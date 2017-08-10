#pragma once
#include <SFML\Graphics.hpp>
#include "enemy.h"

class EasyEnemy : public Enemy {
public:
	EasyEnemy() : EasyEnemy(Vector2f(0, 0)) {};
	EasyEnemy(Vector2f blitPosition) : Enemy(9.0f, 2.0f, &easy_enemyT, blitPosition) {};
	void Update(Player *user);

};