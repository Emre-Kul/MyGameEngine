#ifndef VECTORS_H
#define VECTORS_H

#include <cmath>

class Vector2{

	public: 
		float x,y;
		Vector2();
		Vector2(float a,float b);
		Vector2(const Vector2 &vec);

		
		void change(float a,float b);
		void changeX(float a){x = a;}//inline
		void changeY(float a){y = a;}//inline
	
		void normalize(Vector2 &vec);
		float length(){return (float)sqrt( (x*x) + (y*y));}//inline

		Vector2 operator+(const Vector2 vec);
		Vector2 operator-(const Vector2 vec);
		Vector2 operator*(float num);
		Vector2 operator/(float num);
             
		Vector2 operator+=(const Vector2 vec);
		Vector2 operator-=(const Vector2 vec);
		Vector2 operator*=(float num);
		Vector2 operator/=(float num);

};
class Vector3{
	     public:
             float x,y,z;
            
             Vector3();
	     Vector3(float a,float b);
             Vector3(float a,float b,float c);
             Vector3(const Vector3 &vec2);
      
             void change(float a,float b,float c);
             void change (const Vector3 &vec2);
	     void changeX(float a){x = a;}//inline
	     void changeY(float a){y = a;}//inline
	     void changeZ(float a){z = a;}//inline
             
             void normalize(Vector3 &vec);
	     float length(){return sqrt(x*x+y*y+z*z);}//inline
             Vector3 normalize();
             
             Vector3 operator+(const Vector3 vec2);
             Vector3 operator-(const Vector3 vec2);
             Vector3 operator*(float num);
             Vector3 operator/(float num);
             
             Vector3 operator+=(const Vector3 vec2);
             Vector3 operator-=(const Vector3 vec2);
             Vector3 operator*=(float num);
             Vector3 operator/=(float num);
             
             
      };
class Vector4{
	public:
		float x,y,z,w;
		Vector4();
		Vector4(float a,float b,float c,float d);
		void change(float a,float b,float c,float d);
		
		void changeX(float a);
		void changeY(float a);
		void changeZ(float a);
		void changeW(float a);
		
	};



#endif
