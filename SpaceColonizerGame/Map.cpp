/*
James Felts 2015
*/
#include "Map.h"

Map::Map()
{}

Map::Map(const std::vector<GameTile> tiles)
{
	m_tiles = tiles;
}

Map::~Map()
{
}

bool Map::update() noexcept
{
	
	return false;
}

void Map::loadTextures() noexcept
{
	GameTile::loadTextures();
}

void Map::render(const float zoomLevel, const int screenSizeX, const int screenSizeY,const Utils::Vector2D shift)const noexcept
{
	int padding = 50;
	float screenSizeXScaledWithPadding = screenSizeX/zoomLevel + padding;
	float screenSizeYScaledWithPadding = screenSizeY/zoomLevel + padding;
	//std::cout << screenSizeXScaledWithPadding << "," << screenSizeYScaledWithPadding << std::endl;
	float x_shift = shift.getX();
	float y_shift = shift.getY();
	size_t len = m_tiles.size();
	for (size_t i = 0;i < len;i++)
	{
		//GameTile tmp = m_tiles.operator[](i);
		//m_tiles.operator[](i).shift(shift);
		int tileX = m_tiles[i].getX()+x_shift;
		int tileY = m_tiles[i].getY()+y_shift;

		if (tileX > 0 - padding && tileY > 0 - padding && tileX < screenSizeXScaledWithPadding && tileY < screenSizeYScaledWithPadding)
		{
			m_tiles[i].render(zoomLevel,tileX,tileY);
		}
	}
	//std::cout << m_tiles->at(0).at(0) << std::endl;
}

std::unique_ptr<Map> Map::makeUniqueCopy()const
{
	std::vector<GameTile> tiles;
	for (size_t i = 0;i < m_tiles.size();i++)
	{
		//tmp.resize(m_tiles->at(i).size());
		tiles.emplace_back(m_tiles.at(i));
	}
	tiles.shrink_to_fit();
	std::unique_ptr<Map> copy = std::make_unique<Map>(tiles);
	return copy;
}

