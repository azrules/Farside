#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>


class Powerup{

public:
	sf::Sprite redPowerUp[100];
	sf::Sprite yellowPowerUp[100];
	sf::Sprite bluePowerUp[100];
	sf::Texture powerupTexture[3];
	sf::Clock powerupClock;
	sf::IntRect powerupRect[12];
	bool powerupOff[100];
	int count;
	Powerup();
	void powerupMake(int powerupNum, int powerup, int posX, int posY);
	void animatePowerup(int startFrame, int finishFrame, float interval, int powerupNo, int poweruptype);
	void getPowerup(int powerupNo);
};