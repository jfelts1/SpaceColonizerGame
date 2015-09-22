/*
James Felts 2015
*/
#ifndef POINT_H
#define POINT_H

#include <allegro5/allegro.h>
#include <iostream>
#include "Vector.h"

struct Point
{
	friend inline std::ostream& operator<<(std::ostream& out, const Point& point)
	{
		out << "(" << point.x << "," << point.y << ")";
		return out;
	}
	constexpr Point(const float x = 0, const float y = 0):x(x),y(y)
	{}

	virtual ~Point() {}

	//copy constructor
	Point(const Point& orig)
	{
		if (this != &orig)
		{
			x = orig.x;
			y = orig.y;
		}
	}

	//copy assignment
	Point& operator=(const Point& orig)
	{
		if (this != &orig)
		{
			x = orig.x;
			y = orig.y;
		}
		return *this;
	}

	//move constructor
	Point(Point&& orig) noexcept: x(orig.x), y(orig.y)
	{
		orig.x = 0;
		orig.y = 0;
	}

	//move assignment
	Point& operator=(Point&& orig)
	{
		if (this != &orig)
		{
			x = orig.x;
			y = orig.y;
			orig.x = 0;
			orig.y = 0;
		}
		return *this;
	}

	//set both the x and y component to the given number
	Point& operator=(const float val)
	{
		x = val;
		y = val;
		return *this;
	}

	Point operator+(const Utils::Vector2D rhs)
	{
		Point ret(this->x + rhs.getX(), this->y + rhs.getY());
		return ret;
	}

	/*void getCurMousePos(ALLEGRO_MOUSE_EVENT mouse)
	{
		x = mouse.x;
		y = mouse.y;
	}*/

	float x = 0;
	float y = 0;
};
#endif
