#include "Shapes3D.h"

	SHP3Cube::SHP3Cube(){size = 0;}
	SHP3Cube::SHP3Cube(float a,float b,float c,float siz){
                             center.change(a,b,c);
                             size = siz;
                             }
	SHP3Cube::SHP3Cube(Vector3 &vec,float siz){
                               center.change(vec);
                               size = siz;
                               }


	SHP3AABB::SHP3AABB(){}
	SHP3AABB::SHP3AABB(float a,float b,float c,float x,float y,float z){}
	SHP3AABB::SHP3AABB(Vector3 &vec1,Vector3 &vec2){
                               vecMin.change(vec1);
                               vecMax.change(vec2);
                               }


	
	SHP3Ray::SHP3Ray(){}
	SHP3Ray::SHP3Ray(float a,float b,float c,float x,float y,float z){
                           V0.change(a,b,c);
                           V1.change(x,y,z);
                           }
	SHP3Ray::SHP3Ray(Vector3 &vec1,Vector3 &vec2){
                            V0.change(vec1);
                            V1.change(vec2); 
                             }

	SHP3Sphere::SHP3Sphere(){r = 0;}
	SHP3Sphere::SHP3Sphere(float a,float b,float c,float radi){
                                 center.change(a,b,c);
                                 r = radi;
                                 }
	SHP3Sphere::SHP3Sphere(Vector3 &vec,float radi){
                                   center.change(vec);
                                   r = radi;
                                   }
