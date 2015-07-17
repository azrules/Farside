#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>
#include "Blocks.h"
#include "Slime.h"
using namespace std;

void Slime::makeSlime(int slimeNo, int x, int y,int usedSlimes){

	slime[slimeNo].setOrigin(8, 16);
	slime[slimeNo].setScale(2, 2);
	slime[slimeNo].setPosition(x, y);


}
void platform(int possitionxg, int possitionyg, int lengthinblocks, sf::Sprite blocktype[], int blockuse){
	for (int i = 0; i < lengthinblocks; i++){

		blocktype[blockuse + i].setOrigin(16, 16);
		blocktype[blockuse + i].setScale(1, 1);
		blocktype[blockuse + i].setPosition(possitionxg + i * 32 , possitionyg);
	// 	cout << possitionxg * 32 + i * 32 * 3 << ", " << possitionyg * 32 << endl;
	}
}

void Blocks::loadLevel(int level)
{
	
	if (level = 1){

		platform(100, 700, 5, block, 0);
		platform(400, 700, 3, block, 5);
		platform(600, 700, 6, block, 8);
		platform(100, 300, 6, block, 14);
		platform(0, 0, 10, block, 20);
		//
		//cout << "Level 1 is UPPP BOISE";

	}


}

void Slime::animateSlimes()
{
	
	for (int i = 0; i < 100; i++){
		float time;
		time = slimeFram[i].getElapsedTime().asSeconds();
		if (time > 0.5)
		{
			if (!slimeToogle){
				slimeCount = 0;
				slimeToogle = true;
				//ime[i].setPosition(slime[i].getPosition.x, slime[i].getPosition.y + 60);
			}
			if (slimeToogle){
				slimeCount = 1;
				slimeToogle = false;
				//ime[i].setPosition(slime[i].getPosition.x, slime[i].getPosition.y - 60);
			}
			slime[i].setTextureRect(slimeRect[slimeCount]);
			slimeFram[i].restart();
		

		}
	}


} 
void Slime::killSlime(int slimeNo){
	slime[slimeNo].setPosition(9000, 9000);



}
Blocks::Blocks()
{
	blockRect = sf::IntRect(0, 0, 32, 32);
	blockTexture[0].loadFromFile("C:/Users/student/Desktop/Alexander Z/SomeStuff/SFML Template1/Debug/Assets/Textures/Block.png");
	for (int i = 0; i < 100; i++){
		block[i].setTexture(blockTexture[0]);
		block[i].setTextureRect(blockRect);
		
		//cout << "I should be making blocks but im a bitch" << endl;
	}

}
Slime::Slime(){

	slimeRect[0] = sf::IntRect(0, 0, 16, 16);
	slimeRect[1] = sf::IntRect(16, 0, 16, 16);
	slimeTexture.loadFromFile("C:/Users/student/Desktop/Alexander Z/SomeStuff/SFML Template1/Debug/Assets/Textures/Slime.png");
	for (int i = 0; i < 100; i++){
		slime[i].setTexture(slimeTexture);
		slime[i].setTextureRect(slimeRect[0]);
		cout << "slime";
		//cout << "I should be making blocks but im a bitch" << endl;
	}

}