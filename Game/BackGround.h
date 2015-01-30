#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../General/Sprite.h"

class BackGround 
{
	Sprite *bgSprite;
	SHP2Rectangle position;
	Vector3 midPosition;
public:
	
	void setPosition(float minx,float miny,float maxx,float maxy);
	void draw(){bgSprite->draw();}

	Vector3& getMidPosition(){return midPosition;}
	void setSprite(Sprite &spr){bgSprite = &spr;}
	void setPosition(SHP2Rectangle &pos){setPosition(pos.vecMin.x,pos.vecMin.y,pos.vecMax.x,pos.vecMax.y);}
	Sprite& getSprite(){return *bgSprite;}
	SHP2Rectangle& getPosition(){return position;}
};




#endif