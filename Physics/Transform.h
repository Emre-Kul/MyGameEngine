#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Math/Vectors.h"
#include "../Math/Matrix.h"
#include "../Math/MathLib.h"

class Transform{
	public:
	Vector3 position,scale,rotation;		
	void rotate(Vector3 &vec);
			//inlines
	inline Matrix4x4 getTransformMatrix(){return MathLib::generateTransformMatrix(position,rotation,scale);}

};

#endif