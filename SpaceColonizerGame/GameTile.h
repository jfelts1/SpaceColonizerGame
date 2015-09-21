/*
James Felts 2015
*/
#ifndef GAMETILE_H
#define GAMETILE_H
#include <string>
#include <iostream>
#include "Utils/SpriteUtils.h"
#include "Point.h"
#include "Vector.h"
#define TILE_SPRITE_SIZE 10

/*
each tile is 10 by 10
so make each texture file be 10 pixels by 10 pixels
*/

class GameTile
{
public:
	GameTile(float x = 0, float y = 0,const char* filename = "Data/Images/Tiles/RedTile.png");
	virtual ~GameTile();
	void render(const float scale)const noexcept;
	//copy constructor
	GameTile(const GameTile& orig)
	{
		m_sprite = orig.m_sprite;
		m_pos = orig.m_pos;
	}
	//copy assignment
	GameTile& operator=(const GameTile& orig)
	{
		if (this != &orig)
		{
			m_sprite = orig.m_sprite;
			m_pos = orig.m_pos;
		}
		return *this;
	}
	inline void shiftX(const float x) noexcept
	{
		m_pos.x += x;
	}
	inline void shiftY(const float y) noexcept
	{
		m_pos.y += y;
	}
	inline void shift(const Utils::Vector shift) noexcept
	{
		shiftX(shift.getX());
		shiftY(shift.getY());
		//std::cout << m_pos.x << "," << m_pos.y << std::endl;
	}
	float getX()const noexcept{ return m_pos.x; }
	float getY()const noexcept{ return m_pos.y; }
private:
	ALLEGRO_BITMAP* m_sprite;
	Point m_pos;
};
#endif
