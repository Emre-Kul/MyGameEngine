#ifndef SHAPES2D_H
#define SHAPES2D_H

#include "../Math/Vectors.h"
#include "../Math/MathLib.h"

struct SHP2Rectangle{//AABB
	Vector2 vecMin,vecMax;
	SHP2Rectangle();
    SHP2Rectangle(float minx,float miny,float maxx,float maxy);
};  

struct SHP2Circle{
	Vector2 center;
	float r;
    SHP2Circle();
    SHP2Circle(float cx,float cy,float radi);
    SHP2Circle(Vector2 &vec,float radi);	
};

struct SHP2Ray{
    Vector2 P0,P1;
    SHP2Ray();
    SHP2Ray(float x0,float y0,float x1,float y1);
    SHP2Ray(Vector2 &vec1,Vector2 &vec2);       
};

struct SHP2Triangle{
    Vector2 P[3],normal;
};

struct SHP2Plane{
    Vector2 P[4],normal;
};

#endif
