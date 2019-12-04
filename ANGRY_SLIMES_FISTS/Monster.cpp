#include"Mapa.h"
#include"Monster.h"
#include"Stale.h"
#include"algorithm"
#include"Player.h"
#include"vector"
#include"algorithm"

Monster::Monster(){
	alive = 1;
	nextMove = STAY;
}
Monster::~Monster(){}

void Monster::setPosition( int xPoz ,int yPoz ){
	x = xPoz;
	y = yPoz;
}

void Monster::setDead(){
	alive = 0;
}

int Monster::search( Mapa & mapa ){
	int val = std::min( std::min( std:: min( mapa.getDist(x-1,y) , mapa.getDist(x+1,y) ) , mapa.getDist(x,y+1) ) , mapa.getDist(x,y-1) );
	std::vector< int > directions;
	if( val == INF )
		return STAY;
	if( mapa.getDist(x-1,y) == val && mapa.getBlockValue(x-1,y) != MONSTER)
		directions.push_back(UP);
	if( mapa.getDist(x+1,y) == val && mapa.getBlockValue(x+1,y) != MONSTER)
		directions.push_back( DOWN );
	if( mapa.getDist(x,y-1) == val && mapa.getBlockValue(x,y-1) != MONSTER)
		directions.push_back( LEFT );
	if( mapa.getDist(x,y+1) == val && mapa.getBlockValue(x,y+1) != MONSTER)
		directions.push_back( RIGHT );
	std::random_shuffle(directions.begin() , directions.end() );
	if( !directions.size() ){
		return STAY;
	}
	return directions[0];
}

void Monster::disolve( Mapa & mapa ){
	mapa.setBlockValue( x , y , GROUND);
}

int Monster::moving( int newX , int newY , Mapa & mapa , Player & player ){
	if( mapa.getBlockValue( newX , newY ) == PLAYER ){
		if( player.getFire() ){
			mapa.sounds.playMonsterSound();
			player.spendFire();
			setDead();
			disolve(mapa);
			return 0;
		}
		else{
			mapa.sounds.playDeathSound();
			mapa.restartLevel();
		}
	}
	mapa.move( x , y , newX , newY );
	x = newX;
	y = newY;
	return 0;
}

int Monster::move( int frame , Mapa& mapa , Player& player){
	if( frame % MONSTER_DELAY )
		return 0;
	int direction = search( mapa );
	int newX, newY;
	switch( direction ){
		case UP:
			newX = x-1 , newY = y;
			return moving( newX , newY , mapa , player);
		case DOWN:
			newX = x+1 , newY = y;
			return moving( newX , newY , mapa , player);
		case LEFT:
			newX = x , newY = y-1;
			return moving( newX , newY , mapa , player);
		case RIGHT:
			newX = x , newY = y+1;
			return moving( newX , newY , mapa , player);
		default:
			return 0;
	}
}

bool Monster::isAlive(){
	return alive;
}