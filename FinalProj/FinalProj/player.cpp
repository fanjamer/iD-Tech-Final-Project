#include "player.h"

Player::Player() {

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