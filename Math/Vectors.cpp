#include "Vectors.h"
									//VECTOR2//
Vector2::Vector2(){
	x = 0; 
	y = 0;
 }
Vector2::Vector2(float a,float b){
	x = a;
	y = b;
 }
Vector2::Vector2(const Vector2 &vec){
	x = vec.x;
	y = vec.y;
  }
void Vector2::change(float a,float b){
	x = a;
	y = b;
 }
Vector2 Vector2::normalize(){
	Vector2 CopVec;
	float len = length();
	CopVec.x = x/len;
	CopVec.y = y/len;
	return CopVec;
}
Vector2 Vector2::operator+=(const Vector2 vec){
x += vec.x;
y += vec.y;
return *this;
}
Vector2 Vector2::operator-=(const Vector2 vec){
x -= vec.x;
y -= vec.y;
return *this;
}
Vector2 Vector2::operator*=(float num){
x*= num;
y*= num;
return *this;
}
Vector2 Vector2::operator/=(float num){
x/= num;
y/= num;
return *this;
}     
Vector2 Vector2::operator+(const Vector2 vec){return Vector2(x+vec.x,y+vec.y);}
Vector2 Vector2::operator-(const Vector2 vec){return Vector2(x-vec.x,y-vec.y);}
Vector2 Vector2::operator*(float num){return Vector2(x*num,y*num);}
Vector2 Vector2::operator/(float num){return Vector2(x/num,y/num);}

void Vector2::normalize(Vector2 &vec){}
void Vector2::MoveDirect(Vector2 &current,Vector2 &target,float t){}
void Vector2::MoveLerp(Vector2 &current,Vector2 &target,float t){}
void Vector2::DotProduct(Vector2 &vec1,Vector2 &vec2){}

									//VECTOR3//
Vector3::Vector3(){
	x = 0;
	y = 0;
	z = 0;
}
Vector3::Vector3(float a,float b){
x = a;
y = b;
z = 0;
}
Vector3::Vector3(float a,float b,float c){
                          x = a;
                          y = b;
                          z = c;
                          }
Vector3::Vector3(const Vector3 &vec2){
                          x = vec2.x;
                          y = vec2.y;
                          z = vec2.z;
                          }
void  Vector3::change(float a,float b,float c){
                          x = a;
                          y = b;
                          z = c;
                          }
void  Vector3::change (const Vector3 &vec2){
                          x = vec2.x;
                          y = vec2.y;
                          z = vec2.z;
                          }
Vector3 Vector3::normalize(){
       Vector3 copyVec;
	   copyVec.change(x,y,z); 
       float len = copyVec.length();
       copyVec.changeX(x/len);
       copyVec.changeY(y/len);
       copyVec.changeZ(z/len); 
       return copyVec;    
          }
Vector3 Vector3::operator+(const Vector3 vec2){return Vector3(x+vec2.x,y+vec2.y,z+vec2.z);}
Vector3 Vector3::operator-(const Vector3 vec2){return Vector3(x-vec2.x,y-vec2.y,z-vec2.z);}
Vector3 Vector3::operator*(float num){return Vector3(x*num,y*num,z*num);}
Vector3 Vector3::operator/(float num){return Vector3(x/num,y/num,z/num);}
Vector3 Vector3::operator+=(const Vector3 vec2){
             x+=vec2.x;
             y+=vec2.y;
             z+=vec2.z;
             return *this;
             }
Vector3 Vector3::operator-=(const Vector3 vec2){
             x-=vec2.x;
             y-=vec2.y;
             z-=vec2.z;
             return *this;
             }
Vector3 Vector3::operator*=(float num){
             x*=num;
             y*=num;
             z*=num;
             return *this;
             }
Vector3 Vector3::operator/=(float num){
             x/=num;
             y/=num;
             z/=num;
             return *this;
             }

void Vector3::normalize(Vector3 &vec){
       float len,a,b,c;
       len = vec.length();
       a = vec.x/len;
       b = vec.y/len;
       c = vec.z/len;
       vec.change(a,b,c);
       }
void Vector3::MoveDirect(Vector3 &current,Vector3 &target,float t){}
void Vector3::MoveLerp(Vector3 &current,Vector3 &target,float t){}
void Vector3::DotProduct(Vector3 &vec1,Vector3 &vec2){}
