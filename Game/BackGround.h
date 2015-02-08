#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../General/Sprite.h"

class BackGround 
{
	Sprite *bgSprite;
	SHP2Rectangle position;

public:
	
	void setPosition(float minx,float miny,float maxx,float maxy);
				//inlines
	inline void draw(){bgSprite->draw();}
	inline void setSprite(Sprite &spr){bgSprite = &spr;}
	inline void setPosition(SHP2Rectangle &pos){setPosition(pos.vecMin.x,pos.vecMin.y,pos.vecMax.x,pos.vecMax.y);}
	inline Sprite& getSprite(){return *bgSprite;}
	inline SHP2Rectangle& getPosition(){return position;}
};




#endif