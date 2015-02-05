#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Button.h"
#include "../General/TextManager.h"

class Menu{
	std::vector <Button> buttons;
	
	SHP2Rectangle position;
public:
	TextManager textManager;	
	void addButton(Vector2 &size,Vector2 &distance,string text,Sprite &buttonBackground);
	void drawMenu();
	void cleanMenu();
					//inlines
	inline void setMenuPosition(SHP2Rectangle &pos){position = pos;}

	

};

#endif