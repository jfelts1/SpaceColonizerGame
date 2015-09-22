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
	/*{
		std::vector<std::vector<GameTile>> tiles;
		for (auto i : *orig.m_tiles.get())
		{
			std::vector<GameTile> tmp;
			for (auto tile : i)
			{
				const GameTile temp = GameTile(tile);
				tmp.push_back(temp);
			}
			tiles.push_back(tmp);
		}
		m_tiles = std::make_unique<std::vector<std::vector<GameTile>>>(tiles);
	}*/
	//copy assignement
	Map& operator=(const Map& orig) = delete;
	/*{
		if (&orig != this)
		{
			std::vector<std::vector<GameTile>> tiles;
			for (auto i : *orig.m_tiles.get())
			{
				std::vector<GameTile> tmp;
				for (auto tile : i)
				{
					const GameTile temp = GameTile(tile);
					tmp.push_back(temp);
				}
				tiles.push_back(tmp);
			}
			m_tiles = std::make_unique<std::vector<std::vector<GameTile>>>(tiles);
		}
		return *this;
	}*/
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

	void update(const Utils::Vector shift) noexcept;
	void loadTextures()noexcept;
	void render(const float zoomLevel)const noexcept;

	//allows the forcing of creation a copy that can only be owned by one thing
	std::unique_ptr<Map> makeUniqueCopy()const;
private:
	std::unique_ptr<std::vector<std::vector<GameTile>>> m_tiles;
};
#endif
