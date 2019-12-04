#pragma once
#include "Mapa.h"
#include "Stale.h"
#include "Gate.h"
#include "iostream"
#include "map"

class Player{
private:
	int x;
	int y;
	int nextMove;
	int coins;
	int fire;
public:
	Player();
	~Player();

	int getCoins();
	int getFire();
	void addCoin();
	void addFire();
	void spendCoins( int diff );
	void resetCoinsAndFire();
	void spendFire();
	void setPosition( int a , int b );
	void planToMove( int direction );
	void moving( int x , int y , int newX , int newY , Mapa & mapa , std::map< std::pair< int , int > , Gate >& map);
	void move( int frame , Mapa & mapa ,  std::map< std::pair< int , int > , Gate > & map);
	void updateDist( Mapa & mapa);
};