#ifndef CAMERA_H
#define CAMERA_H

#include "../Math/Vectors.h"
#include "../Math/Matrix.h"
#include "../Math/Mathlib.h"

class Camera{
	Vector3 position;
	Matrix4x4 viewMatrix;	
	float cyaw,cpitch,croll;

public:
	void setCamera(Vector3 &pos,float yaw,float pitch,float roll);
				//inlines
	inline void generateViewMatrix(){viewMatrix = MathLib::generateViewMatrix(position,cpitch,cyaw,croll);}
	inline void setPosition(Vector3 &vec){position = vec;}
	inline Vector3& getPosition(){return position;}	
	inline Matrix4x4& getViewMatrix(){return viewMatrix;}

};

#endif