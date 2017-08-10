#include "main.h"
using namespace sf;
using namespace std;

int main()
{
	RectangleShape hpBarBottom; RectangleShape hpBarTop; RectangleShape blackG;
	///Window///
	int screenSize[2];

	screenSize[0] = 1699;
	screenSize[1] = 867;

	RenderWindow window(VideoMode(screenSize[0], screenSize[1]), "The RPG");
	window.setPosition(Vector2i(window.getPosition().x, window.getPosition().y - 50));

	///Variables///
	easy_enemyT.loadFromFile("Textures/ge.png");
	med_enemyT.loadFromFile("Textures/gm.png");
	hard_enemyT.loadFromFile("Textures/gh.png");
	impossible_enemyT.loadFromFile("Textures/gepic.png");

	gameOverFont.loadFromFile(/*resourcePath() + */"game_over.ttf"); //MAC ONLY
	///gOver.loadFromFile("game_over.ttf"); //windows only

	waveNumberText1.setFont(gameOverFont);
	waveNumberText1.setString("W A V E");
	waveNumberText1.setFillColor(Color(255, 255, 255));
	waveNumberText1.setOutlineColor(Color(0, 0, 0));
	waveNumberText1.setOutlineThickness(1);
	waveNumberText1.setOrigin(waveNumberText1.getLocalBounds().width / 2, waveNumberText1.getLocalBounds().height / 2);

	waveNumberText1.setScale(1, 1);
	waveNumberText1.setCharacterSize(90);

	wave.Wave::Wave(one_easy.diff);
	
	waveNumberText2.setFont(gameOverFont);
	
	waveNumberText2.setOutlineColor(Color(255, 255, 255));
	waveNumberText2.setFillColor(Color(0, 0, 0));
	waveNumberText2.setOutlineThickness(5);
	waveNumberText2.setOrigin(waveNumberText2.getLocalBounds().width / 2, waveNumberText2.getLocalBounds().height / 2);

	waveNumberText2.setScale(1, 1);
	waveNumberText2.setCharacterSize(90);

	
	hpBarBottom.setFillColor(Color::Red);
	hpBarBottom.setOutlineColor(Color::White);
	hpBarBottom.setOutlineThickness(3);

	
	hpBarTop.setFillColor(Color::Green);
	hpBarTop.setOutlineColor(Color::White);
	hpBarTop.setOutlineThickness(3);

	
	blackG.setSize(Vector2f(screenSize[0], screenSize[1]));
	blackG.setFillColor(Color::Black);
	blackG.setOutlineColor(Color::Black);

	border.setFillColor(Color::Transparent);
	border.setOutlineColor(Color::Black);
	border.setOutlineThickness(5);
	border.setSize(Vector2f(screenSize[0], screenSize[1]));
	border.setPosition(0, 0);

	gameOverText.setFont(gameOverFont);
	gameOverText.setString("GAME OVER!\nRestart?\n(Y / N)");
	gameOverText.setFillColor(Color(255, 255, 255));
	gameOverText.setOutlineColor(Color(0, 0, 0));
	gameOverText.setOutlineThickness(1);

	gameOverText.setScale(1, 1);
	gameOverText.setCharacterSize(100);
	gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2, gameOverText.getLocalBounds().height / 2);

	playerTexture.loadFromFile(/*resourcePath() + */"Textures/char1_frames.png");

	grassTexture.loadFromFile(/*resourcePath() + */"Textures/grass_tile.png");
	grassTexture.setRepeated(true);

	Clock clock;

	player.sprite.setTexture(playerTexture);
	gSprite.setTexture(grassTexture);

	gSprite.setPosition(Vector2f(-screenSize[0], -screenSize[1]));

	int frame = 0;

	player.sprite.setScale(1.25, 1.25);
	player.sprite.setOrigin(64, 64);
	player.sprite.setPosition(Vector2f(screenSize[0] / 2, screenSize[1] / 2));
	player.sprite.setTextureRect(playerDown[1]);

	View camera(Vector2f(50, 50), Vector2f(100, 100));
	camera.setSize(screenSize[0], screenSize[1]);

	hpBarTop.setSize(Vector2f(player.sprite.getTextureRect().width, 20)); hpBarBottom.setSize(Vector2f(player.sprite.getTextureRect().width, 20));

	while (window.isOpen())
	{
		while (player.alive) {
			waveNumberText2.setString(to_string(wave.diff));

			//cout << hp / maxhp << endl;
			hpBarTop.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y - 30);
			hpBarTop.setScale(player.hp / player.maxhp, 1);
			hpBarBottom.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y - 30);

			camera.setCenter(player.sprite.getPosition().x, player.sprite.getPosition().y);

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::W || event.key.code == Keyboard::Up)
					{
						player.movU = true;
						//faceR, faceL, faceU, faceD = false; //the four '= false;' statements here are safeguards
					}if (event.key.code == Keyboard::A || event.key.code == Keyboard::Left)
					{
						player.movL = true;
						//faceR, faceL, faceU, faceD = false;
					}if (event.key.code == Keyboard::S || event.key.code == Keyboard::Down)
					{
						player.movD = true;
						//faceR, faceL, faceU, faceD = false;
					}if (event.key.code == Keyboard::D || event.key.code == Keyboard::Right)
					{
						player.movR = true;
						//faceR, faceL, faceU, faceD = false;
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
						player.movU = false;
						player.sprite.setTextureRect(playerUp[1]);
						frame = 2;
						//faceU = true;
					}if (event.key.code == Keyboard::A || event.key.code == Keyboard::Left)
					{
						player.movL = false;
						player.sprite.setTextureRect(playerLeft[1]);
						frame = 2;
						//faceL = true;
					}if (event.key.code == Keyboard::S || event.key.code == Keyboard::Down)
					{
						player.movD = false;
						player.sprite.setTextureRect(playerDown[1]);
						frame = 2;
						//faceD = true;
					}if (event.key.code == Keyboard::D || event.key.code == Keyboard::Right)
					{
						player.movR = false;
						player.sprite.setTextureRect(playerRight[1]);
						frame = 2;
						//faceR = true;
					}
				}
			}

			if (player.hp <= 0) {
				player.alive = false;
			}

			sf::Vector2f viewCenter = camera.getCenter();
			sf::Vector2f halfExtents = camera.getSize() / 2.0f;
			sf::Vector2f translation = viewCenter - halfExtents;

			FloatRect camRect = camera.getViewport();

			camRect.left += static_cast<int>(translation.x);
			camRect.top += static_cast<int>(translation.y);

			waveNumberText1.setPosition(camRect.left + waveNumberText1.getLocalBounds().width / 3, camRect.top - waveNumberText1.getLocalBounds().height - 12);
			waveNumberText2.setPosition(camRect.left + waveNumberText2.getLocalBounds().width * 9, camRect.top - waveNumberText2.getLocalBounds().height);

			Vector2f movement(0, 0);
			timer = clock.getElapsedTime().asSeconds();

			if (player.movU)
			{
				movement.y -= 0.4f;
				if (timer > 0.1f)
				{
					if (frame < 3) {
						player.sprite.setTextureRect(playerUp[frame]); frame++;
					}
					else
						frame = 0;
					clock.restart();
				}

			}
			if (player.movD)
			{
				movement.y += 0.4f;
				if (timer > 0.1f)
				{
					if (frame < 3) {
						player.sprite.setTextureRect(playerDown[frame]); frame++;
					}
					else
						frame = 0;
					clock.restart();
				}
			}
			if (player.movL)
			{
				movement.x -= 0.4f;
				if (timer > 0.1f)
				{
					if (frame < 3) {
						player.sprite.setTextureRect(playerLeft[frame]); frame++;
					}
					else
						frame = 0;
					clock.restart();
				}
			}
			if (player.movR)
			{
				movement.x += 0.4f;
				if (timer > 0.1f)
				{
					if (frame < 3) {
						player.sprite.setTextureRect(playerRight[frame]); frame++;
					}
					else
						frame = 0;
					clock.restart();
				}
			}


			/*if (faceU) {


				//faceU = false;
			}
			else if (faceD) {


				//faceD = false;
			}
			else if (faceL) {


				//faceL = false;
			}
			else if (faceR) {


				//faceR = false;
			}*/

			player.sprite.move(movement);

			camera.move(movement);

			window.setView(camera);


			waveNumberText1.move(movement);
			waveNumberText2.move(movement);

			gSprite.setTextureRect(IntRect(-screenSize[0], -screenSize[1], screenSize[0]*3, screenSize[1]*3));

			window.clear();

			window.draw(gSprite);

			window.draw(border);

			window.draw(player.sprite);

			window.draw(hpBarBottom);
			window.draw(hpBarTop);

			window.draw(waveNumberText1);
			window.draw(waveNumberText2);
			
			window.draw(easy_enemyT); window.draw(med_enemyT); window.draw(hard_enemyT); window.draw(impossible_enemyT);

			window.display();

		}
		while (!player.alive) {
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Escape) {
						window.close();
					}
					if (event.key.code == Keyboard::Y) {
						player.alive = true;
					}
					else if (event.key.code == Keyboard::N) {
						window.close();
					}
				}
				window.draw(blackG);
				gameOverText.setPosition(camera.getCenter().x, camera.getCenter().y);
				window.draw(gameOverText);
				window.display();
			}
		}
		player.attacking = false;
		player.dmg = 3;
		player.maxhp = 10;
		player.hp = player.maxhp;
		if (player.movD) {
			player.sprite.setTextureRect(playerDown[1]);
			frame = 2;
		}
		else if (player.movU) {
			player.sprite.setTextureRect(playerUp[1]);
			frame = 2;
		}
		else if (player.movL) {
			player.sprite.setTextureRect(playerLeft[1]);
			frame = 2;
		}
		else if (player.movR) {
			player.sprite.setTextureRect(playerRight[1]);
			frame = 2;
		}
		player.movD = false;
		player.movU = false;
		player.movL = false;
		player.movR = false;
	}
	return 0;
}