#include "Camera.h"
void Camera::setCamera(Vector3 &pos,float yaw,float pitch,float roll){
	position = pos;
	cyaw = yaw;
	cpitch = pitch;
	croll = roll;
	generateViewMatrix();
}
