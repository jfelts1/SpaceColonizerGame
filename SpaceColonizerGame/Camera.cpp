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

Utils::Vector Camera::update() noexcept
{
	Utils::Vector ret;
	if (GET_KEYBINDS.upPressed())
	{
		ret.setY(ret.getY() - SHIFT_SPEED);
	}
	if (GET_KEYBINDS.downPressed())
	{
		ret.setY(ret.getY() + SHIFT_SPEED);
	}
	if (GET_KEYBINDS.leftPressed())
	{
		ret.setX(ret.getX() - SHIFT_SPEED);
	}
	if (GET_KEYBINDS.rightPressed())
	{
		ret.setX(ret.getX() + SHIFT_SPEED);
	}
	ret.truncate(SHIFT_SPEED);
	//std::cout << ret.getX() << "," << ret.getY() << std::endl;
	return ret;
}
