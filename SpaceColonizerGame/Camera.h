/*
James Felts 2015
*/
#ifndef CAMERA_H
#define CAMERA_H
#include <allegro5/allegro.h>
#include "Point.h"
#include "Keybinds.h"
#include "Vector.h"

#define SHIFT_SPEED 10
class Camera
{
public:
	Camera();
	virtual ~Camera();

	//returns the vector that is used to shift the world view
	Utils::Vector update();
private:
	//this is used to track the displacment of the world view
	Point m_pos;
	float m_zoomLevel;

};
#endif
