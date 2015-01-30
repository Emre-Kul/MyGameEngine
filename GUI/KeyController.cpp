#include "KeyController.h"
KeyStatus::KeyStatus(){
for(int i = 0;i < 15;i++) 
	KEY_STATUSS[i] = GAME_KEY_STATUS_FREE;
}
void KeyController::PressKey(int k){
	keyStats.KEY_STATUSS[k] = GAME_KEY_STATUS_PRESSED;
}
void KeyController::ReleaseKey(int k){
	keyStats.KEY_STATUSS[k] = GAME_KEY_STATUS_RELEASED;
}
bool KeyController::isKeyPressed(int k){
	if(keyStats.KEY_STATUSS[k] == GAME_KEY_STATUS_PRESSED) return true;
	return false;
}
bool KeyController::isKeyPressing(int k){
	if(keyStats.KEY_STATUSS[k] == GAME_KEY_STATUS_PRESSING) return true;
	return false;
}
bool KeyController::isKeyFree(int k){
	if(keyStats.KEY_STATUSS[k] == GAME_KEY_STATUS_FREE) return true;
	return false;
}
bool KeyController::isKeyReleased(int k){
	if(keyStats.KEY_STATUSS[k] == GAME_KEY_STATUS_RELEASED) return true;
	return false;
}
void KeyController::FreeKey(int k){
	keyStats.KEY_STATUSS[k] = GAME_KEY_STATUS_FREE;
}