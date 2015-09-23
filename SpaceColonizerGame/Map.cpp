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

/*void Map::shift(const Utils::Vector2D shift) noexcept
{
	for (size_t i = 0;i < m_tiles->size();i++)
	{
		size_t tmp = m_tiles->operator[](i).size();
		for (size_t j = 0;j < tmp;j++)
		{
			m_tiles->operator[](i).operator[](j).shift(shift);
		}
	}
}*/

bool Map::update() noexcept
{
	
	return false;
	//std::cout <<shift.getX()<<","<<shift.getY()<<" Gametile[0][0] "<< m_tiles->at(0).at(0).getX() << "," << m_tiles->at(0).at(0).getY() << std::endl;
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
	size_t len = m_tiles->size();
	for (size_t i = 0;i < len;i++)
	{
		size_t len2 = m_tiles->operator[](i).size();
		for (size_t j = 0;j < len2;j++)
		{
			GameTile tmp = m_tiles->operator[](i).operator[](j);
			tmp.shift(shift);
			int tileX = tmp.getX();
			int tileY = tmp.getY();

			if (tileX > 0 - padding && tileY > 0 - padding && tileX < screenSizeXScaledWithPadding && tileY < screenSizeYScaledWithPadding)
			{
				tmp.render(zoomLevel);
			}
		}
	}
	//std::cout << m_tiles->at(0).at(0) << std::endl;
}

std::unique_ptr<Map> Map::makeUniqueCopy()const
{
	std::vector<std::vector<GameTile>> tiles;
	for (size_t i = 0;i < m_tiles->size();i++)
	{
		std::vector<GameTile> tmp;
		//tmp.resize(m_tiles->at(i).size());
		for (size_t j = 0;j < m_tiles->at(i).size();j++)
		{
			tmp.emplace_back(m_tiles->at(i).at(j));
		}
		tiles.emplace_back(tmp);
	}
	std::unique_ptr<Map> copy = std::make_unique<Map>(tiles);
	return copy;
}

