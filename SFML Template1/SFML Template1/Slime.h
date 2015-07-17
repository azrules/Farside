#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>


class Slime{

public:
	sf::Sprite slime[100];
	sf::Texture slimeTexture;
	sf::Clock slimeFram[100];
	sf::IntRect slimeRect[2];
	int slimeCount = 0;
	int slimeHealth;
	bool slimeToogle = false;
	Slime();
	
	void makeSlime(int slimeNo, int x, int y, int usedSlimes);
	void animateSlimes();
	void killSlime(int slimeNo);

};