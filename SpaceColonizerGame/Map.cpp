/*
James Felts 2015
*/
#include "Map.h"

Map::Map()
{}

Map::Map(std::vector<std::vector<GameTile>> tiles)
{
	m_tiles = std::make_unique<std::vector<std::vector<GameTile>>> (tiles);
}

Map::~Map()
{
}

void Map::update(const Utils::Vector shift)
{
	for (int i = 0;i < m_tiles->size();i++)
	{
		for (int j = 0;j < m_tiles->at(i).size();j++)
		{
			m_tiles->at(i).at(j).shift(shift);
		}
	}
	std::cout <<shift.getX()<<","<<shift.getY()<<" Gametile[0][0] "<< m_tiles->at(0).at(0).getX() << "," << m_tiles->at(0).at(0).getY() << std::endl;
}

void Map::render(const float zoomLevel)const
{
	for (auto i : *m_tiles.get())
	{
		for (auto tile: i)
		{
			tile.render(zoomLevel);
		}
	}
}

std::unique_ptr<Map> Map::makeUniqueCopy()const
{
	std::vector<std::vector<GameTile>> tiles;
	for (auto i : *m_tiles.get())
	{
		std::vector<GameTile> tmp;
		for (auto tile : i)
		{
			const GameTile temp = GameTile(tile);
			tmp.push_back(temp);
		}
		tiles.push_back(tmp);
	}
	std::unique_ptr<Map> copy = std::make_unique<Map>(tiles);
	return copy;
}

