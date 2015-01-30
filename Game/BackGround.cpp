#include "BackGround.h"
void BackGround::setPosition(float minx,float miny,float maxx,float maxy){
	position.vecMax.change(maxx,maxy);
	position.vecMin.change(minx,miny);
	midPosition.x = (position.vecMax.x + position.vecMin.x)/2;
	midPosition.y = (position.vecMax.y + position.vecMin.y)/2;
}