#include <SFML\Graphics.hpp>
#include "player.h"
#include "main.h"
using namespace sf;
using namespace std;

int main()
{
	///Window///
	int screenSize[2];

	screenSize[0] = 1699;
	screenSize[1] = 867;

	RenderWindow window(VideoMode(screenSize[0], screenSize[1]), "The Ghost, The Hat, And The Scarf");
	window.setPosition(Vector2i(window.getPosition().x, window.getPosition().y - 50));

	///Variables///
	bool mUp = false;
	bool mDown = false;
	bool mLeft = false;
	bool mRight = false;

	bool idleUp = false;
	bool idleDown = false;
	bool idleLeft = true;
	bool idleRight = false;

	Texture texture;

	int frame = 0;

	Texture grassTexture;
	grassTexture.loadFromFile("Textures/grass_tile.png");
	grassTexture.setRepeated(true);

	Sprite grassSprite;
	grassSprite.setTexture(grassTexture);

	grassSprite.setScale(2, 2);
	grassSprite.setPosition(0, 0);

	float idleTimer = 0;
	float movementTimer = 0;

	Sprite playerSprite;
	player ghost;

	{
		{
			{
				ghost.playerIdle[0][0].
					loadFromFile("Textures/up/gameSpriteU.png");
			}

			{
				ghost.playerMove[0][0].
					loadFromFile("Textures/up/gameSpriteUM1.png");
				ghost.playerMove[0][1].
					loadFromFile("Textures/up/gameSpriteUM2.png");
			}
		}


		{
			{
				ghost.playerIdle[1][0].
					loadFromFile("Textures/down/gameSpriteD1.png");
				ghost.playerIdle[1][1].
					loadFromFile("Textures/down/gameSpriteD2.png");
				ghost.playerIdle[1][2].
					loadFromFile("Textures/down/gameSpriteD3.png");
			}

			{
				ghost.playerMove[1][0].
					loadFromFile("Textures/down/gameSpriteDM1.png");
				ghost.playerMove[1][1].
					loadFromFile("Textures/down/gameSpriteDM2.png");
			}
		}


		{
			{
				ghost.playerIdle[2][0].
					loadFromFile("Textures/left/gameSpriteL1.png");
				ghost.playerIdle[2][1].
					loadFromFile("Textures/left/gameSpriteL2.png");
				ghost.playerIdle[2][2].
					loadFromFile("Textures/left/gameSpriteL3.png");
			}

			{
				ghost.playerMove[2][0].
					loadFromFile("Textures/left/gameSpriteLM1.png");
				ghost.playerMove[2][1].
					loadFromFile("Textures/left/gameSpriteLM2.png");
			}
		}


		{
			{
				ghost.playerIdle[3][0].
					loadFromFile("Textures/right/gameSpriteR1.png");
				ghost.playerIdle[3][1].
					loadFromFile("Textures/right/gameSpriteR2.png");
				ghost.playerIdle[3][2].
					loadFromFile("Textures/right/gameSpriteR3.png");
			}

			{
				ghost.playerMove[3][0].
					loadFromFile("Textures/right/gameSpriteRM1.png");
				ghost.playerMove[3][1].
					loadFromFile("Textures/right/gameSpriteRM2.png");
			}
		}
	}
	//Player textures, condenced for your viewing convenience.
	playerSprite.setScale(2, 2);
	playerSprite.setOrigin(Vector2f(16, 16));
	playerSprite.setPosition(Vector2f(100, 100));

	Sprite log[4];

	Texture logText;

	{

		logText.loadFromFile("Textures/log.png");
		logText.setSmooth(true);

		log[0].setTexture(logText);
		log[0].setScale(0.75, 0.75);
		log[0].setPosition(64, 156);
		log[0].setTextureRect(IntRect(0, 0, 52, 52));

		log[1].setTexture(logText);
		log[1].setScale(0.75, 0.75);
		log[1].setPosition(64, 117);
		log[1].setTextureRect(IntRect(52, 0, 52, 52));

		log[2].setTexture(logText);
		log[2].setScale(0.75, 0.75);
		log[2].setPosition(64, 78);
		log[2].setTextureRect(IntRect(104, 0, 52, 52));

		log[3].setTexture(logText);
		log[3].setScale(0.75, 0.75);
		log[3].setPosition(64, 39);
		log[3].setTextureRect(IntRect(156, 0, 52, 52));
	}
	//Tree Stuff, collapsed to make program easier to read.

	Clock clock;

	View camera(Vector2f(50, 50), Vector2f(100, 100));

	camera.setSize(screenSize[0], screenSize[1]);
	camera.setCenter(playerSprite.getPosition().x, playerSprite.getPosition().y);

	FloatRect camRect = camera.getViewport();

	///Program Running While loop///
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::W || event.key.code == Keyboard::Up)
				{
					mUp = true;
					idleUp, idleDown, idleLeft, idleRight = false;
				}if (event.key.code == Keyboard::A || event.key.code == Keyboard::Left)
				{
					mLeft = true;
					idleUp, idleDown, idleLeft, idleRight = false;
				}if (event.key.code == Keyboard::S || event.key.code == Keyboard::Down)
				{
					mDown = true;
					idleUp, idleDown, idleLeft, idleRight = false;
				}if (event.key.code == Keyboard::D || event.key.code == Keyboard::Right)
				{
					mRight = true;
					idleUp, idleDown, idleLeft, idleRight = false;
				}

				if (event.key.code == Keyboard::Escape)
				{
					window.close();
				}
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::W || event.key.code == Keyboard::Up)
				{
					mUp = false;
					idleUp = true;
				}if (event.key.code == Keyboard::A || event.key.code == Keyboard::Left)
				{
					mLeft = false;
					idleLeft = true;
				}if (event.key.code == Keyboard::S || event.key.code == Keyboard::Down)
				{
					mDown = false;
					idleDown = true;
				}if (event.key.code == Keyboard::D || event.key.code == Keyboard::Right)
				{
					mRight = false;
					idleRight = true;
				}
			}
		}

		Vector2f movement(0, 0);

		if (mUp)
		{
			movement.y -= 0.25f;
			idleTimer = clock.getElapsedTime().asSeconds();
			if (idleTimer > 0.5f)
			{
				if (frame < 1)
					frame++;
				else
					frame = 0;
				clock.restart();
			}
			texture = ghost.playerMove[0][frame];
		}
		else if (idleUp)
		{
			
			texture = ghost.playerIdle[0][frame];
		}

		if (mDown)
		{
			movement.y += 0.25f;
			idleTimer = clock.getElapsedTime().asSeconds();
			if (idleTimer > 0.5f)
			{
				if (frame < 1)
					frame++;
				else
					frame = 0;
				clock.restart();
			}
			texture = ghost.playerMove[1][frame];
		}
		else if (idleDown)
		{		
			idleTimer = clock.getElapsedTime().asSeconds();
			if (idleTimer > 0.5f)
			{
				if (frame < 2)
					frame++;
				else
					frame = 0;
				clock.restart();
			}
			texture = ghost.playerIdle[1][frame];
		}

		if (mLeft)
		{
			movement.x -= 0.25f;
			idleTimer = clock.getElapsedTime().asSeconds();
			if (idleTimer > 0.5f)
			{
				if (frame < 1)
					frame++;
				else
					frame = 0;
				clock.restart();
			}
			texture = ghost.playerMove[2][frame];
		}
		else if (idleLeft)
		{
			idleTimer = clock.getElapsedTime().asSeconds();
			if (idleTimer > 0.5f)
			{
				if (frame < 2)
					frame++;
				else
					frame = 0;
				clock.restart();
			}
			texture = ghost.playerIdle[2][frame];
		}

		if (mRight)
		{
			movement.x += 0.25f;
			idleTimer = clock.getElapsedTime().asSeconds();
			if (idleTimer > 0.5f)
			{
				if (frame < 1)
					frame++;
				else
					frame = 0;
				clock.restart();
			}
			texture = ghost.playerMove[3][frame];
		}
		else if (idleRight)
		{
			idleTimer = clock.getElapsedTime().asSeconds();
			if (idleTimer > 0.5f)
			{
				if (frame < 2)
					frame++;
				else
					frame = 0;
				clock.restart();
			}
			texture = ghost.playerIdle[3][frame];
		}

		playerSprite.setTexture(texture);

		playerSprite.move(movement);
		camera.move(movement);

		window.setView(camera);

		grassSprite.setTextureRect(IntRect(0, 0, screenSize[0], screenSize[1]));

		window.clear();

		window.draw(grassSprite);

		window.draw(log[0]);
		window.draw(log[1]);
		window.draw(log[2]);
		window.draw(log[3]);

		window.draw(playerSprite);

		window.display();
	}


	return 0;
}