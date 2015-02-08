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
		Vector2 normalize();
					//inlines
		inline void changeX(float a){x = a;}
		inline void changeY(float a){y = a;}
		inline float sqrMaq(){return (x*x + y*y);}
		inline float length(){return (float)sqrt( (x*x) + (y*y));}

		Vector2 operator+(const Vector2 vec);
		Vector2 operator-(const Vector2 vec);
		Vector2 operator*(float num);
		Vector2 operator/(float num);
             
		Vector2 operator+=(const Vector2 vec);
		Vector2 operator-=(const Vector2 vec);
		Vector2 operator*=(float num);
		Vector2 operator/=(float num);
					//Static func like Vector3
		static void normalize(Vector2 &vec);
        static void MoveDirect(Vector2 &current,Vector2 &target,float t);
        static void MoveLerp(Vector2 &current,Vector2 &target,float t);
		static void DotProduct(Vector2 &vec1,Vector2 &vec2);
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
			 Vector3 normalize();
						//inlines
			 inline void changeX(float a){x = a;}
			 inline void changeY(float a){y = a;}
			 inline void changeZ(float a){z = a;}
			 inline float SqrMag(){return (x*x + y*y + z*z);}
			 inline float length(){return sqrt(x*x+y*y+z*z);}
            
             Vector3 operator+(const Vector3 vec2);
             Vector3 operator-(const Vector3 vec2);
             Vector3 operator*(float num);
             Vector3 operator/(float num);
             
             Vector3 operator+=(const Vector3 vec2);
             Vector3 operator-=(const Vector3 vec2);
             Vector3 operator*=(float num);
             Vector3 operator/=(float num);
             
					//Static Functions Not Ready
			 static void normalize(Vector3 &vec);
			 static void MoveDirect(Vector3 &current,Vector3 &target,float t);
			 static void MoveLerp(Vector3 &current,Vector3 &target,float t);
			 static void DotProduct(Vector3 &vec1,Vector3 &vec2);

      };
	//we can create Vector4 if nessecery
#endif