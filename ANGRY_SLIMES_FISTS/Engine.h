#pragma once
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Audio.hpp"
#include"Stale.h"
#include"Texture_Pack.h"
#include"Mapa.h"
#include"Player.h"
#include"Monster.h"
#include"Pasek.h"
#include"StartingScreen.h"
#include"Gate.h"
#include"map"

class Engine{
private:
	bool starting;
    bool running;
    sf::RenderWindow app;
    sf::Event event;
    sf::Sprite sprite;
    Texture_Pack texture_pack;
    sf::Font font;
    sf::Text text;
    sf::Music music;
    Mapa mapa;
    Pasek pasek;
    Player player;
    StartingScreen startingScreen;
    std::vector< Monster > monsters;
    std::map< std::pair< int , int > , Gate > gates;
public:
	Engine( char * title , int pos_x , int pos_y , int width , int height);
	~Engine();
	
	void playMusic( int frame );
	void startingEvents();
	void lookForNewPlayer();
	void eraseMonsters();
	void eraseBoxes();
	void lookForNewMonsters();
	void lookForBoxes();
	void events( int frame );
	void input();
	void update();
	void displayStartingScreen();
	void drawGates();
	void drawPasek( int frame);
	void draw( int frame );
	bool isStarting();
	bool isRunning();
	void quit();
	void manageTextures();
};