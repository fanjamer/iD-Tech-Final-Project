#pragma once
#include <SFML\Graphics.hpp>
#include "enemy.h"

using namespace sf;
using namespace std;

class Wave {
public:
	Wave();
	Wave(int difficulty);				//1 easiest	2 easy		3 medium	4 advanced medium	5 hard		6 impossible

	int diff;

};