#include"Sounds.h"
#include"iostream"
Sounds::Sounds(){
	if(!coinBuffer.loadFromFile("Music/coin.wav"))
		exit(1);
	if(!gateBuffer.loadFromFile("Music/key.wav"))
		exit(1);
	if(!fireBuffer.loadFromFile("Music/fire.wav"))
		exit(1);
	if(!deathBuffer.loadFromFile("Music/death.wav"))
		exit(1);
	if(!monsterBuffer.loadFromFile("Music/monster.wav"))
		exit(1);
	if(!endBuffer.loadFromFile("Music/end.wav") )
		exit(1);
	if(!boxBuffer.loadFromFile("Music/box.wav") )
		exit(1);
	coinSound.setBuffer(coinBuffer);
	monsterSound.setBuffer(monsterBuffer);
	deathSound.setBuffer(deathBuffer);
	gateSound.setBuffer(gateBuffer);
	fireSound.setBuffer(fireBuffer);
	endSound.setBuffer(endBuffer);
	boxSound.setBuffer(boxBuffer);
	coinSound.setVolume(30);
}
Sounds::~Sounds(){}

void Sounds::playMonsterSound(){
	monsterSound.play();
}

void Sounds::playDeathSound(){
	deathSound.play();
}

void Sounds::playCoinSound(){
	coinSound.play();
}

void Sounds::playGateSound(){
	gateSound.play();
}

void Sounds::playFireSound(){
	fireSound.play();
}

void Sounds::playEndSound(){
	endSound.play();
}
void Sounds::playBoxSound(){
	boxSound.play();
}