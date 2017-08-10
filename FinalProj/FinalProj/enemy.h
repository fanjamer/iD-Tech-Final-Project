#pragma once
#include <SFML\Graphics.hpp>
#include "player.h"
#include "text_img.h"

using namespace std;
using namespace sf;

class Enemy {
public:
	Enemy();
	Enemy(float maximumHealth, float enemyDamage, Texture *txt, Vector2f position);

	float hp;
	float maxhp;

	float dmg;

	bool attacking;

	bool movU;
	bool movD;
	bool movL;
	bool movR;

	bool alive;

	Vector2f pos;

	Sprite sprite;
	
	virtual void Update(Player *user) =0;

};