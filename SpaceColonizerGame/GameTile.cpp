/*
James Felts 2015
*/
#include "GameTile.h"

GameTile::GameTile(const float x, const float y,const char* filename)
{
	//m_sprite = Utils::getSprite(filename);
	m_pos = Point(x*TILE_SPRITE_SIZE, y*TILE_SPRITE_SIZE);
	m_spriteFilename = std::string(filename);
}

GameTile::~GameTile()
{
	
}

void GameTile::render(float scale)noexcept
{
	al_draw_scaled_rotated_bitmap(m_sprite, TILE_SPRITE_SIZE, TILE_SPRITE_SIZE, m_pos.x*scale, m_pos.y*scale, scale, scale, 0, 0);
}

void GameTile::loadTextures() noexcept
{
	if (m_sprite == nullptr)
	{
		m_sprite = Utils::getSprite(m_spriteFilename.c_str());
	}
}

