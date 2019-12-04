#include"Pasek.h"
#include"SFML/Graphics.hpp"
#include"string"
Pasek::Pasek(){
	if(!pasekTexture.loadFromFile("Textures/pasek.png") )
		exit(0);
	if(!frameTexture.loadFromFile("Textures/frame.png") )
		exit(0);
	coinTexture.resize(FRAMES);
	fireTexture.resize(FRAMES);
	for( int i = 0 ; i < FRAMES ; i++){
		std::string pom = std::to_string(i);
		if(!coinTexture[i].loadFromFile("Textures/coin" + pom + ".png") )
			exit(0);
		if(!fireTexture[i].loadFromFile("Textures/fire" + pom + ".png") ) 
			exit(0);
	}
	if(!restartTexture.loadFromFile("Textures/restart.png") ) 
		exit(0);
	if(!restartHighTexture.loadFromFile("Textures/restartHigh.png") ) 
		exit(0);
	restartSprite.setTexture(restartTexture);
	restartSprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	restartSprite.setPosition(GLOBAL_SCALE*1050,GLOBAL_SCALE*800);
	restartHighSprite.setTexture(restartHighTexture);
	restartHighSprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	restartHighSprite.setPosition(GLOBAL_SCALE*1050,GLOBAL_SCALE*800);
	restartHighSprite.setScale(sf::Vector2f(GLOBAL_SCALE*2,GLOBAL_SCALE*2) );
	restartSprite.setScale(sf::Vector2f(GLOBAL_SCALE*2,GLOBAL_SCALE*2) );
	pasekSprite.setTexture(pasekTexture);
	pasekSprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	pasekSprite.setPosition(sf::Vector2f(GLOBAL_SCALE*1000,GLOBAL_SCALE*0) );
	frameSprite.setTexture(frameTexture);
	frameSprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	coinSprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	coinSprite.setPosition(sf::Vector2f(GLOBAL_SCALE*1075,GLOBAL_SCALE*125));
	fireSprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	fireSprite.setPosition(sf::Vector2f(GLOBAL_SCALE*1075,GLOBAL_SCALE*425));

	font.loadFromFile("Fonts/Welbut__.ttf");
	howManyFire.setFont(font);
	howManyFire.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	howManyCoins.setFont(font);
	howManyCoins.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	howManyCoins.setColor(sf::Color::Yellow);
	howManyFire.setColor(sf::Color::Red);
	howManyCoins.setPosition(sf::Vector2f( GLOBAL_SCALE*1260 , GLOBAL_SCALE*110 ));
	howManyFire.setPosition(sf::Vector2f(GLOBAL_SCALE*1260 , GLOBAL_SCALE*410));
	info.setFont(font);
	info.setPosition(sf::Vector2f(GLOBAL_SCALE*310 , GLOBAL_SCALE*10));
	info.setScale(sf::Vector2f(GLOBAL_SCALE*0.7,GLOBAL_SCALE*0.7));
	info.setColor(sf::Color::Blue);
	info.setString("*** Press Escape to exit game ***");

	howManyFire.setScale(sf::Vector2f(GLOBAL_SCALE*5,GLOBAL_SCALE*5));
	howManyCoins.setScale(sf::Vector2f(GLOBAL_SCALE*5,GLOBAL_SCALE*5));
}
Pasek::~Pasek(){}
