/*
James Felts 2015
*/
#ifndef GAMETILE_H
#define GAMETILE_H
#include <string>
#include <iostream>
#include <thread>
#include <bitset>
#include <cstdint>
#include "Utils/SpriteUtils.h"
#include "Point.h"
#include "Vector.h"
#define TILE_SPRITE_SIZE 10
#define TERRAIN_FLAGS_SIZE 16

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
	GameTile(const float x, const float y,const std::string filename,const std::bitset<TERRAIN_FLAGS_SIZE> terrainFlags);
	virtual ~GameTile();
	void render(const float scale)const noexcept;
	void loadTextures()noexcept;
	//copy constructor
	GameTile(const GameTile& orig)
	{
		m_sprite = orig.m_sprite;
		m_pos = orig.m_pos;
		m_spriteFilename = orig.m_spriteFilename;
		m_terrainFlags = orig.m_terrainFlags;
	}
	//copy assignment
	GameTile& operator=(const GameTile& orig)
	{
		if (this != &orig)
		{
			m_sprite = orig.m_sprite;
			m_pos = orig.m_pos;
			m_spriteFilename = orig.m_spriteFilename;
			m_terrainFlags = orig.m_terrainFlags;
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
	inline void shift(const Utils::Vector2D shift) noexcept
	{
		shiftX(shift.getX());
		shiftY(shift.getY());
	}
	float getX()const noexcept{ return m_pos.x; }
	float getY()const noexcept{ return m_pos.y; }

	bool isWater()const noexcept { return m_terrainFlags[0]; }
	bool isUnbuildableTerrain()const noexcept { return m_terrainFlags[1]; }
	bool isRoughTerrain()const noexcept { return m_terrainFlags[2]; }
	bool isMildTerrain()const noexcept { return m_terrainFlags[3]; }
private:
	std::string m_spriteFilename;
	ALLEGRO_BITMAP* m_sprite = nullptr;
	Point m_pos;
	//bit position format right to left
	// 0 = water
	// 1 = unbuildable terrain
	// 2 = rough terrain
	// 3 = mild terrain
	std::bitset<TERRAIN_FLAGS_SIZE> m_terrainFlags;
};
#endif
