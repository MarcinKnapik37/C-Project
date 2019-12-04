#include"StartingScreen.h"
#include"Stale.h"

StartingScreen::StartingScreen(){
	screen.loadFromFile("Textures/starting_screen.png");
	start.loadFromFile("Textures/starting_button.png");
	highlightedStart.loadFromFile("Textures/highlighted_starting_button.png");
	sprite.setTexture(screen);
	sprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	sprite.setPosition(sf::Vector2f(GLOBAL_SCALE*0,GLOBAL_SCALE*0));
	button.setTexture(start);
	button.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	button.setPosition(sf::Vector2f(GLOBAL_SCALE*480,GLOBAL_SCALE*800));
	highlightedButton.setTexture( highlightedStart );
	highlightedButton.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
	highlightedButton.setPosition(sf::Vector2f( GLOBAL_SCALE*480 , GLOBAL_SCALE*800 ) );
}

StartingScreen::~StartingScreen(){

}