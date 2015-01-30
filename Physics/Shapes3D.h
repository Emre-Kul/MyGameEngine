#ifndef SHAPES3D_H
#define SHAPES3D_H

#include "../Math/Vectors.h"

struct SHP3Cube{
	Vector3 center;
	float size;
	SHP3Cube();
	SHP3Cube(float a,float b,float c,float siz);
	SHP3Cube(Vector3 &vec,float siz);
};

struct SHP3AABB{
	Vector3 vecMin,vecMax;
	SHP3AABB();
	SHP3AABB(float a,float b,float c,float x,float y,float z);
	SHP3AABB(Vector3 &vec1,Vector3 &vec2);
};

struct SHP3Ray{
	Vector3 V0,V1;
	SHP3Ray();
	SHP3Ray(float a,float b,float c,float x,float y,float z);
	SHP3Ray(Vector3 &vec1,Vector3 &vec2);
};

struct SHP3Plane{
	Vector3 P[4],normal;
};

struct SHP3Triangle{
	Vector3 P[3],normal;
};

struct SHP3Sphere{
	Vector3 center;
	float r;
	SHP3Sphere();
	SHP3Sphere(float a,float b,float c,float radi);
	SHP3Sphere(Vector3 &vec,float radi);
	};
	
struct SHP3Cylinder{
	SHP3Sphere base;
	float h;
};


#endif
