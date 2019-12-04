#pragma once

const float GLOBAL_SCALE = 1.0;
const int FRAMELIMIT = 10;
const int FRAMES = 5;
const float BLOCK_SIZE = 50;
const int MAP_SIZE = 20;
const float SIZE = BLOCK_SIZE * MAP_SIZE;
const int DELAY = 3;
const int MONSTER_DELAY = 2 * DELAY;
const int INF = 1e9+7;
const int MUSIC_DURATION = 112*FRAMELIMIT;

enum{
	WALL,
	PLAYER,
	GROUND,
	COIN,
	MONSTER,
	END_BLOCK,
	BOX,
	FIRE,
	GATE,
	NUMBER_OF_BLOCKS
};

enum{
	STAY,
	UP,
	DOWN,
	LEFT,
	RIGHT
};