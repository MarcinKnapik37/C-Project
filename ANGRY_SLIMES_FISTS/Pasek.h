#pragma once
#include"SFML/Graphics.hpp"
#include"vector"
#include"Stale.h"
class Pasek{
private:
public:
	sf::Font font;
	sf::Text howManyCoins;
	sf::Text howManyFire;
	sf::Text info;
	std::vector< sf::Texture > fireTexture , coinTexture;
	sf::Texture pasekTexture , frameTexture , restartTexture , restartHighTexture;
	sf::Sprite pasekSprite , frameSprite , fireSprite , coinSprite , restartSprite , restartHighSprite ;
 	Pasek();
 	~Pasek();
};