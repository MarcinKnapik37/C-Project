#include "Mapa.h"
#include "Player.h"
#include "Stale.h"
#include "iostream"
#include "queue"
Player::Player(){
	coins = 0;
	fire = 0;
	nextMove = STAY;
}
Player::~Player(){}

int Player::getFire(){
	return fire;
}

int Player::getCoins(){
	return coins;
}

void Player::updateDist(Mapa & mapa){
	std::queue< std::pair < int , int > > Q;
	for( int i = 0 ; i < MAP_SIZE ; i++ )
		for( int j = 0 ; j < MAP_SIZE ;j++)
			mapa.changeDist( i , j , INF);
	mapa.changeDist( x , y , 0);
	Q.push({x,y});
	int dist = 1;
	while( Q.size() ){
		int sizeQ = Q.size();
		for( int i = 0 ; i < sizeQ ; i++ ){
			std::pair< int , int > current = Q.front();
			Q.pop();
			int value = mapa.getBlockValue( current.first + 1 , current.second );
			if( (value == GROUND || value == MONSTER) && mapa.getDist( current.first + 1, current.second ) == INF ){
				Q.push( { current.first + 1, current.second } );
				mapa.changeDist( current.first + 1, current.second , dist);
			}
			value = mapa.getBlockValue( current.first - 1 , current.second );
			if( (value == GROUND || value == MONSTER) && mapa.getDist( current.first - 1, current.second ) == INF ){
				Q.push( { current.first - 1 , current.second } );
				mapa.changeDist( current.first - 1 , current.second , dist);
			}
			value = mapa.getBlockValue( current.first , current.second + 1);
			if( (value == GROUND || value == MONSTER) && mapa.getDist( current.first , current.second + 1 ) == INF ){
				Q.push( { current.first , current.second + 1 } );
				mapa.changeDist( current.first , current.second + 1, dist);
			}
			value = mapa.getBlockValue( current.first , current.second - 1 );
			if( (value == GROUND || value == MONSTER) && mapa.getDist( current.first , current.second - 1) == INF ){
				Q.push( { current.first , current.second - 1} );
				mapa.changeDist( current.first , current.second - 1, dist);
			}			
		}
		dist++;
	}
}

void Player::setPosition( int a , int b ){
	x = a;
	y = b;
}

void Player::planToMove( int direction ){
	nextMove = direction;
}

void Player::addCoin(){
	coins++;
}

void Player::addFire(){
	fire++;
}

void Player::spendCoins( int diff ){
	coins -= diff;
}

void Player::resetCoinsAndFire(){
	coins = 0;
	fire = 0;
}
void Player::spendFire(){
	fire--;
}

void Player::moving( int x , int y , int newX , int newY , Mapa & mapa , std::map< std::pair< int , int > , Gate >& map){
	if( mapa.getBlockValue(newX,newY) == BOX ){
		int xDiff = newX - x;
		int yDiff = newY - y;
		int newerX = newX + xDiff;
		int newerY = newY + yDiff;
		if( mapa.getBlockValue(newerX, newerY) == GROUND){
			mapa.sounds.playBoxSound();
			mapa.move(newX,newY,newerX,newerY);
			mapa.move(x , y , newX , newY);
			setPosition( newX , newY);
		}
	}
	else if( mapa.getBlockValue( newX , newY ) == GATE ){
		int demand = map[{newX,newY}].getDemand();
		if( demand <= getCoins() ){
			mapa.sounds.playGateSound();
			map[{newX,newY}].setUnactive();
			spendCoins(demand);
			mapa.move( x , y , newX , newY );
			setPosition(newX ,newY);
		}
	}
	else if( mapa.getBlockValue(newX,newY) == MONSTER ){
		/*int fireballs = getFire();
		if( !fireballs ){
			mapa.restartLevel();
		}
		else{
			spendFire();

			mapa.move( x , y , newX , newY );
			setPosition(newX ,newY);
		}*/
	}
	else if( mapa.getBlockValue(newX,newY) != WALL ){
		if( mapa.checkForTheEnd( newX , newY ) ){
			mapa.sounds.playEndSound();
			mapa.finishLevel();
		}
		if( mapa.checkForTheCoin( newX , newY ) ){
			mapa.sounds.playCoinSound();
			addCoin();
		}
		if( mapa.checkForTheFire( newX , newY ) ){
			mapa.sounds.playFireSound();
			addFire();
		}
		mapa.move( x , y , newX , newY );
		setPosition(newX ,newY);
	} 
}

void Player::move( int frame , Mapa &mapa , std::map< std::pair< int , int > , Gate >& map ){
	if( frame % DELAY )
		return;
	int newX = x , newY = y;
	switch( nextMove ){
		case UP:
			newX = x-1 , newY = y;
			break;
		case DOWN:
			newX = x+1 , newY = y;
			break;
		case LEFT:
			newX = x , newY = y-1;
			break;
		case RIGHT:
			newX = x , newY = y+1;
			break;
		default:
			break;
	}
	if( x != newX || y != newY )
		moving( x , y , newX , newY , mapa , map);
	nextMove = STAY;
	updateDist( mapa );
}