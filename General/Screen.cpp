#include "Screen.h"
Screen::Screen(){
	SCR_HEIGHT = 0;
	SCR_WIDTH = 0;
	ratio = 0.0f;
}
Screen::Screen(int witdh,int height){
	SCR_HEIGHT = height;
	SCR_WIDTH = witdh;
	ratio = (float)SCR_HEIGHT/(float)SCR_WIDTH;
}	
	 