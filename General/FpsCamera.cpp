#include "FpsCamera.h"
FpsCamera::FpsCamera(){
	sensity = 0.1f;
}
void FpsCamera::updateCam(){
	
}
void FpsCamera::setFpsCamera(Screen &scr,MouseController &mouse,KeyController &key){
	setScreen(scr);
	setMouse(mouse);
	setKey(key);
}