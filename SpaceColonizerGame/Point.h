/*
James Felts 2015
*/
#ifndef POINT_H
#define POINT_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <allegro5/allegro.h>
#include <iostream>
#include <type_traits>
#include "Vector.h"

template<typename T>
struct Point
{
	static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value,"T must be a numeric type");
	friend std::ostream& operator<<(std::ostream& out, const Point& point)
	{
		out << "(" << point.x << "," << point.y << ")";
		return out;
	}

	explicit constexpr Point(const T x = 0, const T y = 0) :x(x), y(y)
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
	Point& operator=(const T val)
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

	T x = 0;
	T y = 0;
};
#endif
