#include "MouseController.h"
MouseController::MouseController(){
	mouseStat[0] = MOUSE_EVENT_BUTTON_FREE;
	mouseStat[1] = MOUSE_EVENT_BUTTON_FREE;
	mouseStat[2] = MOUSE_EVENT_BUTTON_FREE;
}
void MouseController::setMouse(MouseButtons mousebutton,MouseEvent mouseevent){
	mouseStat[mousebutton] = mouseevent;
}
void MouseController::freeMouse(){
	for(unsigned int i = 0;i < 3;i++) mouseStat[i] = MOUSE_EVENT_BUTTON_FREE;
}