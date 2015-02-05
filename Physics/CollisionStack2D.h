#ifndef COLLISIONSTACK2D_H
#define COLLISIONSTACK2D_H

#include <vector>
#include "Collision2D.h"
using std::vector;

class CollisionStack2D{
		public:
		
		vector <SHP2Rectangle*> aabbs;
		vector <SHP2Ray*> rays;

		CollisionStack2D(){}

		inline void addRay(SHP2Ray &ray){rays.push_back(&ray);}
		inline void addRectangle(SHP2Rectangle &rec){aabbs.push_back(new SHP2Rectangle(rec));}

		void addRay(vector <SHP2Ray> &ray);
		void addRectangle(vector <SHP2Rectangle> &rec);

		void refreshRectangle(SHP2Rectangle &rec,int id);

		bool rayTrace(SHP2Ray &ray,Vector2 &dot);
		bool rayTrace(SHP2Ray &ray,vector <Vector2*> &dot);
	
		bool rectangleTrace(SHP2Rectangle &rec);
		bool rectangleTrace(SHP2Rectangle &rec,Vector2& normal,Vector2& velocity,float &time);
		
		float sweptAABB(SHP2Rectangle &rec1,SHP2Rectangle &rec2,Vector2& normal,Vector2& velocity);	

};




#endif
