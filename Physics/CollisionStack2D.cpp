#include "CollisionStack2D.h"

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

void CollisionStack2D::refreshRectangle(SHP2Rectangle &rec,int id){
	aabbs[id] = new SHP2Rectangle(rec);

}

										//new Version
float CollisionStack2D::sweptAABB(SHP2Rectangle &rec1,SHP2Rectangle &rec2,Vector2& normal,Vector2& velocity){
	float xnear,ynear,t_near;

	float velx = velocity.x;
	float vely = velocity.y;

	if(velx > 0) xnear = rec2.vecMin.x - rec1.vecMax.x;
	else xnear = rec2.vecMax.x - rec1.vecMin.x ;
	
	if(vely > 0) ynear = rec2.vecMin.y - rec1.vecMax.y;
	else  ynear = rec2.vecMax.y - rec1.vecMin.y ;
	
	if(velx != 0) xnear = xnear / velx;
	else xnear = -std::numeric_limits<float>::infinity();
	
	if(vely != 0) ynear = ynear / vely;
	else ynear = -std::numeric_limits<float>::infinity();

	if(xnear > ynear){
		if(velx > 0) normal.changeX(-1.0f);
		else normal.changeX(1.0f);
	}
	else {
		if(vely > 0) normal.changeY(-1.0f);
		else normal.changeY(1.0f);
	}
	
	t_near = max(xnear,ynear)-0.001f;
	return t_near;
}	
bool CollisionStack2D::rectangleTrace(SHP2Rectangle &rec,Vector2& normal,Vector2& velocity,float &time){
	bool hit = false;
	float time_old = 1.0f;
	SHP2Rectangle futureRec(rec.vecMin.x + velocity.x,rec.vecMin.y + velocity.y,rec.vecMax.x + velocity.x,rec.vecMax.y + velocity.y);
	for(unsigned int i = 0;i < aabbs.size();i++){
		if(Collision2D::RecRecCol(futureRec,*aabbs[i])){
		hit = true;
		time = sweptAABB(rec,*aabbs[i],normal,velocity);
		if(time < time_old)time_old = time; 
		}
	}
	time = time_old;
	return hit;
}