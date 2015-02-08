#include "BackGround.h"
void BackGround::setPosition(float minx,float miny,float maxx,float maxy){
	position.vecMax.change(maxx,maxy);
	position.vecMin.change(minx,miny);
}