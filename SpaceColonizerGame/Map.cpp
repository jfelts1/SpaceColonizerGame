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

void Map::shift(const Utils::Vector2D shift) noexcept
{
	for (size_t i = 0;i < m_tiles->size();i++)
	{
		for (size_t j = 0;j < m_tiles->at(i).size();j++)
		{
			m_tiles->at(i).at(j).shift(shift);
		}
	}
}

void Map::update() noexcept
{
	
	//std::cout <<shift.getX()<<","<<shift.getY()<<" Gametile[0][0] "<< m_tiles->at(0).at(0).getX() << "," << m_tiles->at(0).at(0).getY() << std::endl;
}

void Map::loadTextures() noexcept
{
	GameTile::loadTextures();
}

void Map::render(const float zoomLevel, const int screenSizeX, const int screenSizeY)const noexcept
{
	int padding = 50;
	float screenSizeXScaledWithPadding = screenSizeX/zoomLevel + padding;
	float screenSizeYScaledWithPadding = screenSizeY/zoomLevel + padding;
	//std::cout << screenSizeXScaledWithPadding << "," << screenSizeYScaledWithPadding << std::endl;
	for (auto i : *m_tiles.get())
	{
		for (auto tile: i)
		{
			int tileX = tile.getX();
			int tileY = tile.getY();
			
			if (tileX > 0 - padding && tileY > 0 - padding && tileX < screenSizeXScaledWithPadding && tileY < screenSizeYScaledWithPadding)
			{
				tile.render(zoomLevel);
			}
		}
	}
	//std::cout << m_tiles->at(0).at(0) << std::endl;
}

std::unique_ptr<Map> Map::makeUniqueCopy()const
{
	std::vector<std::vector<GameTile>> tiles;
	//tiles.reserve(m_tiles->size()+1);
	for (auto i : *m_tiles.get())
	{
		std::vector<GameTile> tmp;
		//tmp.reserve(i.size()+1);
		for (auto tile :i)
		{
			//GameTile temp = m_tiles->at(i).at(j);
			tmp.push_back(tile);
		}
		tiles.push_back(tmp);
	}
	std::unique_ptr<Map> copy = std::make_unique<Map>(tiles);
	return copy;
}

