#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Audio.hpp"
#include"iostream"
#include"vector"
#include"Mapa.h"
#include"Player.h"
#include"Stale.h"
#include"Engine.h"
#include"Texture_Pack.h"
#include"Monster.h"

int main( int argc , char ** argv ){
	Texture_Pack pack; 
	Engine game( "SLIME'S ANGRY FISTS", 0 , 0 , 1500 * GLOBAL_SCALE , 1000*GLOBAL_SCALE );
	game.manageTextures();
	long long frame = 0;
	while ( game.isRunning() ){
		while( game.isStarting() ){
			game.startingEvents();
			game.displayStartingScreen();
		}
		if( game.isRunning() ){
			game.playMusic( frame );
    		game.update();
    		game.events( frame );
			game.draw(frame++ % FRAMES);
		}
	}
	return 0;
}
