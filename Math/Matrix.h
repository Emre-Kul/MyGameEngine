#ifndef MATRIX_H
#define MATRIX_H

#include "Vectors.h"

class Matrix4x4{
	float matrix[16];
public:
	Matrix4x4();
	Matrix4x4(float a1,float a2,float a3,float a4,float b1,float b2,float b3,float b4,float c1,float c2,float c3,float c4,float d1,float d2,float d3,float d4);
	void setIdentity();
	
	void translate(Vector3 &vec);
	void scale(Vector3 &vec);
	void rotate(float angle,Vector3 &vec){}
	void rotateX(float angle){}
	void rotateY(float angle){}
	void rotateZ(float angle){}

	float* getMatrix(){return matrix;}//inline

};

#endif