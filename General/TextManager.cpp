#include "TextManager.h"
Font::Font(){}
Font::Font(int textureid,int wth,int hgh,vector <SHP2Rectangle*> &letter,vector <unsigned int> &letter_id){
					  width = wth;
					  height = hgh;
					  font_texture_id = textureid;
                      letters = letter;
					  letter_ids = letter_id;
                      
                      
           } 
int Font::getLetterRectangle(int id){
	unsigned int i = 0;
	if(letter_ids.size() > 0){
		while (i < letter_ids.size() && id != (int)letter_ids[i] ) i++;
		if(i < letter_ids.size()) return i;
	}
	return -1;
	
}

void TextManager::BindFont(Font tmf){currentFont = tmf;}
void TextManager::setPosition(float minx,float miny,float maxx,float maxy){
     text_position.vecMin.change(minx,miny);
     text_position.vecMax.change(maxx,maxy);
     }
void TextManager::setPosition(SHP2Rectangle &pos){
     text_position = pos;
     }
void TextManager::setText(string str){
     text_string = str;
     };
void TextManager::drawText(){
	    SHP2Rectangle texRec,posRec;
		float hgh = text_position.vecMax.x - text_position.vecMin.x;
		posRec = text_position;
		int num ;
		for(unsigned int i = 0;i < text_string.length();i++){
		num = currentFont.getLetterRectangle((unsigned int)text_string[i]);
		if(num >= 0){
		texRec.vecMin.change(
		 1.0f/(float)currentFont.width * currentFont.letters[num]->vecMin.x,
		 1.0f/(float)currentFont.height * currentFont.letters[num]->vecMin.y);
		texRec.vecMax.change(
		 1.0f/(float)currentFont.width * currentFont.letters[num]->vecMax.x,
		 1.0f/(float)currentFont.height * currentFont.letters[num]->vecMax.y
		);
		posRec.vecMax.changeX(text_position.vecMax.x + hgh*i);
		posRec.vecMin.changeX(text_position.vecMin.x + hgh*i);
	
		}
		
		
		}
}     


