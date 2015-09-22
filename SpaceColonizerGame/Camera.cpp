/*
James Felts 2015
*/
#include "Camera.h"

Camera::Camera()
{

}

Camera::~Camera() noexcept
{
}


void Camera::update() noexcept
{
	updateCameraShift();
	updateZoomLevel();
}
