#ifndef COLLISION2D_H
#define COLLISION2D_H
#include "Shapes2D.h"

class Collision2D{
public:
	static bool RecPointCol(SHP2Rectangle &rec,Vector2 &point);
	static bool RecRecCol(SHP2Rectangle &rec1,SHP2Rectangle &rec2);
	static bool RecRayCol(SHP2Rectangle &rec,SHP2Ray &r,Vector2 &dot,float &t);
	static bool CircleCircleCol(SHP2Circle &cr1,SHP2Circle &cr2);
	static bool RayRayCol(SHP2Ray &ray1,SHP2Ray &ray2);
};





#endif
