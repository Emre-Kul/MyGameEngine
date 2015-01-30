#include "Matrix.h"
Matrix4x4::Matrix4x4(){
		  matrix[0] = 1; matrix[1] = 0; matrix[2] = 0; matrix[3] = 0;
		  matrix[4] = 0; matrix[5] = 1; matrix[6] = 0; matrix[7] = 0;
		  matrix[8] = 0; matrix[9] = 0; matrix[10] = 1; matrix[11] = 0;
		  matrix[12] = 0; matrix[13] = 0; matrix[14] = 0; matrix[15] = 1;
}//when using for its crash
Matrix4x4::Matrix4x4(float a1,float a2,float a3,float a4,float b1,float b2,float b3,float b4,float c1,float c2,float c3,float c4,float d1,float d2,float d3,float d4){
				  matrix[0] = a1; matrix[1] = a2; matrix[2] = a3; matrix[3] = a4;
				  matrix[4] = b1; matrix[5] = b2; matrix[6] = b3; matrix[7] = b4;
				  matrix[8] = c1; matrix[9] = c2; matrix[10] = c3; matrix[11] = c4;
				  matrix[12] = d1; matrix[13] = d2; matrix[14] = d3; matrix[15] = d4;
}
void Matrix4x4::setIdentity(){
	 matrix[0] = 1; matrix[1] = 0; matrix[2] = 0; matrix[3] = 0;
     matrix[4] = 0; matrix[5] = 1; matrix[6] = 0; matrix[7] = 0;
     matrix[8] = 0; matrix[9] = 0; matrix[10] = 1; matrix[11] = 0;
     matrix[12] = 0; matrix[13] = 0; matrix[14] = 0; matrix[15] = 1;
}

void Matrix4x4::translate(Vector3 &vec){
	matrix[3] += matrix[0]*vec.x + matrix[1] *vec.y + matrix[2]*vec.z;
	matrix[7] += matrix[4]*vec.x + matrix[5] *vec.y + matrix[6]*vec.z;
	matrix[11] += matrix[8]*vec.x + matrix[9] *vec.y + matrix[10]*vec.z;
	matrix[15] += matrix[12]*vec.x + matrix[13] *vec.y + matrix[14]*vec.z;
}
void Matrix4x4::scale(Vector3 &vec){
	 matrix[0] *= vec.x; matrix[1] *= vec.x; matrix[2] *= vec.x; matrix[3] *= vec.x;
     matrix[4] *= vec.y; matrix[5] *= vec.y; matrix[6] *= vec.y; matrix[7] *= vec.y;
     matrix[8] *= vec.z; matrix[9] *= vec.z; matrix[10] *= vec.z; matrix[11] *= vec.z;
}
