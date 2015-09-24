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

void Map::render(const float zoomLevel, const int screenSizeX, const int screenSizeY,const Utils::Vector2D shift) const noexcept
{
	int padding = 50;
	float screenSizeXScaledWithPadding = screenSizeX/zoomLevel + padding;
	float screenSizeYScaledWithPadding = screenSizeY/zoomLevel + padding;
	//std::cout << screenSizeXScaledWithPadding << "," << screenSizeYScaledWithPadding << std::endl;
	float x_shift = shift.getX();
	float y_shift = shift.getY();

	for (auto& tile: m_tiles)
	{
		int tileX = tile.getX()+x_shift;
		int tileY = tile.getY()+y_shift;

		if (tileX > 0 - padding && tileY > 0 - padding && tileX < screenSizeXScaledWithPadding && tileY < screenSizeYScaledWithPadding)
		{
			tile.render(zoomLevel,tileX,tileY);
		}
	}
}

std::unique_ptr<Map> Map::makeUniqueCopy() const
{
	std::vector<GameTile> tiles;

	for (auto& tile:m_tiles)
	{
		tiles.emplace_back(tile);
	}
	tiles.shrink_to_fit();
	std::unique_ptr<Map> copy = std::make_unique<Map>(tiles);
	return copy;
}

