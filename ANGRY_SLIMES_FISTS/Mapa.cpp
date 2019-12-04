#include "Mapa.h"
#include "Stale.h"
#include "Player.h"
#include "Texture_Pack.h"
#include "string"
#include "fstream"
#include "iostream"

Mapa::Mapa(){
	current_level = 0;
	finished_levels = 0;
}
Mapa::~Mapa(){}

void Mapa::setBlockValue( int x , int y , int val ){
	tab[x][y] = val;
}
void Mapa::restartLevel(){
	current_level--;
}
void Mapa::move( int x , int y , int newX , int newY ){
	tab[newX][newY] = tab[x][y];
	tab[x][y] = GROUND;
}

int Mapa::getBlockValue( int x , int y ){
	return tab[x][y];
}

int Mapa::getDist( int x , int y ){
	return dist[x][y];
}

void Mapa::changeDist( int x , int y , int val ){
	dist[x][y] = val;
}

bool Mapa::checkForTheCoin( int newX , int newY ){
	return tab[newX][newY] == COIN;
}

bool Mapa::checkForTheEnd( int newX , int newY ){
	return tab[newX][newY] == END_BLOCK;
}

bool Mapa::checkForTheFire( int newX , int newY ){
	return tab[newX][newY] == FIRE;
}

void Mapa::finishLevel(){
	finished_levels++;
}

void Mapa::loadLevel( std::map< std::pair< int , int > , Gate > & gates ){
	std::string num = "0";
	num[0] = num[0] + current_level++;
	std::fstream plik;
	plik.open("Levels/Level" + num , std::ios::in );
	if( !plik.good() ){
		std::cout << "nie mozna odczytac poziomu" << std::endl;
		plik.close();
		exit(1);
	}
	gates.clear();
	for( int i = 0 ; i < MAP_SIZE ; i++)
		for( int j = 0 ; j < MAP_SIZE ; j++ ){
			char znak;
			plik >> znak;
			if( znak >= '0' && znak <= '7' ){
				tab[i][j] = znak - '0';
			}
			else{
				gates[{i,j}].setDemand( znak - 'a' + 1);
				tab[i][j] = GATE;
			}
		}
	plik.close();
}

void Mapa::displayTab(){
    for( int i = 0 ; i < MAP_SIZE ; i++ ){
        for( int j = 0 ; j < MAP_SIZE ; j++ ){
            std::cout << tab[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Mapa::displayDist(){
	for( int i = 0 ; i < MAP_SIZE ; i++ ){
        for( int j = 0 ; j < MAP_SIZE ; j++ ){
            std::cout << dist[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
bool Mapa::needToUpload(){
	return current_level == finished_levels;
}
