#include"Engine.h"
#include"Stale.h"
#include"Mapa.h"
#include"Player.h"
#include"Monster.h"
#include"SFML/Graphics/Rect.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"iostream"
#include"string"

Engine::Engine( char * title , int pos_x , int pos_y , int width , int height){
        running = 1;
        starting = 1;
        sprite.setScale(GLOBAL_SCALE,GLOBAL_SCALE);
        font.loadFromFile("Fonts/Welbut__.ttf");
        text.setFont(font);
        text.setScale(GLOBAL_SCALE*1.2 , GLOBAL_SCALE*1.2);
        text.setColor( sf::Color::Magenta );
        app.create(sf::VideoMode( width, height), title);
        app.setPosition(sf::Vector2i( pos_x , pos_y ));
        app.setFramerateLimit(FRAMELIMIT);
        if(!music.openFromFile("Music/mainTheme.ogg"))
            exit(1);
        music.setVolume(60);
}
Engine::~Engine(){}

void Engine::playMusic( int frame ){
    if( !(frame%MUSIC_DURATION) )
        music.play();
}

void Engine::startingEvents(){
    while( app.pollEvent(event) ){
        switch(event.type){
            case sf::Event::Closed:
                starting = 0;
                running = 0;
                quit();
                break;
            case sf::Event::KeyPressed:
                switch( event.key.code ){
                    case sf::Keyboard::Escape:
                        starting = 0;
                        running = 0;
                        quit();
                        break;
                    case sf::Keyboard::Return:
                        starting = 0;
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                if( startingScreen.button.getGlobalBounds().contains( sf::Mouse::getPosition(app).x , sf::Mouse::getPosition(app).y ))
                    starting = 0;
                break;
            default:
                break;
        }
    }
}

void Engine::events( int frame ){
    while (app.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                quit();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code){
                    case sf::Keyboard::Up:
                        player.planToMove(UP);
                        break;
                    case sf::Keyboard::Down:
                        player.planToMove(DOWN);
                        break;
                    case sf::Keyboard::Left:
                        player.planToMove(LEFT);
                        break;
                    case sf::Keyboard::Right:
                        player.planToMove(RIGHT);
                        break;
                    //case sf::Keyboard::R:
                    //    mapa.restartLevel();
                    //    break;
                    case sf::Keyboard::Escape:
                        quit();
                        break;
                    default:
                        break; 
                }
            break;
            case sf::Event::MouseButtonPressed:
                if( pasek.restartSprite.getGlobalBounds().contains( sf::Mouse::getPosition(app).x , sf::Mouse::getPosition(app).y )){
                    mapa.restartLevel();
                }
                break;
            default:
                break;
        }
    }
    player.move( frame , mapa , gates );
    for( auto &monster: monsters )
        if( monster.isAlive() )
            monster.move( frame , mapa , player);
}
void Engine::update(){
    if( mapa.needToUpload() ){
        player.resetCoinsAndFire();
        mapa.loadLevel( gates );
        lookForNewPlayer();
        lookForNewMonsters();
    }
}

void Engine::lookForNewPlayer(){
    for( int i = 0 ; i < MAP_SIZE ; i++ )
        for( int j = 0 ; j < MAP_SIZE ; j++ )
            if( mapa.getBlockValue(i,j) == PLAYER ){
                player.setPosition(i,j);
                return;
            }
}

void Engine::eraseMonsters(){
    monsters.resize(0);
}

void Engine::lookForNewMonsters(){
    eraseMonsters();
    for( int i = 0 ; i < MAP_SIZE ; i++ )
        for( int j = 0 ; j < MAP_SIZE ; j++ )
            if( mapa.getBlockValue(i,j) == MONSTER ){
                Monster monster;
                monster.setPosition(i,j);
                monsters.push_back(monster);
            }
}

void Engine::displayStartingScreen(){
    app.clear();
    app.draw( startingScreen.sprite );
    if( startingScreen.button.getGlobalBounds().contains( sf::Mouse::getPosition(app).x , sf::Mouse::getPosition(app).y ) )
        app.draw( startingScreen.highlightedButton );
    else   
        app.draw( startingScreen.button );
    app.display();
}

void Engine::drawGates(){
    for( auto gate: gates )
        if( gate.second.isActive() ){
            text.setPosition( sf::Vector2f( GLOBAL_SCALE*(gate.first.second*BLOCK_SIZE + 12), GLOBAL_SCALE*(gate.first.first*BLOCK_SIZE + 5) ) );
            text.setString(std::to_string(gate.second.getDemand()));
            app.draw(text);
        }
}

void Engine::drawPasek( int frame ){
    app.draw(pasek.pasekSprite);
    pasek.frameSprite.setPosition( GLOBAL_SCALE*1050, GLOBAL_SCALE*100 );
    app.draw(pasek.frameSprite);
    pasek.frameSprite.setPosition( GLOBAL_SCALE*1050, GLOBAL_SCALE*400 );
    app.draw(pasek.frameSprite);
    pasek.coinSprite.setTexture(pasek.coinTexture[frame%FRAMES]);
    pasek.fireSprite.setTexture(pasek.fireTexture[frame%FRAMES]);
    pasek.coinSprite.setScale(GLOBAL_SCALE*3,GLOBAL_SCALE*3);
    pasek.fireSprite.setScale(GLOBAL_SCALE*3,GLOBAL_SCALE*3);
    app.draw(pasek.coinSprite);
    app.draw(pasek.fireSprite);
    if( pasek.restartSprite.getGlobalBounds().contains( sf::Mouse::getPosition(app).x , sf::Mouse::getPosition(app).y ) )
        app.draw(pasek.restartHighSprite);
    else
        app.draw(pasek.restartSprite);
    std::string temp;
    temp = std::to_string( player.getCoins() );
    pasek.howManyCoins.setString(temp);
    app.draw(pasek.howManyCoins);
    temp = std::to_string( player.getFire() );
    pasek.howManyFire.setString(temp);
    app.draw(pasek.howManyFire);
    app.draw(pasek.info);
}

void Engine::draw( int frame){
    app.clear();
    for( int i = 0 ; i < MAP_SIZE ; ++i )
        for( int j = 0 ; j < MAP_SIZE ; ++j ){
            sprite.setPosition(sf::Vector2f(GLOBAL_SCALE * BLOCK_SIZE*i, GLOBAL_SCALE * BLOCK_SIZE*j));
            sprite.setTexture(texture_pack.textures[mapa.getBlockValue(j,i)][frame]);
            app.draw(sprite);
        }
    drawGates( );
    drawPasek( frame );
    app.display();
}

void Engine::manageTextures(){
    texture_pack.setBlocksNames();
    texture_pack.setTextureSizes(FRAMES);
    texture_pack.loadTextures(FRAMES);
}

bool Engine::isStarting(){
    return starting;
}

bool Engine::isRunning(){
    return running;
}

void Engine::quit(){
    running = 0;
}
