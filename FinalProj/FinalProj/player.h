#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

//#include "playerVar.h"

using namespace sf;
using namespace std;

class Player {
public:
	Player();

	float hp;
	float maxhp;

	float dmg;

	bool attacking;

	bool movU;
	bool movD;
	bool movL;
	bool movR;

	bool alive;

	Sprite sprite;

};