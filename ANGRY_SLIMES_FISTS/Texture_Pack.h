#pragma once
#include"SFML/Graphics.hpp"
#include"vector"

class Texture_Pack{
private:
public:
	std::vector< std::vector< sf::Texture > > textures;
	std::vector< std::string > blocks_names;
	
	Texture_Pack();
	~Texture_Pack();
	void setBlocksNames();
	void setTextureSizes( int size );
	void loadTextures( int size );
};