#include "MathLib.h"


bool clipLine(float rv1,float rv2,float boxmin,float boxmax,float &ft_min,float &ft_max){
	float t_min,t_max,B;
	B = rv2-rv1;
	t_min =  (boxmin-rv1)/B;
	t_max =  (boxmax-rv1)/B;

	if(t_max < t_min)	swap(t_max,t_min);
	
	if(t_max < ft_min)return false; 
	if(t_min > ft_max)return false;
	
	ft_min = max(ft_min,t_min);
	ft_max = min(ft_max,t_max);

	if(ft_max < ft_min)return false;

	return true;
}
float Approach(float Goal,float Current,float Deltatime){
	float distance = Goal-Current;
	
	if(distance > Deltatime) return Current+Deltatime; 
	if(distance < -Deltatime) return Current-Deltatime;
	
	return Goal;
}//üstüne düþün
			/************ 3D ***************/
float DotProduct(Vector3 &vc1,Vector3 &vc2){  
	return  (vc1.x*vc1.x + vc1.y*vc2.y + vc1.z*vc2.z);
}
float PointDistance(Vector3 &p1,Vector3 &p2){
Vector3 newVec;
newVec = p2-p1;
return newVec.length();
}
			/************ 2D ***************/
float DotProduct(Vector2 &vc1,Vector2 &vc2){
	return  (vc1.x*vc1.x + vc1.y*vc2.y);
}
float PointDistance(Vector2 &p1,Vector2 &p2){
Vector2 newVec;
newVec = p2-p1;
return newVec.length();
}

Matrix4x4 MathLib::generateTransformMatrix(Vector3& translation,Vector3& rotation,Vector3& scale){// rotation missing
	Matrix4x4 transformMat;//identity matrix
	transformMat.translate(translation);
	transformMat.scale(scale);
	
	transformMat.rotateX(rotation.x);
	transformMat.rotateY(rotation.y);
	transformMat.rotateZ(rotation.z);
	return transformMat;
}//done
Matrix4x4 MathLib::generateProjectionMatrix(float ratio,float angle,float near,float far){
	Matrix4x4 prm;	
	float y_scale = (1.0f/tan((double)angle * MATH_PI/180.0))*ratio;
	float x_scale = y_scale/ratio;
	float length = far - near;
	prm.getMatrix()[0] = x_scale;
	prm.getMatrix()[5] = y_scale;
	prm.getMatrix()[10] = -(far + near)/length;
	prm.getMatrix()[11] = -((2.0f * near * far)/length);
	prm.getMatrix()[14] = -1.0f;
	prm.getMatrix()[15] = 0.0f;
	return prm;
}//done
Matrix4x4 MathLib::generateViewMatrix(Vector3& position,float pitch,float yaw,float roll){
	Matrix4x4 view;
	view.rotate(pitch,Vector3(1,0,0));
	view.rotate(yaw,Vector3(0,1,0));
	Vector3 negative;
	negative -= position;
	view.translate(negative);
	return view;
}//done