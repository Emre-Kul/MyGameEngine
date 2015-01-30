#ifndef CAMERA_H
#define CAMERA_H

#include "../Math/Vectors.h"
#include "../Math/Matrix.h"

class Camera{
	Vector3 position,eye,up;
	Matrix4x4 viewMatrix;	
	float yaw,pitch,roll;

public:
	
	void setCamera(Vector3 &posV,Vector3 &eyeV,Vector3 &upV);
	void generateViewMatrix();

				//inlines
	void setPosition(Vector3 &vec){position = vec;}
	void setUp(Vector3 &vec){eye = vec;}
	void setEye(Vector3 &vec){up = vec;}

	Vector3& getPosition(){return position;}
	Vector3& getEye(){return eye;}
	Vector3& getUp(){return up;}
	Matrix4x4& getViewMatrix(){return viewMatrix;}

};

#endif