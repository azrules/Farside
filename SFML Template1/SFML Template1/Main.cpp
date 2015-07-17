#include <iostream>
#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>

#include "Player.h"
#include "Powerup.h"
#include "Blocks.h"
#include "Slime.h"
using namespace std;

void makeRectMain(sf::IntRect rect[], int frameCount, int x, int y){
	for (int i = 0; i < frameCount; i++){
		rect[i] = sf::IntRect(x * i, 0, x, y);
	}
}
//Creates Platforms



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
	bool levelLoad = true;
	int rFilter[3] = { 0, 0, 0 };
	Player player;
	Powerup powerup;
	Blocks blocks;
	Slime slime;
	sf::Texture playerTextur; 
	sf::Sprite back;
	sf::Texture backTexture;
	sf::Clock clak;
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
	bool death = false;
	int powerupNo = 0;
	bool hasPowerup = false;
	sf::Clock powerupTime;

	int level = 1;
	//cam
	sf::View camera(sf::FloatRect(50, 50, 150, 150));
	camera.setSize(480 * 2 * 0.9, 270 * 2 * 0.9);
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

			
			if (hasPowerup == false)
				player.animatePlayer(0, 11, 0.07);
			if (hasPowerup == true && powerupNo == 0)
				player.animatePlayer(25, 33, 0.07);
			if (hasPowerup == true && powerupNo == 1)
				player.animatePlayer(39, 41, 0.07);
			
		}
	/*	if (isSpaceDown){
			cout << "werk";
			jump = true;
			if (hasPowerup == false)
				player.animatePlayer(12, 15, 0.08);
				//if (12 <= player.playerCount && player.playerCount <15)
				//{
					viewMove.y -=800;
					cout << "I AM JUMPIMG"<< endl;
				//}
					if (player.playerCount >= 14 && hasPowerup == false){
					isSpaceDown = false;
					jump = false;
				}
					if (hasPowerup == true){
						jump = true;
						viewMove.y -= 8000;
						isSpaceDown = false;
						jump = false;
					}
		
				
				
		}
		*/
		player.player.setColor(sf::Color(255, 255, 255, 200));
		slime.animateSlimes();
		powerup.powerupMake(0, 0, 100, 500);
		powerup.powerupMake(1, 0, 700, 100);
	//	powerup.powerupMake(0, 1, 200, 100);
		powerup.animatePowerup(0, 11, 0.07, 1, 0);
		powerup.animatePowerup(0, 11, 0.07, 0, 0);
		if (isMovingUp&& !death)
			viewMove.y -= 400;
		if (isMovingDown&& !death)
			viewMove.y += 400;
		if (isMovingLeft&& !death){
			player.player.setScale(-3, 3);
			if (hasPowerup == false)
				viewMove.x -= 400;
			if (hasPowerup == true && powerupNo == 0)
				viewMove.x -= 800;
		}
		if (isMovingLeft && !jump&& !death){
			if (hasPowerup == false)
				player.animatePlayer(16, 18, 0.1);
			if (hasPowerup == true && powerupNo == 0)
				player.animatePlayer(34, 37, 0.1);
			player.player.setScale(-3, 3);
		}
		if (isMovingRight&& !death){
			if (hasPowerup == false)
				viewMove.x += 400;
			if (hasPowerup == true && powerupNo == 0)
				viewMove.x += 800;
		}

		if (isMovingRight && !jump && !death){
			if (hasPowerup == false)
				player.animatePlayer(16, 18, 0.1);
			if (hasPowerup == true && powerupNo == 0)
				player.animatePlayer(34, 37, 0.1);
			player.player.setScale(3, 3);
		}
		//START RENDERING
		
		window.clear();
		window.draw(back);
		for (int i = 0; i < 100; i++){
			if (!player.player.getGlobalBounds().intersects(blocks.block[i].getGlobalBounds()) && !jump){
				//viewMove.y += 1;

			}
			
			if (player.player.getGlobalBounds().intersects(blocks.block[i].getGlobalBounds()) && !death)
			{
			
				
				death = true;
				clak.restart();	
				break;
						}
			
			
		}
		if (death == true){
			player.animatePlayer(19, 24, 0.1);
			
			float time = clak.getElapsedTime().asSeconds();
			if (time > 0.4){
				player.playerReset();
				camera.setCenter(480, 270);
				death = false;
				clak.restart();
			}
		}
		if (level == 1){
			if (levelLoad){
				blocks.loadLevel(1);
				slime.makeSlime(0, 100, 685, 0);
				levelLoad = false;
			}
		}
		for (int i = 0; i < 100; i++){


			if (player.player.getGlobalBounds().intersects(powerup.bluePowerUp[i].getGlobalBounds()))
			{
				hasPowerup = true;
				powerupNo = 0;
				powerupTime.restart();
				powerup.powerupOff[i] = true;

			}
			if (player.player.getGlobalBounds().intersects(powerup.redPowerUp[i].getGlobalBounds()))
			{
				hasPowerup = true;
				powerupNo = 1;
				powerupTime.restart();
				powerup.powerupOffr[i] = true;


			}



		}
		for (int i = 0; i < 100; i++){


			if (player.player.getGlobalBounds().intersects(slime.slime[i].getGlobalBounds()))
			{
				if (!hasPowerup)
					death = true;
				if (hasPowerup)
					slime.killSlime(i);
			}
		}
		for (int i = 0; i < 100; i++){
			window.draw(blocks.block[i]);
		}
		for (int i = 0; i < 100; i++){
			window.draw(slime.slime[i]);
		}
		sf::Time changeInTime = clock.restart();
		
		player.player.move(viewMove * changeInTime.asSeconds());
		camera.move(viewMove* changeInTime.asSeconds());
		window.setView(camera);
		//end of event polling
		
		window.draw(player.player);
		window.draw(powerup.bluePowerUp[0]);
		window.draw(powerup.bluePowerUp[1]);
		window.draw(powerup.redPowerUp[0]);
		//window.draw(powerup.bluePowerUp[1]);
		window.display();
		




	}
}
