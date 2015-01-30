#ifndef COLLISIONSTACK2D_H
#define COLLISIONSTACK2D_H

#include <vector>
#include "Shapes2D.h"
#include "Collision2D.h"
using std::vector;

struct CollisionWall{
bool WALLTOP,WALLBOTTOM,WALLRIGHT,WALLLEFT;
CollisionWall();
};

class CollisionStack2D{
		public:
		vector <SHP2Rectangle*> aabbs;
		vector <SHP2Ray*> rays;
	    
		
		float sweptAABB(SHP2Rectangle &rec1,SHP2Rectangle &rec2,CollisionWall &wall,float velx,float vely);
		
		CollisionStack2D();

		void addRay(SHP2Ray &ray);
		void addRay(vector <SHP2Ray> &ray);
		
		
		void addRectangle(SHP2Rectangle &rec);
		void addRectangle(vector <SHP2Rectangle> &rec);

		void refreshRectangle(SHP2Rectangle &rec,int id);
	

		bool rayTrace(SHP2Ray &ray,Vector2 &dot);
		bool rayTrace(SHP2Ray &ray,vector <Vector2*> &dot);
	
		bool rectangleTrace(SHP2Rectangle &rec);
		bool rectangleTrace(SHP2Rectangle &rec,CollisionWall &WALL,float velx,float vely,float &time);

};




#endif
