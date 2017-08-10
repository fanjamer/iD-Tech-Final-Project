#pragma once
#include <SFML/Graphics.hpp>
#include "text_img.h"
#include "player.h"
#include "wave.h"
#include <iostream>
#include <string>

#include "easy_enemy.h"
#include "medium_enemy.h"
#include "hard_enemy.h"

#include "enemy.h"

Wave wave;

/*| Wave One: 5 Easy | 1 Medium | 0 Hard |*/Wave one_easy(1);
												
/*| Wave Two: 10 Easy | 2 Medium | 1 Hard |*/Wave two_easy(2);
												
												
/*| Wave Three: 20 Easy | 4 Medium | 2 Hard |*/Wave three_medium(4);
												
/*| Wave Four: 30 Easy | 6 Medium | 3 Hard |*/Wave four_medium(6);
												
												
/*| Wave Five: 50 Easy | 10 Medium | 5 Hard |*/Wave five_hard(10);
												
												
												
/*| Scientific |*/	Wave six_impossible(16);
/*| Impossibility:  | 80   Easy |				
					| 16 Medium |				
					| 8    Hard |				
*/												
												
int easyMax = 0;
int mediumMax = 0;
int hardMax = 0;

Sprite gSprite;

Player player;

EasyEnemy easyE;


float timer;

Event event;