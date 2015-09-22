/*
James Felts 2015
*/
#ifndef CAMERA_H
#define CAMERA_H
#include <allegro5/allegro.h>
#include "Point.h"
#include "Keybinds.h"
#include "Vector.h"
#include "Mousebinds.h"

#define SHIFT_SPEED 10
#define ZOOM_SPEED 0.125
#define MAX_ZOOM 3.0f
#define MIN_ZOOM 0.25f
class Camera
{
public:
	Camera();
	virtual ~Camera() noexcept;
	float getZoomLevel()const noexcept { return m_zoomLevel; }
	Utils::Vector getCameraShift() const noexcept { return m_cameraShift; }

	//returns the vector that is used to shift the world view
	void update() noexcept;
private:
	//this is used to track the displacment of the world view
	Utils::Vector m_cameraShift;
	float m_zoomLevel = 1;

	inline void updateCameraShift()noexcept
	{
		//m_cameraShift.setX(0);
		//m_cameraShift.setY(0);
		Utils::Vector curShift;
		if (GET_KEYBINDS.upPressed())
		{
			curShift.setY(curShift.getY() - SHIFT_SPEED);
		}
		if (GET_KEYBINDS.downPressed())
		{
			curShift.setY(curShift.getY() + SHIFT_SPEED);
		}
		if (GET_KEYBINDS.leftPressed())
		{
			curShift.setX(curShift.getX() - SHIFT_SPEED);
		}
		if (GET_KEYBINDS.rightPressed())
		{
			curShift.setX(curShift.getX() + SHIFT_SPEED);
		}
		curShift.truncate(SHIFT_SPEED);
		m_cameraShift += curShift;
		std::cout << "curShift"<<curShift <<" camShift"<<m_cameraShift<< std::endl;

	}

	inline void updateZoomLevel() noexcept
	{
		if (GET_MOUSEBINDS.scrolledDown() && m_zoomLevel > MIN_ZOOM)
		{
			m_zoomLevel -= ZOOM_SPEED;
		}
		if (GET_MOUSEBINDS.scrolledUp() && m_zoomLevel < MAX_ZOOM)
		{
			m_zoomLevel += ZOOM_SPEED;
		}
	}

};
#endif
