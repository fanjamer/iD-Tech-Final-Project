#include "enemy.h"

Enemy::Enemy() {

	maxhp = 10;
	hp = maxhp;

	dmg = 3;

	attacking = false;

	movU = false;
	movD = false;
	movL = false;
	movR = false;

	alive = true;

}

Enemy::Enemy(float maximumHealth, float enemyDamage, Texture *txt, Vector2f position) {

	maxhp = maximumHealth;
	dmg = enemyDamage;

	sprite.setTexture(*txt);

	pos = position;

}