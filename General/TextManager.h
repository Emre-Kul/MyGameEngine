#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <iostream>
#include <string.h>
#include <vector>
#include "../Physics/Shapes2D.h"

using std::vector;
using std::string;

class Font{
	public:
	   int font_texture_id;
	   int width,height;

       vector <SHP2Rectangle*> letters;       
       vector <unsigned int> letter_ids;
       
       Font();
       Font(int textureid,int wth,int hgh,vector <SHP2Rectangle*> &letter,vector <unsigned int> &letter_id);
	   int getLetterRectangle(int id);	    
       };
/*
struct Text{
string str;
position

};
*/
class TextManager{
          
          string text_string;
          float *meshTEXT;

      public:
		  SHP2Rectangle text_position;
          Font currentFont;
          void BindFont(Font tmf);
          
          void setPosition(float minx,float miny,float maxx,float maxy);
          void setPosition(SHP2Rectangle &pos);
          
          void setText(string str);
          //void drawText(Text &txt);     
          void drawText();
      
      };
#endif
