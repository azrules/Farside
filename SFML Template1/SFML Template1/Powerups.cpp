#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>
#include "Powerup.h"
#include "Player.h"
using namespace std;
void makeRectPowa(sf::IntRect rect[], int frameCount, int x, int y)
{
	for (int i = 0; i < frameCount; i++){
		rect[i] = sf::IntRect(x * i, 0, x, y);
	}
}
void Powerup::animatePowerup(int startFrame, int finishFrame, float interval,int powerupNo,int poweruptype){

	float time;
	time = powerupClock[powerupNo].getElapsedTime().asSeconds();
	
	if (time > interval)
	{
		if (count < startFrame)
			count = startFrame;


		count++;
		if (poweruptype == 0){
			bluePowerUp[powerupNo].setTextureRect(powerupRect[count]);
			//cout << "WEED2.0";
			
		}
		if (poweruptype == 1)
			redPowerUp[powerupNo].setTextureRect(powerupRect[count]);
		if (poweruptype == 2)
			yellowPowerUp[powerupNo].setTextureRect(powerupRect[count]);
		powerupClock[powerupNo].restart();
		if (count >= finishFrame)
			count = startFrame;

	}

}

Powerup::Powerup()
{
	makeRectPowa(powerupRect, 12, 10, 10);
	powerupTexture[0].loadFromFile("C:/Users/student/Desktop/Alexander Z/SomeStuff/SFML Template1/Debug/Assets/Textures/bpower.png");
	powerupTexture[1].loadFromFile("C:/Users/student/Desktop/Alexander Z/SomeStuff/SFML Template1/Debug/Assets/Textures/rpower.png");
	powerupTexture[2].loadFromFile("C:/Users/student/Desktop/Alexander Z/SomeStuff/SFML Template1/Debug/Assets/Textures/ypower.png");
	for (int i = 0; i < 100; i++){
		bluePowerUp[i].setTexture(powerupTexture[0]);
		bluePowerUp[i].setTextureRect(powerupRect[0]);
		redPowerUp[i].setTexture(powerupTexture[1]);
		yellowPowerUp[i].setTexture(powerupTexture[2]);
	}
	for (int i = 0; i < 100; i++){
		powerupOff[i] = false;
	}
}

void Powerup::powerupMake(int powerupNum, int powerup, int posX, int posY){
	if (powerup == 0){

		if (powerupOff[powerupNum] == false)
		{
			bluePowerUp[powerupNum].setOrigin(5, 5);
			bluePowerUp[powerupNum].setScale(5, 5);
			bluePowerUp[powerupNum].setPosition(posX, posY);
		}
		else
		{

			bluePowerUp[powerupNum].setPosition(-9000, -9000);

		}
	}
	if (powerup == 1)
	{


		if (powerupOffr[powerupNum] == false)
		{
			redPowerUp[powerupNum].setOrigin(5, 5);
			redPowerUp[powerupNum].setScale(5, 5);
			redPowerUp[powerupNum].setPosition(posX, posY);
		}
		else
		{

			redPowerUp[powerupNum].setPosition(-9000, -9000);

		}
	}
	if (powerup == 2)
	{


		if (powerupOff[powerupNum] == false)
		{
			redPowerUp[powerupNum].setOrigin(5, 5);
			redPowerUp[powerupNum].setScale(5, 5);
			redPowerUp[powerupNum].setPosition(posX, posY);
		}
		else
		{

			redPowerUp[powerupNum].setPosition(-9000, -9000);

		}
	}
}