#pragma once
#include"SFML/Audio.hpp"
class Sounds{
private:
	sf::SoundBuffer coinBuffer;
	sf::Sound coinSound;
	sf::SoundBuffer gateBuffer;
	sf::Sound gateSound;
	sf::SoundBuffer fireBuffer;
	sf::Sound fireSound;
	sf::SoundBuffer deathBuffer;
	sf::Sound deathSound;
	sf::SoundBuffer monsterBuffer;
	sf::Sound monsterSound;
	sf::SoundBuffer endBuffer;
	sf::Sound endSound;
	sf::SoundBuffer boxBuffer;
	sf::Sound boxSound;

public:
	Sounds();
	~Sounds();
	void playMonsterSound();
	void playDeathSound();
	void playFireSound();
	void playGateSound();
	void playCoinSound();
	void playEndSound();
	void playBoxSound();
};