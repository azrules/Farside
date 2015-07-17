#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>


class Player{

public:
	sf::Sprite player;
	sf::Texture playerTexture;	
	sf::Clock PlayerFram;
	sf::IntRect playerRect[100];
	int playerCount = 0;
	int playerHealth;
	
	Player();
	Player(int animation);
	Player(sf::Texture texture);

	void animatePlayer(int startFrame, int finishFrame, float interval);
	void playerReset();
};