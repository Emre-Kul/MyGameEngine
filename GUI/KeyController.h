#ifndef KEYCONTROLLER_H
#define KEYCONTROLLER_H

const int GAME_KEY_UP = 0;
const int GAME_KEY_DOWN = 1;
const int GAME_KEY_RIGHT = 2;
const int GAME_KEY_LEFT = 3;
const int GAME_KEY_ESCAPE = 4;
const int GAME_KEY_FREE1 = 5;
const int GAME_KEY_FREE2 = 6;
const int GAME_KEY_FREE3 = 7;
const int GAME_KEY_FREE4 = 8;
const int GAME_KEY_FREE5 = 9;
const int GAME_KEY_FREE6 = 10;
const int GAME_KEY_FREE7 = 11;
const int GAME_KEY_FREE8 = 12;
const int GAME_KEY_FREE9 = 13;
const int GAME_KEY_FREE0 = 14;
	

const int GAME_KEY_STATUS_PRESSED = 0;
const int GAME_KEY_STATUS_PRESSING = 1;
const int GAME_KEY_STATUS_RELEASED = 2;
const int GAME_KEY_STATUS_FREE = 3;

struct KeyStatus{
	int KEY_STATUSS[15];
	KeyStatus();
};

class KeyController{
public:
	KeyStatus keyStats;

	void PressKey(int k);
	void ReleaseKey(int k);
	void FreeKey(int k);

	bool isKeyPressed(int k);
	bool isKeyPressing(int k);
	bool isKeyFree(int k);
	bool isKeyReleased(int k);


};

#endif