#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>


class Blocks{

public:
	sf::Sprite block[100];
	sf::Texture blockTexture[10];
	sf::IntRect blockRect;


	Blocks();
	
	void loadLevel(int level);


};