#pragma once
#include"SFML/Graphics.hpp"
class StartingScreen{
private:
public:
	sf::Texture screen , start , highlightedStart;
	sf::Sprite sprite , button , highlightedButton;
	StartingScreen();
	~StartingScreen();

	void display();
};