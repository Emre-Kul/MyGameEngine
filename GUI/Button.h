#ifndef BUTTON_H
#define BUTTON_H

#include "Sprite.h"

class Button{
	//focusSprite,normalSprite ?
	Sprite buttonSprite;//there can be more than 1 
	bool GotFocus,PressButton;
public:
	Button();
	void DrawButton();

	//inline//
	void setButtonSprite(Sprite &sprite){buttonSprite = sprite;}
	void setFocus(bool focus){GotFocus = focus;}
	void pressButton(){PressButton = true;}
	bool isFocused(){return GotFocus;}
	bool isPressed(){return PressButton;}

};


#endif