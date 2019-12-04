#include"SFML/Graphics.hpp"
#include"Texture_Pack.h"
#include"iostream"
#include"Stale.h"
Texture_Pack::Texture_Pack(){
	textures.resize(NUMBER_OF_BLOCKS);
}
Texture_Pack::~Texture_Pack(){}

void Texture_Pack::setBlocksNames(){
	blocks_names.resize(NUMBER_OF_BLOCKS);
	blocks_names[0] = "wall";
	blocks_names[1] = "player";
	blocks_names[2] = "ground";
	blocks_names[3] = "coin";
	blocks_names[4] = "monster";
	blocks_names[5] = "end_block";
	blocks_names[6] = "box";
	blocks_names[7] = "fire";
	blocks_names[8] = "gate";
}

void Texture_Pack::setTextureSizes( int size ){
	for( auto &u: textures )
		u.resize(size);
}

void Texture_Pack::loadTextures( int size ){
	for( int i = 0 ; i < NUMBER_OF_BLOCKS ; i++ ){
		std::string num = "0";
		for( int j = 0 ; j < size ; j++ ){
			if(!textures[i][j].loadFromFile("Textures/" + blocks_names[i] + num + ".png")){
				std::cout << "nie załadowano textury " << std::endl;
				exit(1);
			}
			num[0]++;
		}
	}
}
