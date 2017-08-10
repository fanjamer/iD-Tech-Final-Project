#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

static Texture grassTexture;
static Texture playerTexture;

static Font gameOverFont;
static Text gameOverText;
static Text waveNumberText1;
static Text waveNumberText2;

static IntRect playerLeft[4] = {
	IntRect(0, 0, 128, 128),
	IntRect(128, 0, 128, 128),
	IntRect(256, 0, 128, 128),
	IntRect(128, 0, 128, 128),
};
static IntRect playerRight[4] = {
	IntRect(0, 256, 128, 128),
	IntRect(128, 256, 128, 128),
	IntRect(256, 256, 128, 128),
	IntRect(128, 256, 128, 128),
};
static IntRect playerUp[4] = {

	IntRect(0, 128, 128, 128),
	IntRect(128, 128, 128, 128),
	IntRect(256, 128, 128, 128),
	IntRect(128, 128, 128, 128)
};
static IntRect playerDown[4] = {
	IntRect(384, 256, 128, 128),
	IntRect(512, 256, 128, 128),
	IntRect(640, 256, 128, 128),
	IntRect(512, 256, 128, 128)
};

static Texture easy_enemyT;
static Texture med_enemyT;
static Texture hard_enemyT;
static Texture impossible_enemyT; 

static RectangleShape border;