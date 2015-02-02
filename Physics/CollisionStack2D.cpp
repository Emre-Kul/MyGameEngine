#include "CollisionStack2D.h"
CollisionWall::CollisionWall(){
	WALLBOTTOM = false;
	WALLTOP = false;
	WALLLEFT = false;
	WALLRIGHT = false;
}

CollisionStack2D::CollisionStack2D(){}
void CollisionStack2D::addRay(SHP2Ray &ray){
	rays.push_back(&ray);
}
void CollisionStack2D::addRectangle(SHP2Rectangle &rec){
	aabbs.push_back(new SHP2Rectangle(rec));
}
void CollisionStack2D::addRectangle(vector <SHP2Rectangle> &rec){
	for(unsigned int i = 0;i < rec.size();i ++)
		aabbs.push_back(new SHP2Rectangle(rec[i]));
}
void CollisionStack2D::addRay(vector <SHP2Ray> &ray){
	for(unsigned int i = 0;i < ray.size();i++)
		rays.push_back(new SHP2Ray(ray[i]));
}
bool CollisionStack2D::rayTrace(SHP2Ray &ray,Vector2 &dot){
	Vector2 vec;
	float current,tolerance = 1;
	bool hit = false;
	for(unsigned int i = 0;i < aabbs.size();i++){
		if(Collision2D::RecRayCol(*aabbs[i],ray,vec,current)){
			
			if(current < tolerance){
				tolerance = current;
				dot = vec; 
				hit = true;
			}
			}
		}
	return hit;
}

bool CollisionStack2D::rayTrace(SHP2Ray &ray,vector <Vector2*> &dot){
	Vector2 vec;
	float current;
	bool hit = false;
	
	dot.clear();
	
	for(unsigned int i = 0;i < aabbs.size();i++){
		if(Collision2D::RecRayCol(*aabbs[i],ray,vec,current)){
			    dot.push_back(new Vector2(vec));
				hit = true;
			
			}
		}
	return hit;
}
bool CollisionStack2D::rectangleTrace(SHP2Rectangle &rec){
	unsigned int i = 0;
	bool hit = false;
		while(i < aabbs.size() && !hit){
			if(Collision2D::RecRecCol(rec,*aabbs[i])) {
				hit = true;
			}
			i++;
		}
		return hit;
}

float CollisionStack2D::sweptAABB(SHP2Rectangle &rec1,SHP2Rectangle &rec2,CollisionWall &wall,float velx,float vely){
	float xnear,ynear,t_near;

	if(velx > 0)
		xnear = rec2.vecMin.x - rec1.vecMax.x;
	else 
		xnear = rec2.vecMax.x - rec1.vecMin.x ;
	
	if(vely > 0)
		ynear = rec2.vecMin.y - rec1.vecMax.y;
	else 
		ynear = rec2.vecMax.y - rec1.vecMin.y ;
	if(velx != 0)
	 xnear = xnear / velx;
	else xnear = -std::numeric_limits<float>::infinity();
	if(vely != 0)
	 ynear = ynear / vely;
	else ynear = -std::numeric_limits<float>::infinity();
	


	if(xnear > ynear){
		if(velx > 0) wall.WALLRIGHT = true;//cout << "SAG ";
		else wall.WALLLEFT = true;//cout << "SOL ";
	}
	else {
		if(vely > 0) wall.WALLTOP = true;//cout << "TOP ";
		else wall.WALLBOTTOM=true;//cout << "BOTTOM ";
	}
	

	t_near = max(xnear,ynear)-0.001f;
	return t_near;
}

bool CollisionStack2D::rectangleTrace(SHP2Rectangle &rec,CollisionWall &WALL,float velx,float vely,float &time){
	bool hit = false;
	float time_old = 1.0f;
	SHP2Rectangle futureRec(rec.vecMin.x + velx,rec.vecMin.y + vely,rec.vecMax.x + velx,rec.vecMax.y + vely);
	for(unsigned int i = 0;i < aabbs.size();i++){
		if(Collision2D::RecRecCol(futureRec,*aabbs[i])){
		hit = true;
		time = sweptAABB(rec,*aabbs[i],WALL,velx,vely);
		if(time < time_old)time_old = time; 
		}
	}
	time = time_old;
	return hit;
}
void CollisionStack2D::refreshRectangle(SHP2Rectangle &rec,int id){
	aabbs[id] = new SHP2Rectangle(rec);

}
/*
float lastSweptAABB(SHP2Rectangle &movedRec,SHP2Rectangle &staticRec,Vector2& normal,Vector2& velocity){
float xnear,ynear,t_near;

	if(velocity.x > 0)
		xnear = staticRec.vecMin.x - movedRec.vecMax.x;
	else 
		xnear = staticRec.vecMax.x - movedRec.vecMin.x ;
	
	if(velocity.y > 0)
		ynear = staticRec.vecMin.y - movedRec.vecMax.y;
	else 
		ynear = staticRec.vecMax.y - movedRec.vecMin.y ;
	if(velocity.x != 0)
	 xnear = xnear / velocity.x;
	else xnear = -std::numeric_limits<float>::infinity();
	if(velocity.y != 0)
	 ynear = ynear / velocity.y;
	else ynear = -std::numeric_limits<float>::infinity();
	


	if(xnear > ynear){
		if(velocity.x > 0) normal.changeX(1.0f);//cout << "SAG ";
		else normal.changeX(-1.0f);//cout << "SOL ";
	}
	else {
		if(velocity.y > 0) normal.changeY(1.0f);//cout << "TOP ";
		else normal.changeY(-1.0f);//cout << "BOTTOM ";
	}
	

	t_near = max(xnear,ynear)-0.001;
	return t_near;


}*/