#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <iostream>
#include <string.h>
#include <vector>
#include "../Physics/Shapes2D.h"
#include "../Renderer/MeshCreator.h"
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

class TextManager{
		  vector <SHP2Rectangle> positions;
		  vector <string> texts;
		  
		  Font currentFont;
		  string text_string;

		  Mesh text_mesh;
          Vector2 size;
      public:
		 
		  void addText(SHP2Rectangle &pos,string text);
          void BindFont(Font &tmf,Vector2 &sz);
          void drawTexts();
		  void cleanTexts();
		  void generateMesh();	
      };
#endif
