#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class player {
public:
	player();

	Texture playerUpIdle;
	Texture playerUpMove1;
	Texture playerUpMove2;
	Texture playerUp[3];

	Texture playerDownIdle1;
	Texture playerDownIdle2;
	Texture playerDownIdle3;
	Texture playerDownMove1;
	Texture playerDownMove2;
	Texture playerDown[5];

	Texture playerLeftIdle1;
	Texture playerLeftIdle2;
	Texture playerLeftIdle3;
	Texture playerLeftMove1;
	Texture playerLeftMove2;
	Texture playerLeft[5];

	Texture playerRightIdle1;
	Texture playerRightIdle2;
	Texture playerRightIdle3;
	Texture playerRightMove1;
	Texture playerRightMove2;
	Texture playerRight[5];

	Texture playerMove[4][2];
	Texture playerIdle[4][3];

};