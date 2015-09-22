/*
James Felts 2015
*/
#ifndef GAMETILE_H
#define GAMETILE_H
#include <string>
#include <iostream>
#include <thread>
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

	friend inline std::ostream& operator<<(std::ostream& out, const GameTile& tile)
	{
		//int* tmp = (int*)tile.m_sprite;
		out << "Pos" << tile.m_pos << " spriteFile = " << tile.m_spriteFilename;
		return out;
	}
public:
	GameTile(const float x = 0, const float y = 0,std::string filename = "Data/Images/Tiles/RedTile.png");
	virtual ~GameTile();
	void render(const float scale)const noexcept;
	void loadTextures()noexcept;
	//copy constructor
	GameTile(const GameTile& orig)
	{
		m_sprite = orig.m_sprite;
		m_pos = orig.m_pos;
		m_spriteFilename = orig.m_spriteFilename;
	}
	//copy assignment
	GameTile& operator=(const GameTile& orig)
	{
		if (this != &orig)
		{
			m_sprite = orig.m_sprite;
			m_pos = orig.m_pos;
			m_spriteFilename = orig.m_spriteFilename;
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
	}
	float getX()const noexcept{ return m_pos.x; }
	float getY()const noexcept{ return m_pos.y; }
private:
	std::string m_spriteFilename;
	ALLEGRO_BITMAP* m_sprite = nullptr;
	Point m_pos;
};
#endif
