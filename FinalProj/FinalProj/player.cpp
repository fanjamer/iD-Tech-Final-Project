#include "player.h"

player::player() {
	Texture playerUp[3] = { playerUpIdle, playerUpMove1, playerUpMove2 };

	Texture playerDown[5] = { playerDownIdle1, playerDownIdle2, playerDownIdle3, playerDownMove1, playerDownMove2 };

	Texture playerLeft[5] = { playerLeftIdle1, playerLeftIdle2, playerLeftIdle3, playerLeftMove1, playerLeftMove2 };

	Texture playerRight[5] = { playerRightIdle1, playerRightIdle2, playerRightIdle3, playerRightMove1, playerRightMove2 };

	Texture playerMove[4][2] =
	{
		{ playerUp[1], playerUp[2] },
		{ playerDown[3], playerDown[4] },
		{ playerLeft[3], playerLeft[4] },
		{ playerRight[3], playerRight[4] }
	};

	Texture playerIdle[4][3] =
	{
		{ playerUp[0], playerUp[0], playerUp[0] },
		{ playerDown[0], playerDown[1], playerDown[2] },
		{ playerLeft[0], playerLeft[1], playerLeft[2] },
		{ playerRight[0], playerRight[1], playerRight[2] }
	};

};