#include "Matrix.h"
Matrix4x4::Matrix4x4(){
	 m[0] = 1; m[1] = 0; m[2] = 0; m[3] = 0;
     m[4] = 0; m[5] = 1; m[6] = 0; m[7] = 0;
	 m[8] = 0; m[9] = 0; m[10] = 1; m[11] = 0;
     m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}//when using for its crash
Matrix4x4::Matrix4x4(float a1,float a2,float a3,float a4,float b1,float b2,float b3,float b4,float c1,float c2,float c3,float c4,float d1,float d2,float d3,float d4){
	m[0] = a1; m[1] = a2; m[2] = a3; m[3] = a4;
	m[4] = b1; m[5] = b2; m[6] = b3; m[7] = b4;
	m[8] = c1; m[9] = c2; m[10] = c3; m[11] = c4;
	m[12] = d1; m[13] = d2; m[14] = d3; m[15] = d4;
}
void Matrix4x4::setIdentity(){
	 m[0] = 1; m[1] = 0; m[2] = 0; m[3] = 0;
     m[4] = 0; m[5] = 1; m[6] = 0; m[7] = 0;
	 m[8] = 0; m[9] = 0; m[10] = 1; m[11] = 0;
     m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}
void Matrix4x4::transpoze(){
	for(int i = 0;i < 4;i++) for (int j = i*5;j < i+4;j++)swap(m[i],m[j]);
}
void Matrix4x4::translate(Vector3 &vec){
	m[0] += m[12]*vec.x;	
	m[1] += m[13]*vec.x;
	m[2] += m[14]*vec.x;
	m[3] += m[15]*vec.x;

	m[4] += m[12]*vec.y;	
	m[5] += m[13]*vec.y;
	m[6] += m[14]*vec.y;
	m[7] += m[15]*vec.y;

	m[8] += m[12]*vec.z;	
	m[9] += m[13]*vec.z;
	m[10] += m[14]*vec.z;
	m[11] += m[15]*vec.z;

}
void Matrix4x4::scale(Vector3 &vec){
	 m[0] *= vec.x; m[1] *= vec.x; m[2] *= vec.x; m[3] *= vec.x;
     m[4] *= vec.y; m[5] *= vec.y; m[6] *= vec.y; m[7] *= vec.y;
     m[8] *= vec.z; m[9] *= vec.z; m[10] *= vec.z; m[11] *= vec.z;
}//correct
void Matrix4x4::rotate(float angle,Vector3 &vec){
	if(angle < 0.0f)while(angle < 0.0f) angle += 360.0f;
	else while(angle > 360.0f) angle -= 360.0f;
	
	float cosa = cosf(angle*MATH_PI/180.0f);
	float sina = sinf(angle*MATH_PI/180.0f);
	
	if(angle == 0.0f || angle == 360.0f)sina = 0.0f;
	if(angle == 90.0f)cosa = 0.0f;
	if(angle == 180.0f)sina = 0.0f;
	if(angle == 270.0f)cosa = 0.0f;

}
void Matrix4x4::rotateX(float angle){
	//1 0 0 0
	//0 cosx -sinx 0
	//0 sinx cosx 0
	//0 0 0 1
	if(angle < 0.0f)while(angle < 0.0f) angle += 360.0f;
	else while(angle > 360.0f) angle -= 360.0f;
	
	float cosa = cosf(angle*MATH_PI/180.0f);
	float sina = sinf(angle*MATH_PI/180.0f);
	
	if(angle == 0.0f || angle == 360.0f)sina = 0.0f;
	if(angle == 90.0f)cosa = 0.0f;
	if(angle == 180.0f)sina = 0.0f;
	if(angle == 270.0f)cosa = 0.0f;
	
	float m4,m5,m6,m7;//because this is cahncing and using again
	m4 = m[4]; 
	m5 = m[5]; 
	m6 = m[6]; 
	m7 = m[7];

	m[4] = m4 * cosa + m[8] * sina;
	m[8] = m4 * -sina + m[8] * cosa;
	
	m[5] = m5 * cosa + m[9] * sina;
	m[9] = m5 * -sina + m[9] * cosa;
	
	m[6] = m6 * cosa + m[10] * sina;
	m[10] = m6 * -sina + m[10] * cosa;
	
	m[7] = m7 * cosa + m[11] * sina;
	m[11] = m7 * -sina + m[11] * cosa;
	
	for(int i = 0;i < 16;i++) m[i]  += 0.0f;//for -0.0
}
void Matrix4x4::rotateY(float angle){
	//cosx 0 sinx 0
	// 0 1 0 0
	//-sinx 0 cosx 0
	//0 0 0 1
	if(angle < 0.0f)while(angle < 0.0f) angle += 360.0f;
	else while(angle > 360.0f) angle -= 360.0f;
	
	float cosa = cosf(angle*MATH_PI/180.0f);
	float sina = sinf(angle*MATH_PI/180.0f);
	
	if(angle == 0.0f || angle == 360.0f)sina = 0.0f;
	if(angle == 90.0f)cosa = 0.0f;
	if(angle == 180.0f)sina = 0.0f;
	if(angle == 270.0f)cosa = 0.0f;
	float m0,m4,m8,m12;
	m0 = m[0]; 
	m4 = m[4]; 
	m8 = m[8]; 
	m12 = m[12];

	m[0] = m0 * cosa + m[2] * -sina;
	m[2] = m0 * sina + m[2] * cosa;
	m[4] = m4 * cosa + m[6] * -sina;
	m[6] = m4 * sina + m[6] * cosa;
	m[8] = m8 * cosa + m[10] * -sina;
	m[10] = m8 * sina + m[10] * cosa;
	m[12] = m12 * cosa + m[14] * -sina;
	m[14] = m12 * sina + m[14] * cosa;

	for(int i = 0;i < 16;i++) m[i] += 0.0f;
}
void Matrix4x4::rotateZ(float angle){
	//cosx -sinx 0 0
	//sinx cosx 0 0
	//0 0 1 0
	//0 0 0 1

	if(angle < 0.0f)while(angle < 0.0f) angle += 360.0f;
	else while(angle > 360.0f) angle -= 360.0f;
	
	float cosa = cosf(angle*MATH_PI/180.0f);
	float sina = sinf(angle*MATH_PI/180.0f);
	
	if(angle == 0.0f || angle == 360.0f)sina = 0.0f;
	if(angle == 90.0f)cosa = 0.0f;
	if(angle == 180.0f)sina = 0.0f;
	if(angle == 270.0f)cosa = 0.0f;

	float m0,m4,m8,m12;
	m0 = m[0]; 
	m4 = m[4]; 
	m8 = m[8]; 
	m12 = m[12];

	m[0] = m0 * cosa + m[1] * sina;
	m[1] = m0 * -sina + m[1] * cosa;
	m[4] = m4 * cosa + m[5] * sina;
	m[5] = m4 * -sina + m[5] * cosa;
	m[8] = m8 * cosa + m[9] * sina;
	m[9] = m8 * -sina + m[9] * cosa;
	m[12] = m12 * cosa + m[13] * sina;
	m[13] = m12 * -sina + m[13] * cosa;

	for(int i = 0;i < 16;i++) m[i] += 0.0f;

}
Vector3 Matrix4x4::operator*(Vector3& vt){
	Vector3 temp;
	temp.x = vt.x* m[0] + vt.y *m[1] + vt.z*m[2] + m[3];
	temp.y = vt.x* m[4] + vt.y *m[5] + vt.z*m[6] + m[7];
	temp.z = vt.x* m[8] + vt.y *m[9] + vt.z*m[10] + m[11];
	return temp;

}
