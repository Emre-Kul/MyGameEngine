#include "Button.h"
Button::Button(){
	text = "";
	gotFocus = false;
	buttonPressed = false;
}
void Button::setPosition(SHP2Rectangle &pos){
	position = pos;
	buttonSprite.generateMesh(position);//position changed
}
void Button::setButton(Sprite &backgroundSprite,SHP2Rectangle &pos,string s_text){
	position = pos;
	buttonSprite = backgroundSprite;
	text = s_text;
	
	buttonSprite.generateMesh(position);//position changed
	
}