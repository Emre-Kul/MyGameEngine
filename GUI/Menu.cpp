#include "Menu.h"
void Menu::drawMenu(){
	for(int m = 0;m < buttons.size();m++)
		  buttons[m].DrawButton();
	
	textManager.drawTexts();
}
void Menu::cleanMenu(){
	buttons.erase(buttons.begin(),buttons.end());
	textManager.cleanTexts();
}
void Menu::addButton(Vector2 &size,Vector2 &distance,string text,Sprite &buttonBackground){
	Button tempButton;
	SHP2Rectangle buttonPos;
	
	buttonPos.vecMin.x = position.vecMin.x + distance.x;
	buttonPos.vecMax.y = position.vecMax.y - distance.y;
	buttonPos.vecMin.y = buttonPos.vecMax.y - size.y;
	buttonPos.vecMax.x = buttonPos.vecMin.x + size.x;

	tempButton.setButton(buttonBackground,buttonPos,text);
	textManager.addText(tempButton.getPosition(),tempButton.getText());
	
	buttons.push_back(tempButton);
}