#pragma once
#include "Stale.h"
#include "Gate.h"
#include"map"
#include"Sounds.h"

class Mapa{
private:
	int tab[MAP_SIZE][MAP_SIZE];
	int dist[MAP_SIZE][MAP_SIZE];
	int current_level;
	int finished_levels;
public:	
	Sounds sounds;
	Mapa();
	~Mapa();

	void setBlockValue( int x , int y , int val);
	void finishLevel();
	void restartLevel();
	int getDist( int x, int y);
	int getBlockValue( int x ,int y);
	void changeDist( int x, int y ,int val );
	bool checkForTheCoin( int newX , int newY );
	bool checkForTheEnd( int newX , int newY );
	bool checkForTheFire( int newX , int newY );
	bool tryToMovePlayer( int x ,int y , int newX , int newY);
	void move( int x , int y ,int newX , int newY );
	void loadLevel( std::map< std::pair< int , int > , Gate > & map);
	void displayTab();
	void displayDist();
	bool needToUpload();
};