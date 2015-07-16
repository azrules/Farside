#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>
#include "Player.h"
#include "Powerup.h"
using namespace std;

void makeRectMain(sf::IntRect rect[], int frameCount, int x, int y){
	for (int i = 0; i < frameCount; i++){
		rect[i] = sf::IntRect(x * i, 0, x, y);
	}
}
//Creates Platforms
void platform(int possitionxg, int possitionyg, int lengthinblocks, sf::Sprite blocktype[], int blockuse, int variant, sf::IntRect textureRect[]){
	for (int i = 0; i < lengthinblocks; i++){

		blocktype[blockuse + i].setOrigin(16, 16);
		blocktype[blockuse + i].setScale(3, 3);
		blocktype[blockuse + i].setPosition(possitionxg*32 + i * 32 * 3, possitionyg*32);
		blocktype[blockuse + i].setTextureRect(textureRect[variant]);
	}
}


//Animation Function 
void animate(int startFrame, int finishFrame, sf::Sprite* thing, sf::Clock* clock, sf::IntRect rect[], int* countVar, int interval){
	float time;
	time = clock->getElapsedTime().asSeconds();
	if (time > interval)
	{
		if (*countVar < finishFrame){
			*countVar++;
		}
		if (*countVar < startFrame)
			*countVar = 0;
	}
	thing->setTextureRect(rect[*countVar]);
	clock->restart();
}

int main(){
	//Player
	Player player;
	Powerup powerup;
	sf::Texture playerTextur; 
	sf::Sprite back;
	sf::Texture backTexture;
	Player(); //Instantiates PLayer
	backTexture.loadFromFile("C:/Users/student/Desktop/Alexander Z/SomeStuff/SFML Template1/Debug/Assets/Textures/backg.png");
	back.setTexture(backTexture);
	//Window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
	//Input Booleans
	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;
	bool isSpaceDown = false;
	bool jump = false;
	int powerupNo = 0;
	bool hasPowerup = false;
	sf::Clock powerupTime;
	int level = 3;
	//cam
	sf::View camera(sf::FloatRect(50, 50, 150, 150));
	camera.setSize(480*2, 270*2);
	camera.setCenter(480, 270);
	//Global Clock
	sf::Clock clock;
	//Stuff that happens when the program is running.
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//Input events
			if (event.type == sf::Event::KeyPressed)
			{
				if (level > 0)
				{
					if (event.key.code == sf::Keyboard::W)
					{
						isMovingUp = true;
					}

					if (event.key.code == sf::Keyboard::Space)
					{
						isSpaceDown = true;
					}
					if (event.key.code == sf::Keyboard::Space && sf::Keyboard::A)
					{
						isSpaceDown = true;
					}
					if (event.key.code == sf::Keyboard::S)
					{
						isMovingDown = true;
					}
					if (event.key.code == sf::Keyboard::A)
					{
						isMovingLeft = true;
					}
					if (event.key.code == sf::Keyboard::D)
					{
						isMovingRight = true;
					}
				}
			}
			//Release Events
			if (event.type == sf::Event::KeyReleased)
			{
				if (level == 0)
				{
					if (event.key.code == sf::Keyboard::Return)
					{
						level++;
					}
				}
				if (level > 0)
				{
					if (event.key.code == sf::Keyboard::W)
					{
						isMovingUp = false;
					}
					if (event.key.code == sf::Keyboard::Space)
					{

					}
					if (event.key.code == sf::Keyboard::S)
					{
						isMovingDown = false;
					}
					if (event.key.code == sf::Keyboard::A)
					{
						isMovingLeft = false;
					}
					if (event.key.code == sf::Keyboard::D)
					{
						isMovingRight = false;
					}
				}
			}
		}
		sf::Vector2f viewMove(0, 0);
		if (!isMovingDown && !isMovingLeft && !isMovingRight && !isMovingUp && !jump)
		{

			player.animatePlayer(0, 11, 0.07);
			
		}
		if (isSpaceDown){
			jump = true;
				player.animatePlayer(12, 15, 0.08);
				if (12 < player.playerCount < 15)
				{
					viewMove.y += 0.1;
				}
				
					isSpaceDown = false;
					jump = false;
				

				
				
		}
		
		powerup.powerupMake(0, 0, 100, 100);
		powerup.animatePowerup(0, 11, 0.07, 0, 0);
		if (isMovingUp)
			viewMove.y -= 100;
		if (isMovingDown)
			viewMove.y += 100;
		if (isMovingLeft)
			viewMove.x -= 100;
		if (isMovingLeft){
			player.animatePlayer(16, 18, 0.1);
			player.player.setScale(-3, 3);
		}
		if (isMovingRight)
			viewMove.x += 100;
		if (isMovingRight){
			player.animatePlayer(16, 18, 0.1);
			player.player.setScale(3, 3);
		}
		for (int i = 0; i < 100; i++){

			if (player.player.getGlobalBounds().intersects(powerup.bluePowerUp[i].getGlobalBounds()))
			{
				hasPowerup = true;
				powerupNo = 0;
				powerupTime.restart();
			}

		}
		window.clear();
		sf::Time changeInTime = clock.restart();
		
		player.player.move(viewMove * changeInTime.asSeconds());
		camera.move(viewMove* changeInTime.asSeconds());
		window.setView(camera);
		//end of event polling
		window.draw(back);
		window.draw(player.player);
		window.draw(powerup.bluePowerUp[0]);
		window.draw(powerup.bluePowerUp[1]);
		window.display();
		




	}
}
