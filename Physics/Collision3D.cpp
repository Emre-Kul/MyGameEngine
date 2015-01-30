#include "Collision3D.h"

bool Collision3D::RayAABBCol(SHP3Ray &r,SHP3AABB &ab,Vector3 &dot,float &ffrac){
	float t_min,t_max;
	Vector3 B;
	B = r.V1-r.V0;

	t_min = 0;
	t_max = 1;
	
	if(!clipLine(r.V0.x,r.V1.x,ab.vecMin.x,ab.vecMax.x,t_min,t_max))return false;
	if(!clipLine(r.V0.y,r.V1.y,ab.vecMin.y,ab.vecMax.y,t_min,t_max))return false;
	if(!clipLine(r.V0.z,r.V1.z,ab.vecMin.z,ab.vecMax.z,t_min,t_max))return false;

	if(t_max < t_min)t_min = t_max;
	dot = r.V0+B*t_min;
	

	ffrac = t_min;
	return true;
}


bool Collision3D::SphSphCol(SHP3Sphere &sp1,SHP3Sphere &sp2){
	float dist = PointDistance(sp1.center,sp2.center);
	return (dist <= (sp1.r+sp2.r));

}
bool Collision3D::RaySphCol(SHP3Ray &ry,SHP3Sphere &sp,float t){

	//bu algoritmayý yaz
	return false;
}

bool Collision3D::InfiniteRaySphCol(SHP3Ray &ry,SHP3Sphere &sp,float *T1,float *T2){
	float a,b,c,delta;
	Vector3 vec;
	//BU FONKSIYON YANLIÞ
	vec = ry.V0-sp.center;
	a = DotProduct(ry.V1,ry.V1);
	b = 2*DotProduct( vec, ry.V1);
	c = DotProduct(vec,vec) - sp.r*sp.r; 
	
	delta = (b*b - 4*a*c);
	if(a == 0){
	*T1 = *T2 = 0.0f;
	}
	else if(delta >= 0){
		*T1 = (-b - sqrt(delta))/2*a;
		*T2 = (-b + sqrt(delta))/2*a;
		
	return true;
	}
	return false;
	

	
}   
bool Collision3D::RayPlaneCol(SHP3Ray &ry,SHP3Plane &pl){

    return false;
     }     
bool Collision3D::BoxBoxCol(SHP3Cube &bx1,SHP3Cube &bx2){
	
	float size1,size2;
	Vector3 vec1,vec2;
	vec1 = bx1.center;
	vec2 = bx2.center;
	
	size1 = bx1.size;
	size2 = bx2.size;

	    return(vec1.x + size1 > vec2.x - size2 && 
			   vec1.x - size1 < vec2.x + size2 &&
			   vec1.y + size1 > vec2.y - size2 &&
			   vec1.y - size1 < vec2.y + size2 &&
               vec1.z + size1 > vec2.z - size2 &&
               vec1.z - size1 < vec2.z + size2);
}
