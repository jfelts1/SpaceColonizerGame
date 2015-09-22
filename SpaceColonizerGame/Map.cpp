/*
James Felts 2015
*/
#include "Map.h"

Map::Map()
{}

Map::Map(const std::vector<std::vector<GameTile>> tiles)
{
	m_tiles = std::make_unique<std::vector<std::vector<GameTile>>> (tiles);
}

Map::~Map()
{
}

void Map::update(const Utils::Vector shift) noexcept
{
	for (size_t i = 0;i < m_tiles->size();i++)
	{
		for (size_t j = 0;j < m_tiles->at(i).size();j++)
		{
			m_tiles->at(i).at(j).shift(shift);
		}
	}
	//std::cout <<shift.getX()<<","<<shift.getY()<<" Gametile[0][0] "<< m_tiles->at(0).at(0).getX() << "," << m_tiles->at(0).at(0).getY() << std::endl;
}

void Map::loadTextures() noexcept
{
	for (size_t i = 0;i < m_tiles->size();i++)
	{
		for (size_t j = 0;j < m_tiles->at(i).size();j++)
		{
			m_tiles->at(i).at(j).loadTextures();
		}
	}
}

void Map::render(const float zoomLevel)const noexcept
{
	for (auto i : *m_tiles.get())
	{
		for (auto tile: i)
		{
			tile.render(zoomLevel);
		}
	}
	//std::cout << m_tiles->at(0).at(0) << std::endl;
}

std::unique_ptr<Map> Map::makeUniqueCopy()const
{
	std::vector<std::vector<GameTile>> tiles;
	for (auto i : *m_tiles.get())
	{
		std::vector<GameTile> tmp;
		for (auto tile : i)
		{
			tmp.push_back(tile);
		}
		tiles.push_back(tmp);
	}
	std::unique_ptr<Map> copy = std::make_unique<Map>(tiles);
	return copy;
}

