#ifndef MATRIX_H
#define MATRIX_H

#include "Vectors.h"
#include <math.h>
#include <algorithm>
const float MATH_PI = 3.14159265f;

class Matrix4x4{
	float m[16];
public:
	Matrix4x4();
	Matrix4x4(float a1,float a2,float a3,float a4,float b1,float b2,float b3,float b4,float c1,float c2,float c3,float c4,float d1,float d2,float d3,float d4);
	void setIdentity();
	
	void transpoze();
	void translate(Vector3 &vec);
	void scale(Vector3 &vec);
	void rotate(float angle,Vector3 &vec);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	Vector3 operator*(Vector3& vt);
	float* getMatrix(){return m;}//inline

};

#endif