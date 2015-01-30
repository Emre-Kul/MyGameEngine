#include "Camera.h"
void Camera::setCamera(Vector3 &posV,Vector3 &eyeV,Vector3 &upV){
	position = posV;
	eye = eyeV;
	up = upV;
}
void Camera::generateViewMatrix(){


}