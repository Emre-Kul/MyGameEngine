#include "Collision2D.h"
bool Collision2D::RecPointCol(SHP2Rectangle &rec,Vector2 &point){
	if(point.x < rec.vecMin.x || point.x > rec.vecMax.x)return false;
	if(point.y < rec.vecMin.y || point.y > rec.vecMax.y)return false;
	return true;
}
bool Collision2D::RecRecCol(SHP2Rectangle &rec1,SHP2Rectangle &rec2){
	/*
	bool intersects(const Rectf& r1, const Rectf& r2)
{
  if(r1.p2.x < r2.p1.x || r1.p1.x > r2.p2.x)
    return false;
  if(r1.p2.y < r2.p1.y || r1.p1.y > r2.p2.y)
    return false;

  return true;
}

	*/
	return (rec1.vecMin.x < rec2.vecMax.x &&
			rec1.vecMax.x > rec2.vecMin.x &&
			rec1.vecMin.y < rec2.vecMax.y && 
			rec1.vecMax.y > rec2.vecMin.y 
			);
}
bool Collision2D::RecRayCol(SHP2Rectangle &rec,SHP2Ray &r,Vector2 &dot,float &t){
	float t_min,t_max,min,max;
	Vector2 B;
	B = r.P1-r.P0;

	t_min = 0;
	t_max = 1;
	
	if(!clipLine(r.P0.x,r.P1.x,rec.vecMin.x,rec.vecMax.x,t_min,t_max))return false;
	if(!clipLine(r.P0.y,r.P1.y,rec.vecMin.y,rec.vecMax.y,t_min,t_max))return false;


	if(t_max < t_min)t_min = t_max;

	dot = (r.P0 + B*t_min);
	t = t_min;

	return true;
}
bool Collision2D::CircleCircleCol(SHP2Circle &cr1,SHP2Circle &cr2){
	Vector2 dVec;
	dVec = cr2.center-cr1.center;
	return ( dVec.length() <= (cr1.r+cr2.r) );

}
