#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>
#include "Player.h"

void makeRect(sf::IntRect rect[], int frameCount, int x, int y){
	for (int i = 0; i < frameCount; i++){
		rect[i] = sf::IntRect(x * i, 0, x, y);
	}
}
void Player::animatePlayer(int startFrame, int finishFrame, float interval){

	float time;
	time = PlayerFram.getElapsedTime().asSeconds();
	if (time > interval)
	{ 
		if (playerCount < startFrame)
			playerCount = startFrame;

		
			playerCount++;
		player.setTextureRect(playerRect[playerCount]);
	PlayerFram.restart();
		if (playerCount >= finishFrame)
			playerCount = startFrame;
		
	}
	
}

Player::Player()
{
	makeRect(playerRect, 52, 18, 18);
	playerHealth = 2;
	
	playerTexture.loadFromFile("C:/Users/student/Desktop/Alexander Z/SomeStuff/SFML Template1/Debug/Assets/Textures/Player.png");
	player.setTexture(playerTexture);
	player.setOrigin(8.5, 8.5);
	player.setScale(3, 3);
	player.setPosition(480, 270);
	player.setTextureRect(playerRect[0]);
}
Player::Player(int animation)
{
	
}
Player::Player(sf::Texture texture){
	playerTexture = texture;
	

}