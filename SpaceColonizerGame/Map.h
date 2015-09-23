/*
James Felts 2015
*/
#ifndef MAP_H
#define MAP_H
#include <memory>
#include <vector>
#include "GameTile.h"
#include "Vector.h"
class Map
{
public:
	Map();
	Map(const std::vector<std::vector<GameTile>> tiles);
	//copy constructor
	Map(const Map& orig) = delete;

	//copy assignement
	Map& operator=(const Map& orig) = delete;

	//move constructor
	Map(Map&& orig)noexcept: m_tiles(std::move(orig.m_tiles))
	{}
	//move assignment
	Map& operator=(Map&& orig)
	{
		if (&orig != this)
		{
			m_tiles = std::move(orig.m_tiles);
		}
		return *this;
	}
	virtual ~Map();

	bool update() noexcept;
	void loadTextures()noexcept;
	void render(const float zoomLevel, const int screenSizeX, const int screenSizeY,const Utils::Vector2D shift)const noexcept;

	//allows the forcing of creation a copy that can only be owned by one thing
	std::unique_ptr<Map> makeUniqueCopy()const;
private:
	std::vector<std::vector<GameTile>> m_tiles;
};
#endif
