#ifndef BUTTON_H
#define BUTTON_H

#include "../General/Sprite.h"
#include "../Renderer/Mesh.h"

class Button{
	string text;
	Sprite buttonSprite;//there can be more than 1 
	SHP2Rectangle position;
	bool gotFocus,buttonPressed;

public:
	Button();
	void setPosition(SHP2Rectangle &pos);
	void setButton(Sprite &backgroundSprite,SHP2Rectangle &pos,string s_text);
					//inline//
	inline void setButtonSprite(Sprite &sprite){buttonSprite = sprite;}
	inline void setFocus(bool focus){gotFocus = focus;}
	inline void pressButton(){buttonPressed = true;}
	inline void setText(string txt){text = txt;}
	
	inline void DrawButton(){buttonSprite.draw();}
	inline string& getText(){return text;}
	inline bool isFocused(){return gotFocus;}
	inline bool isPressed(){return buttonPressed;}
	inline SHP2Rectangle& getPosition(){return position;}

};


#endif