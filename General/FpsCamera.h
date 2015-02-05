#ifndef FPSCAMERA_H
#define FPSCANERA_H

#include "Camera.h"
#include "Screen.h"

#include "../GUI/MouseController.h"
#include "../GUI/KeyController.h"

class FpsCamera : public Camera{
	MouseController *mouseController;//game have mouse controller so it must be pointer	
	KeyController *keyController;
	Screen *screen;
	float sensity;
public:
	FpsCamera();
	void updateCam();
	void setFpsCamera(Screen &scr,MouseController &mouse,KeyController &key);
						//inlines
	inline void setMouse(MouseController &mouseCont){mouseController = &mouseCont;}
	inline void setKey(KeyController &keyCont){keyController = &keyCont;}
	inline void setScreen(Screen &scr){screen = &scr;}
	inline void setSensity(float sens){sensity = sens;}

};

#endif