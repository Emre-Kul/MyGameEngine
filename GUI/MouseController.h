#ifndef MOUSECONTROLLER_H
#define MOUSECONTROLLER_H

#include "../Math/Vectors.h"

enum MouseButtons
{
	MOUSE_RIGHT_CLICK,
	MOUSE_LEFT_CLICK,
	MOUSE_MID_CLICK
};
enum MouseEvent
{
	MOUSE_EVENT_BUTTON_DOWN,
	MOUSE_EVENT_BUTTON_UP,
	MOUSE_EVENT_BUTTON_FREE
};
class MouseController{
		int mouseStat[3];
		Vector2 coord;
	public:
		MouseController();
		void freeMouse();
		void setMouse(MouseButtons mousebutton,MouseEvent mouseevent);
		
		void setMouseCoord(Vector2	&vec){coord = vec;}
		int getMouse(MouseButtons ms){return mouseStat[ms];}
		Vector2& getMouseCoord(){return coord;}
};

#endif