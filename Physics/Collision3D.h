#ifndef COLLISION3D_H
#define COLLISION3D_H

#include "Shapes3D.h"
#include "../Math/MathLib.h"



class Collision3D{
public:
	static bool RayAABBCol(SHP3Ray &r,SHP3AABB &ab,Vector3 &dot,float &ffrac);
	static bool BoxBoxCol(SHP3Cube &bx1,SHP3Cube &bx2);
	static bool RaySphCol(SHP3Ray &ry,SHP3Sphere &sp,float t);
	static bool RayPlaneCol(SHP3Ray &ry,SHP3Plane &pl);
	static bool SphPlaneCol(SHP3Sphere &ry,SHP3Plane &pl);
	static bool SphSphCol(SHP3Sphere &sp1,SHP3Sphere &sp2);
	static bool InfiniteRaySphCol(SHP3Ray &ry,SHP3Sphere &sp,float *T1,float *T2);

};
#endif
