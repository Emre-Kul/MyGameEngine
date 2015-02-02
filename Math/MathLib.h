#ifndef MATHLIB_H
#define MATHLIB_H

#include <algorithm>
#include "Vectors.h"
#include "Matrix.h"

using std::swap; 
using std::max;
using std::min;

bool clipLine(float rv1,float rv2,float boxmin,float boxmax,float &ft_min,float &ft_max);
float DotProduct(Vector3 &vc1,Vector3 &vc2);
float PointDistance(Vector3 &p1,Vector3 &p2);
float Approach(float Goal,float Current,float Deltatime);
float DotProduct(Vector2 &vc1,Vector2 &vc2);
float PointDistance(Vector2 &p1,Vector2 &p2);

class MathLib{
public:
	static Matrix4x4 generateTransformMatrix(Vector3& translation,Vector3& rotation,Vector3& scale);
	static Matrix4x4 generateViewMatrix(Vector3& position,float pitch,float yaw,float roll);
	static Matrix4x4 generateProjectionMatrix(float ratio,float angle,float near,float far);
};

#endif
