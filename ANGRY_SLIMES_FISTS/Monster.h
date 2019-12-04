#pragma once
#include"Player.h"
class Monster{
private:
	bool alive;
	int nextMove;
	int x;
	int y;
public:
	Monster();
	~Monster();
	void disolve(Mapa & mapa);
	void setDead();
	void setPosition( int xPoz , int yPoz );
	int search( Mapa & mapa );
	int moving( int newX , int newY , Mapa & mapa , Player & player);
	int move( int frame , Mapa & mapa , Player & player);
	bool isAlive();
};