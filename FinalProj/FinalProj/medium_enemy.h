#pragma once
#include <SFML\Graphics.hpp>
#include "enemy.h"

class MediumEnemy : public Enemy {
public:
	MediumEnemy() : MediumEnemy(Vector2f(0, 0)) {};
	MediumEnemy(Vector2f blitPosition) : Enemy(9.0f, 2.0f, &med_enemyT, blitPosition) {};
	void Update(Player *user);

};